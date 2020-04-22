/**
*	@file	FileReader.h
*	@author	中本
*	@brief	ゲーム管理に必要なデータが入っているCSVを管理するクラスを処理
*/


#ifndef FILEREADER_H_
#define FILEREADER_H_

#include "../Data/GameData.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

/**
* @brief	FileReaderクラス
*/
class FileReader
{
public:
	/**
	* @fn			bool LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_)
	* @brief		ゲームに必要な情報をCSVから抜き取るための関数
	* @param[out]	EnemyData*(enemyData_)	敵に必要な情報を入れるためのEnemyDataポインタ
	* @param[out]	GameParam*(gameParam_)	ゲームメインに必要なパラメーターを保存するためのGameParamポインター
	* @param[out]	Days*(days_)			日にちを入れるためのDayspointerポインター
	* @return		bool					読み込みに成功 : true	読み込みに失敗 : false
	*/ 
	bool LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_);

	/**
	* @fn			void WriteCSV(std::string fileName_, int days_)
	* @brief		現在の進行度CSVに保存するための関数
	* @param[in]	std::string(fileName_)	書き込むファイルの名前
	* @param[in]	int(days_)				現在の日にち
	*/
	void WriteCSV(std::string fileName_, int days_);

};

#endif