#ifndef MAIN_VIEWER
#define MAIN_VIEWER

#include "..\Framework\Viewer\Viewer.h"
#include <QtWidgets\QMainWindow>

using namespace Framework;

namespace App
{
	class MainViewer : public Viewer, public QMainWindow
	{
	public:
		MainViewer();

	protected:
	};
}
#endif //MAIN_VIEWER
