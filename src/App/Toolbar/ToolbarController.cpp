#include "ToolbarController.h"

#include "..\MainController.h"
#include "..\MainViewer.h"
#include "ToolbarView.h"

namespace App
{
	ToolbarController::ToolbarController(MainController* mainController, MainViewer* mainViewer) : Controller(), m_mainController(mainController)
	{
		m_toolbarView = new ToolbarView(this, mainViewer);
	}
}