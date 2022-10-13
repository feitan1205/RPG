#pragma once

#include <vector>
#include "SceneBase.h"
#include "player.h"
#include "map.h"
#include "ObjectWood1.h"

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

	void addWood1(int x,int y);

private:

	bool m_isMenu;

	bool m_isHit;

	// �v���C���[
	Player m_player;

	Map m_map;

	std::vector<ObjectWood1*> m_pWood1;

};