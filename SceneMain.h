#pragma once

#include <vector>
#include "SceneBase.h"
#include "SceneMenuWindow.h"
#include "player.h"
#include "map.h"
#include "ObjectWood1.h"
#include "ObjectRoad1.h"

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
	bool getisGameEnd() { return m_isGameEnd; }

	void addWood1(float x,float y);
	void addRoad1(float x,float y);

private:

	bool m_isMenu;

	bool m_isHit;

	bool m_isOpenWindow;

	bool m_isGameEnd;

	// プレイヤー
	Player m_player;

	Map m_map;

	SceneMenuWindow m_menuWindow;

	std::vector<ObjectWood1*> m_pWood1;
	std::vector<ObjectRoad1*> m_pRoad1;


};