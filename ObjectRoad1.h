#pragma once

#include "ObjectBase.h"
#include "Vec2.h"


class ObjectRoad1 :public ObjectBase {

public:

	ObjectRoad1();
	~ObjectRoad1();

	void init();
	void end();

	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void draw();

private:

	int m_handle;

};
