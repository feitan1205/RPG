#include "DxLib.h"
#include "ObjectBase.h"
#include "Vec2.h"


void ObjectBase::update() {

	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_pos.y++;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y--;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x++;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_pos.x--;
	}

}