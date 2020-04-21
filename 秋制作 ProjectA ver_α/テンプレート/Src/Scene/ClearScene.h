/**
*	@file Botan.h
*	@author 中地
*			春日井
*			中本
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#ifndef GAME_OVER_SCENE_H_
#define GAME_OVER_SCENE_H_

/**
* @brief ゲームオーバーシーンの更新関数@n
* ゲームオーバーシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameOverSceneが返る)
*/
SceneId UpdateClearScene();

/**
* @brief ゲームオーバーシーンの描画関数@n
* ゲームオーバーシーンのオブジェクトを描画するための関数
*/
void DrawClearScene();

#endif
