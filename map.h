#pragma once
#include "Vec2.h"

class Map {

public:

	Map();
	~Map();

	void init();

	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void update();
	void back();

	void end();

	void draw();


protected:

	Vec2 m_lastPos;

	Vec2 m_pos;

	int m_groundHandle;

};