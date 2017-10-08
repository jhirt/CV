#ifndef POST_GRE_DB_MANAGER
#define POST_GRE_DB_MANAGER

#include "DbManager.h"
#include "../Entity/Context.h"

#include <QList>

#include <libpq-fe.h>
//class PGconn;

namespace Framework
{
	class PostGreDbManager : public DbManager
	{
	public:
		static PostGreDbManager& getInstance();

		bool WriteContext(Context& context);
		bool ReadAllContexts(QList<Context>& contextList);

	private:
		PostGreDbManager& operator= (const PostGreDbManager&) {}
		PostGreDbManager(const PostGreDbManager&) {}

		PostGreDbManager();
		~PostGreDbManager() {};

		virtual bool Connection();

	private:
		static PostGreDbManager m_instance;
		PGconn* m_conn;
	};
}
#endif //POST_GRE_DB_MANAGER