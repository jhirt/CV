#include "CentralController.h"

#include "..\MainController.h"
#include "..\MainViewer.h"
#include "CentralView.h"
#include "CentralManager.h"

#include "../../Framework/Entity/Context.h"
#include "../../Framework/Manager/PostGreDbManager.h"

#include <QXmlStreamReader>
#include <QString>

namespace App
{
	CentralController::CentralController(MainController* mainController, MainViewer* mainViewer) : Controller(), m_mainController(mainController)
	{
		m_centralManager = new CentralManager();
		m_centralView = new CentralView(this, m_centralManager, mainViewer);
	}

	void CentralController::ChangeFunction(QString fileName)
	{
		 bool ok = m_centralManager->ChangeFunction(fileName);
		 
		 // Save context change in db
		 char controller[30] = "CentralController";
		 char guid[128] = "4ce0f275-d035-4fe3-acae-ba75a8edd98e";
		 char prop[30] = "Function";
		 char value[256];
		 sprintf(value,fileName.toLatin1().data());
		 Context currentFunctionContext(controller, guid, prop, value);

		 PostGreDbManager& dbManager = PostGreDbManager::getInstance();
		 dbManager.WriteContext(currentFunctionContext);
	}


	////////// SLOTS

	void CentralController::ContextChange(QString contextChanged)
	{
		QString fileName;

		QXmlStreamReader reader(contextChanged);
		while (reader.readNextStartElement())
		{
			if (reader.name() == "Data")
			{
				while (reader.readNextStartElement())
				{
					if (reader.name() == "FileName")
					{
						fileName = reader.readElementText();
						ChangeFunction(fileName);
					}
					else
						reader.skipCurrentElement();
				}
			}
			else
				reader.skipCurrentElement();
		}
	}
}