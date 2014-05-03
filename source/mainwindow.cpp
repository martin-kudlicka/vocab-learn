#include "mainwindow.h"

#include <QtWidgets/QFileDialog>
#include <QtCore/QTime>

const QString FORMAT_TEXT = "<center style=\"font-size:xx-large\">%1</center>";

MainWindow::~MainWindow()
{
	_sSettings.SetVocabFile(_qsVocabFile);
	_sSettings.SetWindowX(geometry().x());
	_sSettings.SetWindowY(geometry().y());
	_sSettings.SetWindowHeight(geometry().height());
	_sSettings.SetWindowWidth(geometry().width());
} // ~MainWindow

MainWindow::MainWindow(QWidget *parent /* 0 */, Qt::WindowFlags flags /* 0 */) : QMainWindow(parent, flags)
{
	_iCurrentWord = -1;
	_iTimerRepeat = 0;
	_iTimerTransl = 0;
	_uiWordCount = 0;

	qsrand(QTime::currentTime().msec());

	_uiMainWindow.setupUi(this);
	if (_sSettings.GetOnTop()) {
		setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
	} // if
	if (_sSettings.GetWindowX() != Settings::DEFAULT_DIMENSION) {
		setGeometry(_sSettings.GetWindowX(), _sSettings.GetWindowY(), _sSettings.GetWindowWidth(), _sSettings.GetWindowHeight());
	} // if

	_qsVocabFile = _sSettings.GetVocabFile();
	OpenFile();
} // MainWindow

const void MainWindow::LoadData()
{
	QFile qfFile(_qsVocabFile);
	if (!qfFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	} // if

	_qslVocabList.clear();
	while (!qfFile.atEnd()) {
		_qslVocabList.append(QString::fromUtf8(qfFile.readLine()));
	} // while

	qfFile.close();
} // LoadData

const void MainWindow::on_ActionOpen_triggered(bool checked /* false */)
{
	QString qsFile = QFileDialog::getOpenFileName(this, tr("Select vocabulary file"), QString(), QString(), NULL, QFileDialog::ReadOnly);
	if (!qsFile.isEmpty()) {
		_qsVocabFile = qsFile;
		OpenFile();
	} // if
} // on_ActionOpen_triggered

const void MainWindow::OpenFile()
{
	if (_iTimerRepeat) {
		killTimer(_iTimerRepeat);
		_iTimerRepeat = 0;
	} // if

	_qsVocabFile = _qsVocabFile;
	LoadData();

	if (!_qslVocabList.isEmpty()) {
		_iTimerRepeat = startTimer(_sSettings.GetFrequency());
		timerEvent(&QTimerEvent(_iTimerRepeat));
	} // if else
} // OpenFile

void MainWindow::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == _iTimerRepeat) {
		_uiWordCount++;
		if (_sSettings.GetNewWordsCount() == 0 || _uiWordCount % _sSettings.GetNewWordsFrequency()) {
			_iCurrentWord = qrand() % _qslVocabList.size();
		} else {
			_iCurrentWord = qrand() % _sSettings.GetNewWordsCount();
			_iCurrentWord += _qslVocabList.size() - _sSettings.GetNewWordsCount();
		} // if else
		QString qsText = _qslVocabList.at(_iCurrentWord);
		qsText = qsText.mid(qsText.indexOf("/"));
		qsText = FORMAT_TEXT.arg(qsText);
		_uiMainWindow.TextEdit->setText(qsText);

		QApplication::beep();

		_iTimerTransl = startTimer(_sSettings.GetFrequency() / SHOW_TRANSL_DIVIDER);
	} else {
		killTimer(_iTimerTransl);
		_iTimerTransl = 0;

		QString qsText = FORMAT_TEXT.arg(_qslVocabList.at(_iCurrentWord));
		_uiMainWindow.TextEdit->setText(qsText);
	} // if else
} // timerEvent