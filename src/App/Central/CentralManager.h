#ifndef CENTRAL_MANAGER
#define CENTRAL_MANAGER

#include "..\..\Framework\Manager\Manager.h"
#include "..\..\Framework\Manager\Function2DManagerCsv.h"

#include <QObject>
#include <QtCharts>

using namespace Framework;
using namespace QtCharts;

namespace App
{
	class CentralManager : public QObject, Manager
	{
		Q_OBJECT;

	public:
		CentralManager();

		bool ChangeFunction(QString fileName);
		QChart* Chart() { return m_chart; }

	protected:
		Function2DManagerCsv m_functionManager;
		QLineSeries* m_lineSerie;
		QChart* m_chart;
	};
}
#endif //CENTRAL_MANAGER
