#include "DxLib.h"
#include <cassert>
#include <vector>
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
	m_isHit = false;
}

SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{

	addWood1(100, 100);
	addWood1(200, 100);

	m_isMenu = false;

	m_map.init();

	for (int i = 0; i < m_pWood1.size(); i++) {
		m_pWood1[i]->init();
		m_pWood1[i]->setSize();
		m_pWood1[i]->setHitBox();
	}

	m_player.init();

	m_player.setPlayerSize();

}

// 終了処理
void SceneMain::end()
{

	m_player.end();
	for (int i = 0; i < m_pWood1.size(); i++) {
		m_pWood1[i]->end();
	}
	m_map.end();

}

// 毎フレームの処理
void SceneMain::update()
{
	m_map.update();

	for (int i = 0; i < m_pWood1.size(); i++) {
		m_pWood1[i]->update();
		m_pWood1[i]->setHitBox();
	}

	m_player.update();
	m_player.setHitBox();


	for (int i = 0; i < m_pWood1.size(); i++) {
		m_isHit = CheckHit(m_player.getMinHitBox(), m_player.getMaxHitBox(), m_pWood1[i]->getMinHitBox(), m_pWood1[i]->getMaxHitBox());
		if (m_isHit)		break;
	}

	/*if(!m_isHit){
		m_isHit = CheckHit(m_player.getMinHitBox(), m_player.getMaxHitBox(), m_map.getMaxMapSize(), m_map.getMinMapSize());
	}*/

	if (m_isHit) {

		for (int i = 0; i < m_pWood1.size(); i++) {
			m_pWood1[i]->back();
		}
		m_map.back();
		//DrawFormatString(0, 0, GetColor(255, 0, 0), "・", true);

	}

	if (Pad::isTrigger(PAD_INPUT_8)) {
		m_isMenu = true;
	}

}

// 毎フレームの描画
void SceneMain::draw()
{
	m_map.draw();

	for (int i = 0; i < m_pWood1.size(); i++) {
		if (m_player.getMinHitBox().y >= m_pWood1[i]->getMaxHitBox().y)		m_pWood1[i]->draw();
	}
	
	m_player.draw();

	for (int i = 0; i < m_pWood1.size(); i++) {
		if (m_player.getMinHitBox().y < m_pWood1[i]->getMaxHitBox().y)		m_pWood1[i]->draw();
	}



	DrawFormatString(0, 16, GetColor(255, 255, 255), "%f", m_map.getMaxMapSize().x, true);
	DrawFormatString(0, 32, GetColor(255, 255, 255), "%f", m_player.getMaxHitBox().x, true);


}

void SceneMain::addWood1(int x,int y) {

	ObjectWood1* pWood1 = new ObjectWood1;
	pWood1->setPos(x, y);
	m_pWood1.push_back(pWood1);

}