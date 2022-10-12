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

	void end();

	void draw();

	Vec2 setWood1pos() { m_wood1pos = m_wood1.getWood1pos(); }
	Vec2 setWood1size() { m_wood1size = m_wood1.getWood1size(); }

	Vec2 getWood1pos() { return m_wood1pos; }
	Vec2 getWood1size() { return m_wood1size; }

	class Wood1 {

	public:

		Wood1();
		~Wood1();

		void init();

		void setPos(float x, float y);
		void setPos(Vec2 pos);
		void setSize();

		void end();

		void draw(Vec2 pos);

		Vec2 getWood1pos() { return m_pos; }
		Vec2 getWood1size() { return m_size; }

	private:

		Vec2 m_pos;
		Vec2 m_size;

		int m_handle;
	};

private:

	int m_groundHandle;

	Vec2 m_wood1pos;
	Vec2 m_wood1size;

	Vec2 m_pos;

	Wood1 m_wood1;

};