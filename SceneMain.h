#pragma once

#include "SceneBase.h"
#include "player.h"
#include "map.h"

class SceneMain: public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	
	bool isMenuOpen() { return m_isMenu; }
private:

	bool m_isMenu;

	bool m_isHit;

	// �v���C���[
	Player m_player;

	Map m_map;

};