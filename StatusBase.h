#pragma once

class StatusBase {

public:

	StatusBase() {
		ATK = 0;
		DEF = 0;
		SPE = 0;
	}
	~StatusBase() {}

	virtual void init() {}
	virtual void end() {}

	virtual void update() {}

public:

	int ATK;
	int DEF;
	int SPE;

};