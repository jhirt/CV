#ifndef TOOLBAR_CONTROLLER
#define TOOLBAR_CONTROLLER

#include "..\..\Framework\Controller\Controller.h"

#include <QObject>

using namespace Framework;

namespace App
{
	class MainController;
	class MainViewer;
	class ToolbarView;

	class ToolbarController : public QObject, Controller
	{
		Q_OBJECT;

	public:
		ToolbarController(MainController* mainController, MainViewer* mainViewer);

	protected:
		MainController* m_mainController;
		ToolbarView* m_toolbarView;
	};
}
#endif //TOOLBAR_CONTROLLER