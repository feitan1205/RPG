#pragma once

class StatusBase {

public:

	StatusBase();
	~StatusBase();

	void init();
	void end();

	void update();

public:

	int ATK;
	int DEF;
	int SPE;

};