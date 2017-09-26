#ifndef CENTRAL_CONTROLLER
#define CENTRAL_CONTROLLER

#include "..\..\Framework\Controller\Controller.h"

using namespace Framework;

#include <QObject>

namespace App
{
	class MainController;
	class CentralManager;
	class CentralView;
	class MainViewer;

	class CentralController : public QObject, Controller
	{
		Q_OBJECT;

	public:
		CentralController(MainController* mainController, MainViewer* mainViewer);

	protected:
		MainController* m_mainController;
		CentralManager* m_centralManager;
		CentralView* m_centralView;

		void ChangeFunction(QString fileName);

	public slots:
		void ContextChange(QString contextChanged);
	};
}
#endif //CENTRAL_CONTROLLER
