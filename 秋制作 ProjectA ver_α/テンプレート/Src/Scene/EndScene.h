/**
* @file GameOverScene.h
* @brief ゲームオーバーシーンの関数の宣言
*/
#ifndef CLEAR_SCENE_H_
#define CLEAR_SCENE_H_

/**
* @brief ゲームオーバーシーンの更新関数@n
* ゲームオーバーシーンの仕様が実行される
* @return 遷移先シーンID(基本はSceneId::GameOverSceneが返る)
*/
SceneId UpdateClearOverScene();

/**
* @brief ゲームオーバーシーンの描画関数@n
* ゲームオーバーシーンのオブジェクトを描画するための関数
*/
void DrawClearOverScene();

#endif
