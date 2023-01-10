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
	
	bool RockBlock = false;		// 固定用フラグ

	int Field[BOAD_HEIGHT][BOAD_WINDTH] = { 0 };
	int g_tetris[TETRIS_WINDTH][TETRIS_HEIGHT];        // 落下したテトリミノ(多分あとで使う??)

	

private:


	int x;
	int y;


};

