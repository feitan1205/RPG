#pragma once

// �Q�[���V�[�����N���X
class EnemyBase
{
public:
	EnemyBase() {}
	virtual ~EnemyBase() {}


	virtual void init() {}
	virtual void end() {}

	virtual void update() {}
	virtual void draw() {}

	// �V�[���I��
	virtual bool isEnd() { return false; }
};