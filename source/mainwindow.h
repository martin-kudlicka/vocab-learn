#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "settings.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		~MainWindow();
		MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);

	private:
		static const int SHOW_TRANSL_DIVIDER = 12;

		int _iCurrentWord;
		int _iTimerRepeat;
		int _iTimerTransl;
		QString _qsVocabFile;
		QStringList _qslVocabList;
		uint _uiWordCount;
		Settings _sSettings;
		Ui::Ui_MainWindow _uiMainWindow;

		void timerEvent(QTimerEvent *event);

	private slots:
		const void LoadData();
		const void on_ActionOpen_triggered(bool checked = false);
		const void OpenFile();
}; // MainWindow