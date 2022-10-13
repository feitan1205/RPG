#include "DxLib.h"
#include "ObjectRoad1.h"


ObjectRoad1::ObjectRoad1() {

	m_handle = -1;

}

ObjectRoad1::~ObjectRoad1() {



}

void ObjectRoad1::init() {

	m_handle = LoadGraph("data/road1.png");

}

void ObjectRoad1::setPos(float x, float y) {

	setPos(Vec2(x, y));

}

void ObjectRoad1::setPos(Vec2 pos) {

	m_pos = pos;

}

void ObjectRoad1::end() {

	DeleteGraph(m_handle);

}

void ObjectRoad1::draw() {

	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);

}