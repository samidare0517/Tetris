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
	virtual void FixedUpdate();
	virtual void draw();


private:
	// 表示位置
	Vec2 m_pos;

	// 移動
	Vec2 m_vec;

	int fallframe = 0;

};

