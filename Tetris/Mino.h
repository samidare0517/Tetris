#pragma once
#include "Vec2.h"
#include "Pad.h"
#include "SceneMain.h"
#include "common.h"

class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	virtual void update();
	virtual void FixedUpdate();
	virtual void draw();
	virtual int Field(int field[BOAD_WINDTH][BOAD_HEIGHT]);

	bool RockBlock = false;		// 固定用フラグ


private:
	// 表示位置
	Vec2 m_pos;

	// 移動
	Vec2 m_vec;

	int fallframe = 0;


};

