#include "mainwindow.h"

#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication qaApplication(argc, argv);
	MainWindow mwMainWindow;

	mwMainWindow.show();

	return qaApplication.exec();
} // main