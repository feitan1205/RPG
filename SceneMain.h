#pragma once

#include "SceneBase.h"
#include "player.h"
#include "map.h"

class SceneMain: public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();
	
private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kGraphicNum];
	// プレイヤー
	Player m_player;

	Map m_map;

	int m_mapHandle;
};