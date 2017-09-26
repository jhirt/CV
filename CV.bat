@echo OFF

set CC=MSVC15

set QMAKESPEC=win32-msvc2015

set "PATH=D:\Qt\5.8\msvc2015_64\bin;%PATH%"
set QTDIR=D:\Qt\5.8\msvc2015_64

echo -------------------------------------------------
echo QTDIR: %QTDIR%
echo -------------------------------------------------

echo -------------------------------------------------
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x86_amd64
echo -------------------------------------------------

if exist CV.vcxproj (  
  del /F /Q  CV.vcxproj
)

%QTDIR%\bin\qmake -tp vc -o CV.vcxproj CV.pro

:finish
pause

