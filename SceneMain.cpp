#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "player.h"
#include "map.h"
#include "Pad.h"
#include "Vec2.h"
#include "ObjectBase.h"
#include "ObjectWood1.h"

bool CheckHit(Vec2 playerMinHitBox,Vec2 playerMaxHitBox,Vec2 objectMinHitBox,Vec2 objectMaxHitBox) {


	if (playerMinHitBox.y > objectMaxHitBox.y)		return false;
	if (playerMaxHitBox.y < objectMinHitBox.y)		return false;
	if (playerMinHitBox.x > objectMaxHitBox.x)		return false;
	if (playerMaxHitBox.x < objectMinHitBox.x)		return false;

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
	m_wood1.init();
	m_wood1.setSize();
	m_wood1.setPos(200,200);
	m_wood1.setHitBox();
	m_player.init();

	m_player.setPlayerSize();

}

// 終了処理
void SceneMain::end()
{

	m_player.end();
	m_wood1.end();
	m_map.end();

}

// 毎フレームの処理
void SceneMain::update()
{
	m_map.update();
	m_wood1.update();
	m_player.update();

	m_wood1.setHitBox();
	m_player.setHitBox();


	//for()
	m_isHit = CheckHit(m_player.getMinHitBox(), m_player.getMaxHitBox(),m_wood1.getMinHitBox(), m_wood1.getMaxHitBox());
	
	if (m_isHit) {

		//m_map.setPos(100, 100);
		DrawFormatString(0, 0, GetColor(255, 0, 0), "・", true);

	}

	if (Pad::isTrigger(PAD_INPUT_8)) {
		m_isMenu = true;
	}

}

// 毎フレームの描画
void SceneMain::draw()
{
	m_map.draw();
	m_wood1.draw();
	m_player.draw();
	DrawFormatString(0, 16, GetColor(255, 255, 255), "%f", m_wood1.getMaxHitBox().y, true);
	DrawFormatString(0, 32, GetColor(255, 255, 255), "%f", m_player.getMinHitBox().y, true);


}