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
	
	bool RockBlock = false;		// �Œ�p�t���O

	int Field[BOAD_HEIGHT][BOAD_WINDTH] = { 0 };
	int g_tetris[TETRIS_WINDTH][TETRIS_HEIGHT];        // ���������e�g���~�m(�������ƂŎg��??)

	

private:


	int x;
	int y;


};

