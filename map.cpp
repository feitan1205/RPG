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



}

void Map::draw() {

	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_mapHandle, true);

}