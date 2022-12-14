#pragma once

#include "Vec2.h"

class ObjectBase {

public:

	ObjectBase() {}
	~ObjectBase() {}

	virtual void init() {}
	virtual void end() {}

	virtual void update();
	virtual void back();
	virtual void draw() {}

protected:

	Vec2 m_pos;

	Vec2 m_lastPos;

};