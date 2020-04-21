/**
*	@file GameScene.h
*	@author 中地
*			春日井
*			中本
*	@brief ゲームシーン中の処理
*/

#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

/**
* @brief ゲームシーンの更新関数@n
* ゲームシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameOverSceneが返る)
*/
SceneId UpdateGameScene();

/**
* @brief ゲームシーンの描画関数@n
* ゲームシーンのオブジェクトを描画するための関数
*/
void DrawGameScene();

#endif