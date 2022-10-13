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
	void setHitBox();

	void draw();

	Vec2 getMinHitBox() { return minHitBox; }
	Vec2 getMaxHitBox() { return maxHitBox; }

private:

	Vec2 m_size;

	Vec2 minHitBox;

	Vec2 maxHitBox;

	int m_handle;

};
