#include "MenuView.h"

#include "..\MainViewer.h"
#include "MenuController.h"

namespace App
{
	MenuView::MenuView(MenuController* menuController, MainViewer* mainViewer) : Viewer(), menuController(menuController)
	{
		m_fileMmenu = mainViewer->menuBar()->addMenu("&File");

		m_openAction = new QAction("Open", m_fileMmenu);
		m_fileMmenu->addAction(m_openAction);
		connect(m_openAction, SIGNAL(triggered(bool)), this, SLOT(MenuOpenFileClicked(bool)));
	}

	void MenuView::MenuOpenFileClicked(bool checked)
	{
		QString fileName = QFileDialog::getOpenFileName(m_fileMmenu, "Open new function");
		emit ViewerMenuOpenFileTriggered(fileName);
	}
}