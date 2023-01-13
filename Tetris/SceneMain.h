#pragma once
#include "Pad.h"
#include "Mino.h"
#include "common.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();
	virtual void update();
	virtual void draw();
	
	bool RockBlock = true;		// 固定用フラグ

	int Field[BOAD_HEIGHT][BOAD_WINDTH] = { 0 };


	

private:

	int x;
	int y;
	
};

