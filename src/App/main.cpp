
#include <QtWidgets\QApplication>
/*
#include <QtWidgets\QMainWindow>
#include <QtWidgets\QToolBar>
#include <QtWidgets\QDockWidget>
#include <QtWidgets\QMenu>
#include <QtWidgets\QMenuBar>
*/

#include "MainController.h"

using namespace App;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	MainController* mainController = new MainController();

	/*
	QMainWindow* mainWindow = new QMainWindow();

	QToolBar* toolbar = new QToolBar(mainWindow);

	QToolBar* dock = new QToolBar(mainWindow);

	QMenu *menuFichier = mainWindow->menuBar()->addMenu("&File");

	mainWindow->show();
	*/

	return app.exec();
}
