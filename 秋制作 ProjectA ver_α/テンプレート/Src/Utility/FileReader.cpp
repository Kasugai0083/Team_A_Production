#include "FileReader.h"
#include <windows.h>

bool FileReader::LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_)
{
	FILE* pFile;
	fopen_s(&pFile, "Days.csv", "r");

	if (pFile == nullptr) {
		MessageBox(0, "DaysCSVファイルの読み込みに失敗しました", 0, MB_OK);
		return false;
	}

	char buf[256];
	int TmpDays;
	while (fgets(buf, 256, pFile) != nullptr)
	{
		if (buf[0] == '#') {
			fseek(pFile, 1, SEEK_SET);
			continue;
		}

		fscanf_s(pFile, "%d", &TmpDays);
	}
	fclose(pFile);
	pFile = nullptr;
	
	switch (TmpDays)
	{
	case 1: *days_ = Days::DAY_1; break;
	case 2: *days_ = Days::DAY_2; break;
	case 3: *days_ = Days::DAY_3; break;
	default:
		break;
	}

	std::ostringstream oss;
	oss << TmpDays;

	std::string FileName = "EnemyData";
	FileName = FileName + oss.str();
	FileName = FileName + ".csv";

	fopen_s(&pFile, FileName.c_str(), "r");
	if (pFile == nullptr) {
		MessageBox(0, "Enemycsvファイルの読み込みに失敗しました", 0, MB_OK);
		return false;
	}

	char buf1[256];
	int i = 0;
	while (fgets(buf1, 256, pFile) != nullptr)
	{
		if (buf1[0] == '#') {
			fseek(pFile, 1, SEEK_SET);
			continue;
		}

		fscanf_s(pFile, "%d,%d", &enemyData_[i].m_MovementSpeed, &enemyData_[i].m_SpownJudge);
		++i;
	}
	fclose(pFile);
	pFile = nullptr;


	fopen_s(&pFile, "GameData.csv", "r");

	if (pFile == nullptr) {
		MessageBox(0, "GamedataCSVファイルの読み込みに失敗しました", 0, MB_OK);
		return false;
	}

	char buf3[256];
	while (fgets(buf3, 256, pFile) != nullptr)
	{
		if (buf3[0] == '#') {
			fseek(pFile, 1, SEEK_SET);
			continue;
		}

		fscanf_s(pFile, "%f,%d", &gameParam_->m_MeltRatio, &gameParam_->m_TimeMagnification);
	}
	fclose(pFile);


	return true;
}

void FileReader::WriteCSV(std::string fileName_, int days_)
{
	std::ofstream Ofs(fileName_);
	Ofs << "#day" << std::endl;
	Ofs << days_ << std::endl;
}
