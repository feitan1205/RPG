#include "DxLib.h"
#include "map.h"


//Map::

Map::Map() {

	m_groundHandle = -1;

	m_pos.x = 0;
	m_pos.y = 0;

}

Map::~Map() {

}

void Map::init() {


	m_groundHandle = LoadGraph("data/jimen1.png");

	m_pos.x = 0;
	m_pos.y = 0;

	setMapSize();

}

void Map::setPos(float x, float y) {

	setPos(Vec2(x, y));

}

void Map::setPos(Vec2 pos) {

	m_pos = pos;

}

void Map::setMapSize() {

	m_minMapSize = m_pos;	

}

void Map::update() {

	m_lastPos = m_pos;

	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_pos.y++;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y--;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x++;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_pos.x--;
	}

	m_maxMapSize.x = (static_cast<float>(kGroundNumX) * 64) + m_pos.x;
	m_maxMapSize.y = (static_cast<float>(kGroundNumY) * 64) + m_pos.y;
	

}

void Map::back() {

	m_pos = m_lastPos;

}

void Map::end() {

	DeleteGraph(m_groundHandle);


}

void Map::draw() {

	for (int i = 0; i < kGroundNumY; i++) {
		for (int j = 0; j < kGroundNumX; j++) {
			DrawGraph(static_cast<int>(m_pos.x) + j * 64, static_cast<int>(m_pos.y) + i * 64, m_groundHandle, true);
		}
	}


}