#ifndef CENTRAL_VIEW
#define CENTRAL_VIEW

#include "..\..\Framework\Viewer\Viewer.h"

#include <QObject>
#include <QBoxLayout>

using namespace Framework;

namespace Framework
{
	class ChartView;
}

namespace App
{
	class CentralController;
	class CentralManager;
	class MainViewer;

	class CentralView : public QObject, public Viewer
	{
		Q_OBJECT;

	public:
		CentralView(CentralController* centralController, CentralManager* centralManager, MainViewer* mainViewer);

	protected:
		CentralController* m_centralController;
		CentralManager* m_centralManager;

		QWidget* m_centralWidget;
		QVBoxLayout* m_verticalLayout;
		ChartView* m_chartView;
	};
}
#endif //CENTRAL_VIEW
