#include "DxLib.h"
#include "SelectMenu.h"

namespace {

	constexpr int kMenuInterval = 32;

}


//SelectMenu::Item

SelectMenu::Item::Item() {

	m_text = nullptr;

}

SelectMenu::Item::~Item() {



}

void SelectMenu::Item::draw(int x,int y) {

	DrawString(x, y, m_text, GetColor(255, 255, 255), true);

}

int SelectMenu::Item::getTextWidth()
{
	return GetDrawStringWidth(m_text, strlen(m_text));
}

void SelectMenu::Item::setText(const char* text) {

	m_text = text;

}

//SelectMenu::Cursor

SelectMenu::Cursor::Cursor() {



}

SelectMenu::Cursor::~Cursor() {



}

//SelectMenu::

SelectMenu::SelectMenu() {

	width = 0;

}

SelectMenu::~SelectMenu() {



}

void SelectMenu::init() {



	m_pos.x = 100;
	m_pos.y = 100;



}

void SelectMenu::end() {



}

void SelectMenu::update() {



}

void SelectMenu::draw() {


	for (int i = 0; i < m_pItem.size(); i++) {
		if (m_pItem[i]->getTextWidth() > width) {
			width = m_pItem[i]->getTextWidth();
		}
	}

	int height = kMenuInterval * m_pItem.size();

	DrawBox(static_cast<int>(m_pos.x)-16, static_cast<int>(m_pos.y)-16,
		static_cast<int>(m_pos.x)+width+16, static_cast<int>(m_pos.y)+height,
		GetColor(255, 255, 255), false);

	for (int i = 0; i < m_pItem.size(); i++) {

		m_pItem[i]->draw(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y) + i * kMenuInterval);

	}

}

void SelectMenu::setupCorsor() {



}

void SelectMenu::setPos(float x,float y) {

	setPos(Vec2(x, y));

}

void SelectMenu::setPos(Vec2 pos) {

	m_pos = pos;

}

void SelectMenu::addItem(const char* text) {

	Item* pItem = new Item;
	pItem->setText(text);
	m_pItem.push_back(pItem);

}