#ifndef MENU_VIEW
#define MENU_VIEW

#include "..\..\Framework\Viewer\Viewer.h"

#include <QtWidgets\QMenuBar>
#include <QtWidgets\QMenu>
#include <QtWidgets\QAction>
#include <QtWidgets\QFileDialog>

using namespace Framework;

namespace App
{
	class MenuController;
	class MainViewer;

	class MenuView : public QObject, public Viewer
	{
		Q_OBJECT;

	public:
		MenuView(MenuController* menuController, MainViewer* mainViewer);

	protected:
		MenuController* menuController;

		QMenu*	m_fileMmenu;
		QAction* m_openAction;

	public slots:
		void MenuOpenFileClicked(bool checked);

	signals:
		void ViewerMenuOpenFileTriggered(QString fileName);
	};
}
#endif //MENU_VIEW
