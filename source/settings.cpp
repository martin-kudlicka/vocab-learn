#include "settings.h"

const QString KEY_FREQUENCY = "frequency";
const QString KEY_NEWWORDSCOUNT = "newwordscount";
const QString KEY_NEWWORDSFREQUENCY = "newwordsfrequency";
const QString KEY_ONTOP = "ontop";
const QString KEY_VOCABFILE = "vocabfile";
const QString KEY_WINDOWHEIGHT = "windowheight";
const QString KEY_WINDOWWIDTH = "windowwidth";
const QString KEY_WINDOWX = "windowx";
const QString KEY_WINDOWY = "windowy";
const QString INI_FILE = "VocabLearn.ini";

const int Settings::GetFrequency() const
{
	return _qsSettings.value(KEY_FREQUENCY, DEFAULT_FREQUENCY).toInt();
} // GetFrequency

const int Settings::GetNewWordsCount() const
{
	return _qsSettings.value(KEY_NEWWORDSCOUNT).toInt();
} // GetNewWordsCount

const int Settings::GetNewWordsFrequency() const
{
	return _qsSettings.value(KEY_NEWWORDSFREQUENCY, DEFAULT_NEWWORDSFREQUENCY).toInt();
} // GetNewWordsFrequency

const bool Settings::GetOnTop() const
{
	return _qsSettings.value(KEY_ONTOP, false).toBool();
} // GetOnTop

const QString Settings::GetVocabFile() const
{
	return _qsSettings.value(KEY_VOCABFILE).toString();
} // GetVocabFile

const int Settings::GetWindowHeight() const
{
	return _qsSettings.value(KEY_WINDOWHEIGHT, DEFAULT_DIMENSION).toInt();
} // GetWindowHeight

const int Settings::GetWindowWidth() const
{
	return _qsSettings.value(KEY_WINDOWWIDTH, DEFAULT_DIMENSION).toInt();
} // GetWindowWidth

const int Settings::GetWindowX() const
{
	return _qsSettings.value(KEY_WINDOWX, DEFAULT_DIMENSION).toInt();
} // GetWindowX

const int Settings::GetWindowY() const
{
	return _qsSettings.value(KEY_WINDOWY, DEFAULT_DIMENSION).toInt();
} // GetWindowY

Settings::Settings() : _qsSettings(INI_FILE, QSettings::IniFormat)
{
} // Settings

const void Settings::SetVocabFile(const QString &pFile)
{
	_qsSettings.setValue(KEY_VOCABFILE, pFile);
} // SetVocabFile

const void Settings::SetWindowHeight(const int &pHeight)
{
	_qsSettings.setValue(KEY_WINDOWHEIGHT, pHeight);
} // SetWindowHeight

const void Settings::SetWindowWidth(const int &pWidth)
{
	_qsSettings.setValue(KEY_WINDOWWIDTH, pWidth);
} // SetWindowWidth

const void Settings::SetWindowX(const int &pX)
{
	_qsSettings.setValue(KEY_WINDOWX, pX);
} // SetWindowX

const void Settings::SetWindowY(const int &pY)
{
	_qsSettings.setValue(KEY_WINDOWY, pY);
} // SetWindowY