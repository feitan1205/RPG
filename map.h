#pragma once
#include "Vec2.h"

class Map {

public:

	Map();
	~Map();

	void init();

	void update();

	void end();

	void draw();
private:

	int m_groundHandle;
	int m_woodHandle;

	Vec2 m_pos;


};