#pragma once

#include "ObjectBase.h"
#include "Vec2.h"


class ObjectWood1 :public ObjectBase {

public:

	ObjectWood1();
	~ObjectWood1();

	void init();
	void end();

	void setPos(float x, float y);
	void setPos(Vec2 pos);
	void setSize();

	void draw();

	Vec2 getWood1pos() { return m_pos; }
	Vec2 getWood1size() { return m_size; }

private:

	Vec2 m_size;

	int m_handle;

};
