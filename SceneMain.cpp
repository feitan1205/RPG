#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "player.h"
#include "map.h"
#include "Pad.h"


SceneMain::SceneMain()
{
	m_isMenu = false;
}

SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{

	m_isMenu = false;

	m_map.init();
	m_player.init();

}

// �I������
void SceneMain::end()
{

	m_player.end();

	m_map.end();

}

// ���t���[���̏���
void SceneMain::update()
{
	m_map.update();
	m_player.update();

	if (Pad::isTrigger(PAD_INPUT_8)) {
		m_isMenu = true;
	}

}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_map.draw();
	m_player.draw();
}