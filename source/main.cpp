#include "mainwindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication qaApplication(argc, argv);
	MainWindow mwMainWindow;

	mwMainWindow.show();

	return qaApplication.exec();
} // main