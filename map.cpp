#include "DxLib.h"
#include "map.h"


Map::Map() {

	m_mapHandle = -1;

	m_pos.x = 0;
	m_pos.y = 0;

}

Map::~Map() {

}

void Map::init() {


	m_mapHandle = LoadGraph("data/map.png");

	m_pos.x = 70;
	m_pos.y = 10;

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
	

}

void Map::end() {

	DeleteGraph(m_mapHandle);

}

void Map::draw() {

	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_mapHandle, true);

}