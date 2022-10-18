#pragma once

#include <vector>
#include "SceneBase.h"
#include "SceneMenuWindow.h"
#include "player.h"
#include "Enemy1.h"
#include "map.h"
#include "ObjectWood1.h"
#include "ObjectRoad1.h"

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
	bool getisGameEnd() { return m_isGameEnd; }

	void addWood1(float x,float y);
	void addRoad1(float x,float y);

private:

	bool m_isMenu;

	bool m_isPlayerHit;

	bool m_isEnemyHit;

	bool m_isOpenWindow;

	bool m_isGameEnd;

	// �v���C���[
	Player m_player;

	Enemy1 m_enemy1;

	Map m_map;

	SceneMenuWindow m_menuWindow;

	std::vector<ObjectWood1*> m_pWood1;
	std::vector<ObjectRoad1*> m_pRoad1;

public:

	enum class objecttype
	{
		player,
		enemy,
		wood1,
	};

	typedef struct {
		objecttype type;
		int index;
	}sortdata;
	
};