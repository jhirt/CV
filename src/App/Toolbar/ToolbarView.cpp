#include "ToolbarView.h"

#include "ToolbarController.h"
#include "..\MainViewer.h"

namespace App
{
	ToolbarView::ToolbarView(ToolbarController* toolbarController, MainViewer* mainViewer) : Viewer(), m_toolbarController(toolbarController), QToolBar(mainViewer)
	{

	}
}