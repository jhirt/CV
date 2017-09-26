#include "CentralController.h"

#include "..\MainController.h"
#include "..\MainViewer.h"
#include "CentralView.h"
#include "CentralManager.h"

#include <QXmlStreamReader>

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