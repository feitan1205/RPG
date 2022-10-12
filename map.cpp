#include "DxLib.h"
#include "map.h"


bool CheckHit() {



}

Map::Map() {

	m_groundHandle = -1;
	m_woodHandle = -1;

	m_pos.x = 0;
	m_pos.y = 0;

}

Map::~Map() {

}

void Map::init() {


	m_groundHandle = LoadGraph("data/jimen1.png");
	m_woodHandle = LoadGraph("data/wood1.png");

	m_pos.x = 0;
	m_pos.y = 0;

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

	DeleteGraph(m_groundHandle);
	DeleteGraph(m_woodHandle);

}

void Map::draw() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			DrawGraph(static_cast<int>(m_pos.x) + j * 64, static_cast<int>(m_pos.y) + i * 64, m_groundHandle, true);
		}
	}

	DrawGraph(static_cast<int>(m_pos.x) + 100, static_cast<int>(m_pos.y) + 100, m_woodHandle, true);
}