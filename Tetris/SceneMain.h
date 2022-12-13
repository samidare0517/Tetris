#pragma once
#include "Pad.h"

#define BOAD_WINDTH 12
#define BOAD_HEIGHT 21
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();
	virtual void update();
	virtual void draw();

	int Field[BOAD_HEIGHT][BOAD_WINDTH] = { 0 };
	int Display[BOAD_HEIGHT][BOAD_WINDTH] = { 0 };
private:

};

