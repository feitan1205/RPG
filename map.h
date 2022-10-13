#pragma once
#include "DxLib.h"
#include "Vec2.h"

namespace{

	constexpr int kGroundNumX = 10;
	constexpr int kGroundNumY = 8;

};

class Map {


public:


	Map();
	~Map();

	void init();

	void setPos(float x, float y);
	void setPos(Vec2 pos);
	void setMapSize();

	void update();
	void back();

	void end();

	void draw();

	Vec2 getMinMapSize() { return m_minMapSize; }
	Vec2 getMaxMapSize() { return m_maxMapSize; }

protected:

	Vec2 m_lastPos;

	Vec2 m_pos;

	Vec2 m_minMapSize;

	Vec2 m_maxMapSize;

	int m_groundHandle;

};