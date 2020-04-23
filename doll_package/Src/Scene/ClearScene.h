/**
*	@file ClearScene.h
*	@author 中地
*			春日井
*			中本
*	@brief クリアシーン中の処理
*/

#ifndef GAME_OVER_SCENE_H_
#define GAME_OVER_SCENE_H_

/**
* @brief クリアシーンの更新関数@n
* クリアシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameOverSceneが返る)
*/
SceneId UpdateClearScene();

/**
* @brief クリアシーンの描画関数@n
* クリアシーンのオブジェクトを描画するための関数
*/
void DrawClearScene();

#endif
