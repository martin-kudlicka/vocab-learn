#pragma once

#include <QtCore/QSettings>

class Settings
{
	public:
		static const int DEFAULT_DIMENSION = -1;

		Settings();

		const int GetFrequency() const;
		const int GetNewWordsCount() const;
		const int GetNewWordsFrequency() const;
		const bool GetOnTop() const;
		const QString GetVocabFile() const;
		const int GetWindowHeight() const;
		const int GetWindowWidth() const;
		const int GetWindowX() const;
		const int GetWindowY() const;
		const void SetVocabFile(const QString &pFile);
		const void SetWindowHeight(const int &pHeight);
		const void SetWindowWidth(const int &pWidth);
		const void SetWindowX(const int &pX);
		const void SetWindowY(const int &pY);

	private:
		static const int DEFAULT_FREQUENCY = 60 * 1000;
		static const int DEFAULT_NEWWORDSFREQUENCY = 5;

		QSettings _qsSettings;
}; // Settings