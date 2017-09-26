#include "MainViewer.h"

namespace App
{
	MainViewer::MainViewer() : Viewer(),QMainWindow()
	{
		this->resize(1280, 640);
		show();
	}
}
