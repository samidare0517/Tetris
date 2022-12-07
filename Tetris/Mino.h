#pragma once
#include "Vec2.h"
class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	virtual void update();
	virtual void draw();


private:
	// 表示位置
	Vec2 m_pos;

	// 移動
	Vec2 m_vec;

};

