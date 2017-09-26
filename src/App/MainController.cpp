#include "MainController.h"

#include "Central\CentralController.h"
#include "Dock\DockController.h"
#include "Menu\MenuController.h"
#include "Toolbar\ToolbarController.h"
#include "MainViewer.h"

namespace App
{
	MainController::MainController()
	{
		m_mainViewer = new MainViewer();

		m_menuController = new MenuController(this, m_mainViewer);
		connect(this, SIGNAL(ContextChange(QString)), m_menuController, SLOT(ContextChange(QString)));

		m_toolbarController = new ToolbarController(this, m_mainViewer);
		connect(this, SIGNAL(ContextChange(QString)), m_toolbarController, SLOT(ContextChange(QString)));

		m_dockController = new DockController(this, m_mainViewer);
		connect(this, SIGNAL(ContextChange(QString)), m_dockController, SLOT(ContextChange(QString)));

		m_centralController = new CentralController(this, m_mainViewer);
		connect(this, SIGNAL(ContextChange(QString)), m_centralController, SLOT(ContextChange(QString)));
	}

	void MainController::Context_Change(QString contextChange)
	{
		// Analyze

		// Sending to child controllers
		emit ContextChange(contextChange);
	}
}
