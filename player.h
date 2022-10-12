#pragma once

#include "Vec2.h"

class Player
{
public:

	static constexpr int kGraphicDivX = 3;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicNum = kGraphicDivX * kGraphicDivY;

	static constexpr int kGraphicSizeX = 32;
	static constexpr int kGraphicSizeY = 32;

	Player();
	virtual ~Player();

	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// プレイヤーの初期化
	void init();

	// 処理
	void update();
	
	void end();

	// 描画
	void draw();



private:
	int m_handle[12];

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	int m_animeNo;

	int m_animeFrame;

	int motion;
};