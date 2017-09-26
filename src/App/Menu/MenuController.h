#ifndef MENU_CONTROLLER
#define MENU_CONTROLLER

#include "..\..\Framework\Controller\Controller.h"

#include <QObject>

using namespace Framework;

namespace App
{
	class MainController;
	class MainViewer;
	class MenuView;

	class MenuController : public QObject, public Controller
	{
		Q_OBJECT;

	public:
		MenuController(MainController* mainController, MainViewer* mainViewer);

	protected:
		MainController* mainController;
		MenuView* m_menuView;

	public slots:
		void ViewerMenuOpenFileTriggered(QString fileName);
		
	};
}
#endif //MENU_CONTROLLER