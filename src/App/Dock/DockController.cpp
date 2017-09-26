#include "DockController.h"

#include "..\MainController.h"
#include "..\MainViewer.h"
#include "DockView.h"

namespace App
{
	DockController::DockController(MainController* mainController, MainViewer* mainViewer) : Controller(), m_mainController(mainController)
	{
		m_dockView = new DockView(this, mainViewer);
	}
}