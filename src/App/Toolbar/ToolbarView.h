#ifndef TOOLBAR_VIEW
#define TOOLBAR_VIEW

#include "..\..\Framework\Viewer\Viewer.h"

#include <QObject>
#include <QtWidgets\QToolBar>

using namespace Framework;

namespace App
{
	class ToolbarController;
	class MainViewer;

	class ToolbarView : public QObject, Viewer, QToolBar
	{
		Q_OBJECT;

	public:
		ToolbarView(ToolbarController* toolbarController, MainViewer* mainViewer);

	protected:
		ToolbarController* m_toolbarController;
	};
}
#endif //TOOLBAR_VIEW
