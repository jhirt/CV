#include "DockView.h"

#include "DockController.h"
#include "..\MainViewer.h"

namespace App
{
	DockView::DockView(DockController* dockController, MainViewer* mainViewer) : Viewer(), m_dockController(dockController), QDockWidget(mainViewer)
	{

	}
}