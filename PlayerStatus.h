#pragma once

#include "StatusBase.h"

class PlayerStatus {

public:

	PlayerStatus();
	~PlayerStatus();

	void init();
	void end();

	void update();

	StatusBase getStatus() { return m_playerStatus; }

private:

	StatusBase m_playerStatus;

};
