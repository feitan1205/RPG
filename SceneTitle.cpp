#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

void SceneTitle::init()
{
	m_textPosY = 0;
	m_textVecY = 4;

	m_isGameStart = false;
	m_isGameEnd = false;

	m_menu.init();
	m_menu.addItem("�Q�[���X�^�[�g");
	m_menu.addItem("�I�v�V����");
	m_menu.addItem("�Q�[���I��");

	m_menu.setPos(Game::kScreenWidth/2-73, Game::kScreenHeight / 2 - 50);
	m_menu.setupCorsor();
}

void SceneTitle::update()
{
	// �����̈ړ�
	m_textPosY += m_textVecY;
	if (m_textPosY < 0)
	{
		m_textPosY = 0;
		m_textVecY = 4;
	}
	if (m_textPosY > 200)
	{
		m_textPosY = 200;
		m_textVecY = -4;
	}

	m_menu.update();

	m_isGameStart = m_menu.getisGameStart();

	m_isGameEnd = m_menu.getisGameEnd();
}

void SceneTitle::draw()
{
	m_menu.draw();
	//DrawString(0, m_textPosY, "�^�C�g�����", GetColor(255, 255, 255));
}