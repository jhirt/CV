#include "PostGreDbManager.h"

#include <iostream>

namespace Framework
{
	PostGreDbManager PostGreDbManager::m_instance = PostGreDbManager();

	PostGreDbManager::PostGreDbManager()
	{
		Connection();
	}

	PostGreDbManager& PostGreDbManager::getInstance()
	{
		return PostGreDbManager::m_instance;
	}

	bool PostGreDbManager::Connection()
	{
		const char* conninfo = "user=postgres password=300601yd dbname=CVdb";
		m_conn = PQconnectdb(conninfo);

		ConnStatusType connStatus = PQstatus(m_conn);
		if (connStatus != CONNECTION_OK)
		{
			switch (connStatus)
			{
			case CONNECTION_BAD:
				std::cout << "Couldn't establish connection to database, check identifiers and database state";
			}
			return false;
		}

		return true;
	}

	bool PostGreDbManager::WriteContext(Context& context)
	{
		// Verify if such a context already exist in db
		
		const char* paramValues[2];
		paramValues[0] = context.guid();
		paramValues[1] = context.prop();

		PGresult* queryRes = PQexecParams(
			m_conn,
			"SELECT * FROM \"Context\" WHERE \"GUID\" = $1 AND \"Property\" = $2",
			2,       // one param
			NULL,    // let the backend deduce param type
			paramValues,
			NULL,    // don't need param lengths since text
			NULL,    // default to all text params
			1);      // ask for binary results

		ExecStatusType queryStatus = PQresultStatus(queryRes); 
		if (queryStatus != PGRES_COMMAND_OK && queryStatus != PGRES_TUPLES_OK)
		{
			std::cout << "Couldn't read context table";
			return false;
		}

		char* rC = PQcmdTuples(queryRes);
		int rowsCount = atoi(rC);
		if (rowsCount > 1)
		{
			std::cout << "Critical error, more than 1 context found for a guid and property";
			return false;
		}
		
		/*
		"IF EXISTS(SELECT * FROM \"Context\" WHERE \"GUID\" = $2 AND \"Property\" = $3)"
			"BEGIN"
				"UPDATE \"Context\" SET \"Value\" = $4  WHERE \"GUID\" = $2 AND \"Property\" = $3"
			"END"
		"ELSE"
			"BEGIN"
				"INSERT INTO \"Context\" (\"Controller\", \"GUID\", \"Property\", \"Value\") VALUES ($1, $2, $3, $4)"
			"END";
		*/

		if (rowsCount == 1)
		{
			// If such a context already exist, update it
			const char* paramValues[3];
			paramValues[0] = context.guid();
			paramValues[1] = context.prop();
			paramValues[2] = context.value();

			PGresult* queryRes = PQexecParams(
				m_conn,
				"UPDATE \"Context\" SET \"Value\" = $3  WHERE \"GUID\" = $1 AND \"Property\" = $2",
				3,       // one param 
				NULL,    // let the backend deduce param type
				paramValues,
				NULL,    // don't need param lengths since text 
				NULL,    // default to all text params
				1);      // ask for binary results

			ExecStatusType queryStatus = PQresultStatus(queryRes);
			if (queryStatus != PGRES_COMMAND_OK && queryStatus != PGRES_TUPLES_OK)
			{
				std::cout << "Couldn't read context table";
				return false;
			}
		}
		else
		{
			// It such a context doesn't exist yet, create it by inserting a new row
			const char* paramValues[4];
			paramValues[0] = context.controller();
			paramValues[1] = context.guid();
			paramValues[2] = context.prop();
			paramValues[3] = context.value();

			PGresult* queryRes = PQexecParams(
				m_conn,
				"INSERT INTO \"Context\" (\"Controller\", \"GUID\", \"Property\", \"Value\") VALUES ($1, $2, $3, $4)",
				4,       // one param 
				NULL,    // let the backend deduce param type
				paramValues,
				NULL,    // don't need param lengths since text 
				NULL,    // default to all text params
				1);      // ask for binary results

			ExecStatusType queryStatus = PQresultStatus(queryRes);
			if (queryStatus != PGRES_COMMAND_OK && queryStatus != PGRES_TUPLES_OK)
			{
				std::cout << "Couldn't read context table";
				return false;
			}
		}

		return true;
	}

	bool PostGreDbManager::ReadAllContexts(QList<Context>& contextList)
	{
		PGresult* queryRes = PQexecParams(
			m_conn,
			"SELECT * FROM \"Context\"",
			0,       // one param
			NULL,    // let the backend deduce param type
			NULL,
			NULL,    // don't need param lengths since text
			NULL,    // default to all text params
			1);      // ask for binary results

		ExecStatusType queryStatus = PQresultStatus(queryRes);

		if (queryStatus != PGRES_COMMAND_OK && queryStatus != PGRES_TUPLES_OK)
		{
			std::cout << "Couldn't read context table";
			return false;
		}

		char* rC = PQcmdTuples(queryRes);
		int rowsCount = atoi(rC);

		for (int i = 0; i < rowsCount; i++)
		{
			contextList[i].setController(PQgetvalue(queryRes, i, 0));
			contextList[i].setGuid(PQgetvalue(queryRes, i, 1));
			contextList[i].setProp(PQgetvalue(queryRes, i, 2));
			contextList[i].setValue(PQgetvalue(queryRes, i, 3));
		}

		return true;
	}
} 