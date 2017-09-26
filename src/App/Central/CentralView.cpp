#include "CentralView.h"

#include "..\..\Framework\Entity\ChartView.h"

#include "CentralController.h"
#include "CentralManager.h"
#include "..\MainViewer.h"

using namespace QtCharts;

namespace App
{
	CentralView::CentralView(CentralController* centralController, CentralManager* centralManager, MainViewer* mainViewer) : m_centralController(centralController), m_centralManager(centralManager)
	{
		m_centralWidget = new QWidget();
		mainViewer->setCentralWidget(m_centralWidget);

		m_verticalLayout = new QVBoxLayout();
		
		m_chartView = new ChartView(m_centralWidget);
		m_chartView->setChart(m_centralManager->Chart());
		m_chartView->setRenderHint(QPainter::Antialiasing);
		m_chartView->resize(800, 600);
		m_chartView->show();
		m_verticalLayout->addWidget(m_chartView);

		m_centralWidget->setLayout(m_verticalLayout);
	}
}