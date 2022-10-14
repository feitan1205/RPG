#pragma once

#include "Vec2.h"
#include "PlayerStatus.h"

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
	void setStatus(){m_status = m_inside.getStatus() };

	// 処理
	void update();
	
	void setPlayerSize();

	void setHitBox();

	void end();

	// 描画
	void draw();


	Vec2 getMinHitBox() { return minHitBox; }
	Vec2 getMaxHitBox() { return maxHitBox; }

private:
	int m_handle[12];

	// 表示位置
	Vec2 m_pos;

	Vec2 m_size;
	// 移動
	Vec2 m_vec;

	Vec2 minHitBox;

	Vec2 maxHitBox;

	PlayerStatus m_inside;

	StatusBase m_status;

	int m_animeNo;

	int m_animeFrame;

	int motion;
};