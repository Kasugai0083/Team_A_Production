#pragma once
/**
*	@file OpeningScene.h
*	@author 中地
*			春日井
*			中本
*	@brief オープニングシーン中の処理
*/

#ifndef OPENING_SCENE_H_
#define OPENING_SCENE_H_

/**
* @brief オープニングシーンの更新関数@n
* オープニングシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameOverSceneが返る)
*/
SceneId UpdateOpeningScene();

/**
* @brief オープニングシーンの描画関数@n
* オープニングシーンのオブジェクトを描画するための関数
*/
void DrawOpeningScene();

#endif
