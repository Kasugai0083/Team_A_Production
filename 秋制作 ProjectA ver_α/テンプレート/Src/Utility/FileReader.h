#ifndef FILEREADER_H_
#define FILEREADER_H_

#include "../Data/GameData.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>


class FileReader
{
public:
	bool LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_);

	/*
		CSVに日にちを書き込む関数
		[fileName_] ファイルの名前
		[days_]     書き込む日にち
	*/
	void WriteCSV(std::string fileName_, int days_);

private:
	EnemyData m_EData[6];
	GameParam m_GameParam;
	Days m_Days;
};

#endif