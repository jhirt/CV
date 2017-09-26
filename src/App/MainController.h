#ifndef MAIN_CONTROLLER
#define MAIN_CONTROLLER

#include "..\Framework\Controller\Controller.h"

#include <QObject>

using namespace Framework;

namespace App
{
	class CentralController;
	class DockController;
	class MenuController;
	class ToolbarController;
	class MainViewer;

	class MainController : public QObject, public Controller
	{
		Q_OBJECT;

	public:
		MainController();

		void Context_Change(QString contextChange);

	protected:
		CentralController* m_centralController;
		DockController* m_dockController;
		MenuController* m_menuController;
		ToolbarController* m_toolbarController;

		MainViewer* m_mainViewer;

	signals:
		void ContextChange(QString contextChange);
	};
}
#endif //MAIN_CONTROLLER
