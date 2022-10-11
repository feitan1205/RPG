#pragma once
#include "Vec2.h"

class Map {

public:

	Map();
	~Map();

	void init();

	void update();

	void draw();
private:

	int m_mapHandle;

	Vec2 m_pos;

};