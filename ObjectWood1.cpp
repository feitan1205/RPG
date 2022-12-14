#include "DxLib.h"
#include "ObjectWood1.h"


ObjectWood1::ObjectWood1() {

	m_handle = -1;

}

ObjectWood1::~ObjectWood1() {



}

void ObjectWood1::init() {

	m_handle = LoadGraph("data/wood1.png");

}

void ObjectWood1::setPos(float x, float y) {

	setPos(Vec2(x, y));

}

void ObjectWood1::setPos(Vec2 pos) {

	m_pos = pos;

}

void ObjectWood1::setSize() {

	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);

}

void ObjectWood1::setHitBox() {

	minHitBox.x = m_pos.x + (m_size.x / 8);
	minHitBox.y = m_pos.y + ((m_size.x / 4) * 3);
	maxHitBox.x = m_pos.x + ((m_size.x / 8) * 7);
	maxHitBox.y = m_pos.y + (m_size.y);

}

void ObjectWood1::end() {

	DeleteGraph(m_handle);

}

void ObjectWood1::draw() {

	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, true);

}