@echo off 
setlocal  

set "PROJECT_NAME=Converter.exe"
set "BUILD_DIRECTORY=%~dp0build"
set "QT_BIN=C:/Qt/6.9.1/mingw_64/bin"

echo [Step 1 of 4] Entering Build Directory
cd /d %BUILD_DIRECTORY%

echo [Step 2 of 4] Building The Application
mingw32-make -j%NUMBER_OF_PROCESSORS%
echo The application has been built

echo [Step 3 out of 4] Deploying Qt Dependencies
"%QT_BIN%\windeployqt.exe" "%BUILD_DIRECTORY%/%PROJECT_NAME%"
echo Qt Dependencies have been deployed

echo [Step 4 out of 4] Launching %PROJECT_NAME%...
start "" "%PROJECT_NAME%"