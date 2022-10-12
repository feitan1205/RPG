#include "DxLib.h"
#include "map.h"


//Map::Wood::

Map::Wood1::Wood1() {



}

Map::Wood1::~Wood1() {



}

void Map::Wood1::init() {

	m_handle = LoadGraph("data/wood1.png");

}

void Map::Wood1::setPos(float x, float y) {

	setPos(Vec2(x, y));

}

void Map::Wood1::setPos(Vec2 pos) {

	m_pos = pos;

}

void Map::Wood1::setSize() {

	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);

}

void Map::Wood1::end() {

	DeleteGraph(m_handle);

}

void Map::Wood1::draw(Vec2 pos) {

	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);
	DrawFormatString(0, 48, GetColor(255, 255, 255), "%f", m_pos.x, true);


}

//Map::

Map::Map() {

	m_groundHandle = -1;

	m_pos.x = 0;
	m_pos.y = 0;

	m_wood1.init();

}

Map::~Map() {

}

void Map::init() {


	m_groundHandle = LoadGraph("data/jimen1.png");

	m_pos.x = 0;
	m_pos.y = 0;

	m_wood1.setSize();
}

void Map::setPos(float x, float y) {

	setPos(Vec2(x, y));

}

void Map::setPos(Vec2 pos) {

	m_pos = pos;

}

void Map::update() {

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
	

	m_wood1.setPos(100+ m_pos.x, 100+ m_pos.y);

	m_wood1pos = m_wood1.getWood1pos();
	m_wood1size = m_wood1.getWood1size();

}

void Map::end() {

	DeleteGraph(m_groundHandle);

	m_wood1.end();

}

void Map::draw() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			DrawGraph(static_cast<int>(m_pos.x) + j * 64, static_cast<int>(m_pos.y) + i * 64, m_groundHandle, true);
		}
	}

	m_wood1.draw(m_pos);

}