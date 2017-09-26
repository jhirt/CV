#ifndef CHART_VIEW
#define CHART_VIEW

#include <QtCharts>

namespace QtCharts
{
	class QChartView;
}

namespace Framework
{
	class ChartView : public QChartView
	{
	public:
		ChartView(QWidget *parent);

	protected:
		virtual void wheelEvent(QWheelEvent *event); 
	};
}
#endif //CHART_VIEW
