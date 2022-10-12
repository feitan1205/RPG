#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "player.h"
#include "map.h"
#include "Pad.h"
#include "Vec2.h"

bool CheckHit(Vec2 playerPos,Vec2 playerSize,Vec2 objectPos,Vec2 objectSize) {

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", objectPos.y + objectSize.y, true);

	if ((playerPos.y + (playerPos.y / 2)) > (objectPos.y + objectSize.y))	return false;
	if ((playerPos.y + playerPos.y) < (objectPos.y + (objectSize.y / 2)))	return false;
	if (playerPos.x > objectPos.x + objectSize.x)							return false;
	if (playerPos.x + playerSize.x < objectPos.x)							return false;

	return true;

}

SceneMain::SceneMain()
{
	m_isMenu = false;
}

SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{

	m_isMenu = false;

	m_map.init();
	m_player.init();

	m_player.setPlayerSize();

}

// 終了処理
void SceneMain::end()
{

	m_player.end();

	m_map.end();

}

// 毎フレームの処理
void SceneMain::update()
{
	m_map.update();
	m_player.update();

	DrawFormatString(0, 16, GetColor(255, 255, 255), "%f", m_player.getPlayerPos(), true);


	//for()
	m_isHit = CheckHit(m_player.getPlayerPos(), m_player.getPlayerSize(),m_map.getWood1pos(),m_map.getWood1size());

	if (m_isHit) {

		m_map.setPos(100, 100);

	}

	if (Pad::isTrigger(PAD_INPUT_8)) {
		m_isMenu = true;
	}

}

// 毎フレームの描画
void SceneMain::draw()
{
	m_map.draw();
	m_player.draw();
}