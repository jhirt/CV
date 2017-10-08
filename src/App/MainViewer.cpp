#include "MainViewer.h"

#include <QDockWidget>
#include <QPushButton>
#include <QHBoxLayout>

namespace App
{
	MainViewer::MainViewer() : Viewer(),QMainWindow()
	{
		this->resize(1280, 640);

		/*
		QDockWidget* dock = new QDockWidget();
		QWidget* m_container = new QWidget(this);
		QHBoxLayout* m_layout = new QHBoxLayout();

		QPushButton* m_changeFunctionColorButton = new QPushButton();
		m_layout->addWidget(m_changeFunctionColorButton);

		m_container->setLayout(m_layout);
		dock->setWidget(m_container);
		this->addDockWidget(Qt::TopDockWidgetArea, dock);
		*/
		show();
	}
}
