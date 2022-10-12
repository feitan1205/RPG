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
	
	bool isMenuOpen() { return m_isMenu; }
private:

	bool m_isMenu;

	bool m_isHit;

	// プレイヤー
	Player m_player;

	Map m_map;

};