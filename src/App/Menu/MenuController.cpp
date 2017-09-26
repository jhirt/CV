#include "MenuController.h"

#include "..\MainController.h"
#include "..\MainViewer.h"
#include "MenuView.h"

#include <QXmlStreamWriter>

namespace App
{
	MenuController::MenuController(MainController* mainController, MainViewer* mainViewer) : Controller(), mainController(mainController)
	{
		m_menuView = new MenuView(this, mainViewer);

		connect(m_menuView, SIGNAL(ViewerMenuOpenFileTriggered(QString)), this, SLOT(ViewerMenuOpenFileTriggered(QString)));
	}

	void MenuController::ViewerMenuOpenFileTriggered(QString fileName)
	{
		// emit contextChanged event indicating new data filename
		QString contextChange;
		QXmlStreamWriter writer(&contextChange);
		writer.writeStartDocument();
			writer.writeStartElement("Data");
				writer.writeTextElement("FileName", fileName);
			writer.writeEndElement(); // Data
		writer.writeEndDocument();

		mainController->Context_Change(contextChange);
	}
}