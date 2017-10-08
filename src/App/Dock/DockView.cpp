#include "DockView.h"

#include "DockController.h"
#include "..\MainViewer.h"

#include <QDockWidget>
#include <QPushButton>
#include <QHBoxLayout>

namespace App
{
	DockView::DockView(DockController* dockController, MainViewer* mainViewer) : Viewer(), m_dockController(dockController) //, QDockWidget(mainViewer)
	{
		m_topDockWidget = new QDockWidget(mainViewer);
		m_container = new QWidget(m_topDockWidget);
		m_layout = new QHBoxLayout();

		m_changeFunctionColorButton = new QPushButton();
		m_changeFunctionColorButton->setMaximumSize(QSize(30, 30));
		m_layout->addWidget(m_changeFunctionColorButton);

		m_container->setLayout(m_layout);
		m_topDockWidget->setWidget(m_container);
		QWidget* titleWidget = new QWidget(mainViewer);
		m_topDockWidget->setTitleBarWidget(titleWidget);
		mainViewer->addDockWidget(Qt::TopDockWidgetArea, m_topDockWidget);
		//this->setVisible(true);
	}
}