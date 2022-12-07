#include "SceneMain.h"
#include "Mino.h"
#include "DxLib.h"


namespace
{
	Mino mino;
}


SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{

}

void SceneMain::init()
{
	mino.init();
}

void SceneMain::update()
{
	mino.update();
}

void SceneMain::draw()
{
	mino.draw();

	// ï«Ç…Ç»ÇÈÇ∆Ç±ÇÎ
	// âE
	DrawBox(0, 0, 20, 420, GetColor(225, 225, 225), true);
	// ç∂
	DrawBox(220, 0, 240, 420, GetColor(225, 225, 225), true);
	// â∫
	DrawBox(20, 400, 240, 420, GetColor(225, 225, 225), true);


	// â°ÇÃÉâÉCÉì
	DrawLine(0, 20, 240, 20, GetColor(0, 150, 150), true);
	DrawLine(0, 40, 240, 40, GetColor(0, 150, 150), true);
	DrawLine(0, 60, 240, 60, GetColor(0, 150, 150), true);
	DrawLine(0, 80, 240, 80, GetColor(0, 150, 150), true);
	DrawLine(0, 100, 240, 100, GetColor(0, 150, 150), true);
	DrawLine(0, 120, 240, 120, GetColor(0, 150, 150), true);
	DrawLine(0, 140, 240, 140, GetColor(0, 150, 150), true);
	DrawLine(0, 160, 240, 160, GetColor(0, 150, 150), true);
	DrawLine(0, 180, 240, 180, GetColor(0, 150, 150), true);
	DrawLine(0, 200, 240, 200, GetColor(0, 150, 150), true);
	DrawLine(0, 220, 240, 220, GetColor(0, 150, 150), true);
	DrawLine(0, 240, 240, 240, GetColor(0, 150, 150), true);
	DrawLine(0, 260, 240, 260, GetColor(0, 150, 150), true);
	DrawLine(0, 280, 240, 280, GetColor(0, 150, 150), true);
	DrawLine(0, 300, 240, 300, GetColor(0, 150, 150), true);
	DrawLine(0, 320, 240, 320, GetColor(0, 150, 150), true);
	DrawLine(0, 340, 240, 340, GetColor(0, 150, 150), true);
	DrawLine(0, 360, 240, 360, GetColor(0, 150, 150), true);
	DrawLine(0, 380, 240, 380, GetColor(0, 150, 150), true);
	DrawLine(0, 400, 240, 400, GetColor(0, 150, 150), true);
	DrawLine(0, 420, 240, 420, GetColor(0, 150, 150), true);


	// ècÇÃÉâÉCÉì
	DrawLine(20, 0, 20, 420, GetColor(0, 150, 150), true);
	DrawLine(40, 0, 40, 420, GetColor(0, 150, 150), true);
	DrawLine(60, 0, 60, 420, GetColor(0, 150, 150), true);
	DrawLine(80, 0, 80, 420, GetColor(0, 150, 150), true);
	DrawLine(100, 0, 100, 420, GetColor(0, 150, 150), true);
	DrawLine(120, 0, 120, 420, GetColor(0, 150, 150), true);
	DrawLine(140, 0, 140, 420, GetColor(0, 150, 150), true);
	DrawLine(160, 0, 160, 420, GetColor(0, 150, 150), true);
	DrawLine(180, 0, 180, 420, GetColor(0, 150, 150), true);
	DrawLine(200, 0, 200, 420, GetColor(0, 150, 150), true);
	DrawLine(220, 0, 220, 420, GetColor(0, 150, 150), true);

}

