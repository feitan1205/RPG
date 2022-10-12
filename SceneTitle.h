#pragma once
	
#include "SceneBase.h"
#include "SelectMenu.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_textPosY = 0;
		m_textVecY = 0;
		m_isGameStart = false;
		m_isGameEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init();
	virtual void end() { m_menu.end(); }

	virtual void update();
	virtual void draw();

	virtual bool isGameStart() { return m_isGameStart; }
	virtual bool getisGameEnd() { return m_isGameEnd; }

private:
	// �e�L�X�g�\���ʒu�ύX
	int m_textPosY;
	int m_textVecY;

	SelectMenu m_menu;

	bool m_isGameStart;
	bool m_isGameEnd;
};