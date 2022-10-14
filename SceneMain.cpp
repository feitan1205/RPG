#include "DxLib.h"
#include <cassert>
#include <vector>
#include "game.h"
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

bool CheckOutMap(Vec2 playerMinHitBox, Vec2 playerMaxHitBox, Vec2 minMapSize, Vec2 maxMapSize) {

	bool OutMap = false;

	if (playerMinHitBox.y < minMapSize.y)		OutMap = true;
	if (playerMaxHitBox.y > maxMapSize.y)		OutMap = true;
	if (playerMinHitBox.x < minMapSize.x)		OutMap = true;
	if (playerMaxHitBox.x > maxMapSize.x)		OutMap = true;
	
	return OutMap;


	//return false;
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

	addWood1(0, 0);
	addWood1(60, 0);
	addWood1(120, 0);
	addWood1(180, 0);
	addWood1(240, 0);

	for (int i = 0; i < 8; i++) {
		addRoad1(static_cast<float>(i * 30), 200);
	}

	m_isMenu = false;
	m_isOpenWindow = false;

	m_map.init();

	for (int i = 0; i < m_pWood1.size(); i++) {
		m_pWood1[i]->init();
		m_pWood1[i]->setSize();
		m_pWood1[i]->setHitBox();
	}

	for (int i = 0; i < m_pRoad1.size(); i++) {
		m_pRoad1[i]->init();
	}

	m_player.init();

	m_player.setPlayerSize();

	m_enemy1.init();

	m_enemy1.setPlayerSize();

	m_menuWindow.init();

	m_enemy1.setPos(static_cast<float>(GetRand(static_cast<int>(m_map.getMaxMapSize().x))), 
		static_cast<float>(GetRand(static_cast<int>(m_map.getMaxMapSize().y))));

}

// 終了処理
void SceneMain::end()
{

	m_map.end();

	m_player.end();

	m_enemy1.end();

	m_menuWindow.end();

	for (int i = 0; i < m_pWood1.size(); i++) {
		m_pWood1[i]->end();
		delete m_pWood1[i];
	}

	for (int i = 0; i < m_pRoad1.size(); i++) {
		m_pRoad1[i]->end();
		delete m_pRoad1[i];
	}

	m_pWood1.clear();
	m_pRoad1.clear();

}

// 毎フレームの処理
void SceneMain::update()
{
	if (!m_isOpenWindow) {
		if (Pad::isTrigger(PAD_INPUT_4)) {
			m_isOpenWindow = true;
		}
	}
	else {
		if (Pad::isTrigger(PAD_INPUT_4)) {
			m_isOpenWindow = false;
		}
	}

	if (m_isOpenWindow) {

		m_menuWindow.update();

		m_isGameEnd = m_menuWindow.getisGameEnd();

		return;
	}

	m_map.update();


	for (int i = 0; i < m_pWood1.size(); i++) {
		m_pWood1[i]->update();
		m_pWood1[i]->setHitBox();
	}

	for (int i = 0; i < m_pRoad1.size(); i++) {
		m_pRoad1[i]->update();
	}

	m_player.update();
	m_player.setHitBox();

	m_enemy1.update();
	m_enemy1.setHitBox();

	for (int i = 0; i < m_pWood1.size(); i++) {
		m_isHit = CheckHit(m_player.getMinHitBox(), m_player.getMaxHitBox(), m_pWood1[i]->getMinHitBox(), m_pWood1[i]->getMaxHitBox());
		if (m_isHit)		break;
	}

	if(!m_isHit){
		m_isHit = CheckOutMap(m_player.getMinHitBox(), m_player.getMaxHitBox(), m_map.getMinMapSize(), m_map.getMaxMapSize());
	}

	if (m_isHit) {

		for (int i = 0; i < m_pWood1.size(); i++) {
			m_pWood1[i]->back();
		}
		for (int i = 0; i < m_pRoad1.size(); i++) {
			m_pRoad1[i]->back();
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
	
	for (int i = 0; i < m_pRoad1.size(); i++) {
		m_pRoad1[i]->draw();
	}

	m_player.draw();
	m_enemy1.draw();

	for (int i = 0; i < m_pWood1.size(); i++) {
		if (m_player.getMinHitBox().y < m_pWood1[i]->getMaxHitBox().y)		m_pWood1[i]->draw();
	}

	if (m_isOpenWindow) {

		m_menuWindow.draw();

	}

	DrawFormatString(0, 16, GetColor(255, 255, 255), "%d", m_pWood1.size(), true);
	DrawFormatString(0, 32, GetColor(255, 255, 255), "%f", m_player.getMaxHitBox().y, true);


}

void SceneMain::addWood1(float x,float y) {

	ObjectWood1* pWood1 = new ObjectWood1;
	pWood1->setPos(x, y);
	m_pWood1.push_back(pWood1);

}

void SceneMain::addRoad1(float x, float y) {

	ObjectRoad1* pRoad1 = new ObjectRoad1;
	pRoad1->setPos(x, y);
	m_pRoad1.push_back(pRoad1);

}
