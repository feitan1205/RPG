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
	
private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kGraphicNum];
	// �v���C���[
	Player m_player;

	Map m_map;

	int m_mapHandle;
};