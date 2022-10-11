#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "player.h"
#include "map.h"

namespace {

	const char* const kPlayerGraphicFilename = "data/char.png";

	constexpr int kPlayerGraphicDivX = Player::kGraphicDivX;
	constexpr int kPlayerGraphicDivY = Player::kGraphicDivY;
	constexpr int kPlayerGraphicNum = Player::kGraphicNum;

	constexpr int kPlayerGraphicSizeX = Player::kGraphicSizeX;
	constexpr int kPlayerGraphicSizeY = Player::kGraphicSizeY;

}

SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic) {

		handle = -1;

	}
}

SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	LoadDivGraph(kPlayerGraphicFilename, kPlayerGraphicNum, kPlayerGraphicDivX, kPlayerGraphicDivY,
		kPlayerGraphicSizeX, kPlayerGraphicSizeY, m_hPlayerGraphic);

	for (int i = 0; i < 12; i++) {
		m_player.setHandle(i, m_hPlayerGraphic[i]);
	}

	m_map.init();
	m_player.init();

}

// 終了処理
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic) {

		DeleteGraph(handle);

	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_map.update();
	m_player.update();
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_map.draw();
	m_player.draw();
}