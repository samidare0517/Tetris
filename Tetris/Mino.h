#pragma once
#include "Vec2.h"
#include "Pad.h"
class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	virtual void update();
	virtual void draw();


private:
	// �\���ʒu
	Vec2 m_pos;

	// �ړ�
	Vec2 m_vec;

	int fallframe = 0;

};

