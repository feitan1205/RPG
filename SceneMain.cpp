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

// 初期化
void SceneMain::init()
{

	m_isMenu = false;

	m_map.init();
	m_player.init();

}

// 終了処理
void SceneMain::end()
{

	m_player.end();

	m_map.end();

}

// 毎フレームの処理
void SceneMain::update()
{
	m_map.update();
	m_player.update();

	if (Pad::isTrigger(PAD_INPUT_8)) {
		m_isMenu = true;
	}

}

// 毎フレームの描画
void SceneMain::draw()
{
	m_map.draw();
	m_player.draw();
}