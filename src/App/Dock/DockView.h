#ifndef DOCK_VIEW
#define DOCK_VIEW

#include "..\..\Framework\Viewer\Viewer.h"

#include <QObject>
//#include <QtWidgets\QDockWidget>

using namespace Framework;

class QDockWidget;
class QPushButton;
class QHBoxLayout;

namespace App
{
	class DockController;
	class MainViewer;

	class DockView : public QObject, Viewer //, QDockWidget
	{
		Q_OBJECT;

	public:
		DockView(DockController* dockController, MainViewer* mainViewer);

	protected:
		DockController* m_dockController;
		QDockWidget* m_topDockWidget;
		QWidget* m_container;
		QHBoxLayout* m_layout;
		QPushButton* m_changeFunctionColorButton;
	};
}
#endif //DOCK_VIEW
