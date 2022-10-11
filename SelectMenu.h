#pragma once

#include<vector>
#include "Vec2.h"

class SelectMenu {

public:

	SelectMenu();
	~SelectMenu();

	void init();
	void end();

	void update();

	void draw();

	void setupCorsor();

	void setPos(float x, float y);
	void setPos(Vec2 vec);

	void addItem(const char* text);



private:
	class Item {

	public:

		Item();
		~Item();

		void draw(int x,int y);

		void setText(const char* text);

		int getTextWidth();

	private:

		const char* m_text;
	};

	class Cursor {

	public:

		Cursor();
		~Cursor();



	};

private:

	Vec2 m_pos;
	std::vector<Item*> m_pItem;

	int width;
};