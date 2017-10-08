#include "ChartView.h"
#include <QtGui/QMouseEvent>

namespace Framework
{
	ChartView::ChartView(QWidget *parent) : QChartView(parent)
	{

	}

	void ChartView::wheelEvent(QWheelEvent *event)
	{
		if (event->delta() > 0)
			chart()->zoomIn();
		else
			chart()->zoomOut();

		event->accept();
	}
}