#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "Enemy1.h"

namespace
{
	const char* const kPlayerGraphicFilename = "data/raion.png";

	constexpr int kPlayerGraphicDivX = Enemy1::kGraphicDivX;
	constexpr int kPlayerGraphicDivY = Enemy1::kGraphicDivY;
	constexpr int kPlayerGraphicNum = Enemy1::kGraphicNum;

	constexpr int kPlayerGraphicSizeX = Enemy1::kGraphicSizeX;
	constexpr int kPlayerGraphicSizeY = Enemy1::kGraphicSizeY;

	constexpr int kAnimeChangeFrame = 8;
}

Enemy1::Enemy1()
{
	for (auto& handle : m_handle) {

		handle = -1;

	}

	m_animeNo = 0;
	motion = 0;
	m_animeFrame = 0;


}

Enemy1::~Enemy1()
{

}

void Enemy1::init()
{
	LoadDivGraph(kPlayerGraphicFilename, kPlayerGraphicNum, kPlayerGraphicDivX, kPlayerGraphicDivY,
		kPlayerGraphicSizeX, kPlayerGraphicSizeY, m_handle);

	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 1;
	m_animeFrame = 0;
	motion = 1;

	m_status.init();

}

void Enemy1::update()
{


	m_animeFrame++;

	if (m_animeFrame >= (kGraphicDivX + 1) * kAnimeChangeFrame) {

		m_animeFrame = 0;

	}


	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3) {
			m_animeNo = 1;
		}
		m_animeNo += 9;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3) {
			m_animeNo = 1;
		}
		m_animeNo += 0;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3) {
			m_animeNo = 1;
		}
		m_animeNo += 3;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3) {
			m_animeNo = 1;
		}
		m_animeNo += 6;
	}
	if (padState == 0) {
		if (m_animeNo % 3 == 0) {
			m_animeNo += 1;
		}
		else if (m_animeNo % 3 == 2) {
			m_animeNo -= 1;
		}
	}



}

void Enemy1::setPos(float x, float y) {

	setPos(Vec2(x, y));

}

void Enemy1::setPos(Vec2 pos) {

	m_pos = pos;

}

void Enemy1::setPlayerSize() {


	GetGraphSizeF(m_handle[1], &m_size.x, &m_size.y);

}

void Enemy1::setHitBox() {

	minHitBox.x = m_pos.x + (m_size.x / 8);
	minHitBox.y = m_pos.y + ((m_size.x / 4) * 3);
	maxHitBox.x = m_pos.x + ((m_size.x / 8) * 7);
	maxHitBox.y = m_pos.y + ((m_size.y / 7) * 6);

}

void Enemy1::end() {

	for (auto& handle : m_handle) {

		DeleteGraph(handle);

	}

}

void Enemy1::draw()
{
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}