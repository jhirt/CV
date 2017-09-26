#ifndef DOCK_CONTROLLER
#define DOCK_CONTROLLER

#include "..\..\Framework\Controller\Controller.h"

#include <QObject>

using namespace Framework;

namespace App
{
	class MainController;
	class MainViewer;
	class DockView;

	class DockController : public QObject, public Controller
	{
		Q_OBJECT;

	public:
		DockController(MainController* mainController, MainViewer* mainViewer);

	protected:
		MainController* m_mainController;

		DockView* m_dockView;
	};
}
#endif //DOCK_CONTROLLER
