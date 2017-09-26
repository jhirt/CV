TEMPLATE = app
TARGET = CV

VER_MAJ = 1
VER_MIN = 0
VER_PATCH = 0

LANGUAGE  = C++

QT_VERSION = 5.8

QT += gui core widgets xml charts

CONFIG -= flat

DEPENDPATH += .


HEADERS += .\src\Framework\Controller\Controller.h
HEADERS += .\src\Framework\Entity\Context.h
HEADERS += .\src\Framework\Entity\Function2D.h
HEADERS += .\src\Framework\Manager\ContextManager.h
HEADERS += .\src\Framework\Manager\ContextManagerXml.h
HEADERS += .\src\Framework\Manager\Function2DManager.h
HEADERS += .\src\Framework\Manager\Function2DManagerCsv.h
HEADERS += .\src\Framework\Manager\Manager.h
HEADERS += .\src\Framework\Viewer\Viewer.h

HEADERS += .\src\App\MainController.h
HEADERS += .\src\App\MainViewer.h
HEADERS += .\src\App\Central\CentralContext.h
HEADERS += .\src\App\Central\CentralController.h
HEADERS += .\src\App\Central\CentralManager.h
HEADERS += .\src\App\Central\CentralView.h
HEADERS += .\src\App\Dock\DockContext.h
HEADERS += .\src\App\Dock\DockController.h
HEADERS += .\src\App\Dock\DockView.h
HEADERS += .\src\App\Menu\MenuController.h
HEADERS += .\src\App\Menu\MenuView.h
HEADERS += .\src\App\Toolbar\ToolbarContext.h
HEADERS += .\src\App\Toolbar\ToolbarController.h
HEADERS += .\src\App\Toolbar\ToolbarView.h

SOURCES += .\src\Framework\Controller\Controller.cpp
SOURCES += .\src\Framework\Entity\Context.cpp
SOURCES += .\src\Framework\Entity\Function2D.cpp
SOURCES += .\src\Framework\Manager\ContextManager.cpp
SOURCES += .\src\Framework\Manager\ContextManagerXml.cpp
SOURCES += .\src\Framework\Manager\Function2DManager.cpp
SOURCES += .\src\Framework\Manager\Function2DManagerCsv.cpp
SOURCES += .\src\Framework\Manager\Manager.cpp
SOURCES += .\src\Framework\Viewer\Viewer.cpp

SOURCES += .\src\App\main.cpp
SOURCES += .\src\App\MainController.cpp
SOURCES += .\src\App\MainViewer.cpp
SOURCES += .\src\App\Central\CentralContext.cpp
SOURCES += .\src\App\Central\CentralController.cpp
SOURCES += .\src\App\Central\CentralManager.cpp
SOURCES += .\src\App\Central\CentralView.cpp
SOURCES += .\src\App\Dock\DockContext.cpp
SOURCES += .\src\App\Dock\DockController.cpp
SOURCES += .\src\App\Dock\DockView.cpp
SOURCES += .\src\App\Menu\MenuController.cpp
SOURCES += .\src\App\Menu\MenuView.cpp
SOURCES += .\src\App\Toolbar\ToolbarContext.cpp
SOURCES += .\src\App\Toolbar\ToolbarController.cpp
SOURCES += .\src\App\Toolbar\ToolbarView.cpp

RESOURCES += CV.qrc

win32-msvc2015 {

  CONFIG(debug, debug|release) {

	build_pass:message("---------------------------------------------------------")
	build_pass:message("$${TARGET} (debug) with Qt $${QT_VERSION} and MSVC 2013")
	build_pass:message("---------------------------------------------------------")
	  
    MOC_DIR     += ./x64/debug/
    RCC_DIR     += ./x64/debug/
    UI_DIR      += ./x64/debug/
    OBJECTS_DIR += ./x64/debug/
    INCLUDEPATH += ./x64/debug/

    DESTDIR = ./x64/debug/
  }
  else {
    
	build_pass:message("---------------------------------------------------------")
	build_pass:message("$${TARGET} (release) with Qt $${QT_VERSION} and MSVC 2013")
	build_pass:message("---------------------------------------------------------")
	
    MOC_DIR     += ./x64/release/
    RCC_DIR     += ./x64/release/
    UI_DIR      += ./x64/release/
    OBJECTS_DIR += ./x64/release/
    INCLUDEPATH += ./x64/release/

    DESTDIR = ./x64/release/
  } 
}
