#include "DxLib.h"
#include "Pad.h"
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

	m_itemNum = 3;
	m_repeatDown = 0;
	m_repeatUp = 0;
	m_selectIndex = 0;


	m_isGameEnd = false;

}

SelectMenu::Cursor::~Cursor() {



}

void SelectMenu::Cursor::update() {

	if (Pad::isPress(PAD_INPUT_UP))
	{
		if (m_repeatUp <= 0) {



			m_selectIndex--;
			m_repeatUp = 8;
			if (m_selectIndex < 0) {
				if (Pad::isTrigger(PAD_INPUT_UP)) {
					m_selectIndex = m_itemNum - 1;
				}
				else {
					m_selectIndex = 0;
				}
			}
		}
		else {
			m_repeatUp--;
		}
	}
	else {
		m_repeatUp = 0;
	}



	if (Pad::isPress(PAD_INPUT_DOWN)) {
		if (m_repeatDown <= 0) {
			m_selectIndex++;
			m_repeatDown = 8;
			if (m_selectIndex > m_itemNum - 1) {
				if (Pad::isTrigger(PAD_INPUT_DOWN)) {
					m_selectIndex = 0;
				}
				else {
					m_selectIndex = m_itemNum - 1;
				}
			}
		}
		else {
			m_repeatDown--;
		}
	}
	else {
		m_repeatDown = 0;
	}

	if (Pad::isTrigger(PAD_INPUT_1)) {

		if (m_selectIndex = 2) {
			m_isGameEnd = true;
		}

	}

}

void SelectMenu::Cursor::draw() {

	int posX = m_menuPos.x;
	int posY = m_menuPos.y + kMenuInterval * m_selectIndex;

	DrawBox(posX, posY, posX + m_size.x, posY + m_size.y, GetColor(255, 255, 255), false);

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

	m_cursor.update();

}

void SelectMenu::draw() {

	m_cursor.draw();

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

	m_cursor.setMenuPos(m_pos);
	m_cursor.setSize(Vec2(getWindouWidth(), kMenuInterval/2));

}

void SelectMenu::setPos(float x,float y) {

	setPos(Vec2(x, y));

}

void SelectMenu::setPos(Vec2 pos) {

	m_pos = pos;

}

int SelectMenu::getWindouWidth()
{
	int width = 0;

	// ��ԉ����̍L�����j���[���ڂ̕����E�C���h�E�T�C�Y�ɂ���
	for (auto& pItem : m_pItem)
	{
		if (width < pItem->getTextWidth())
		{
			width = pItem->getTextWidth();
		}
	}
	return width;
}

void SelectMenu::addItem(const char* text) {

	Item* pItem = new Item;
	pItem->setText(text);
	m_pItem.push_back(pItem);

}
