#include "CentralManager.h"

using namespace QtCharts;

namespace App
{
	CentralManager::CentralManager()
	{
		m_lineSerie = new QLineSeries();
		m_chart = new QChart();
		m_chart->addSeries(m_lineSerie);
		m_chart->setTitle("");
		m_chart->setAnimationOptions(QChart::SeriesAnimations);
		m_chart->createDefaultAxes();
		m_chart->hide();
	}

	bool CentralManager::ChangeFunction(QString fileName)
	{
		// Read function on hard drive
		try
		{
			m_functionManager.Read(fileName);
		}
		catch (QString e)
		{
			return false;
		}

		// Update chart
		m_chart->setTitle(fileName.mid(fileName.lastIndexOf("/")+1,-1));
		m_lineSerie->clear();
		for (int i = 0; i < m_functionManager.F().size(); i++)
			*m_lineSerie << m_functionManager.F()[i];

		m_chart->axisX()->setRange(m_functionManager.F().xMin(), m_functionManager.F().xMax());
		m_chart->axisY()->setRange(m_functionManager.F().yMin(), m_functionManager.F().yMax());
		m_chart->show();

		return true;
	}
}