#include "Mino.h"
#include "game.h"
#include "DxLib.h"

namespace
{

}


Mino::Mino()
{

}

Mino::~Mino()
{

}

void Mino::init()
{
	// 初期位置
	m_pos.x = 120.0f;
	m_pos.y = 20.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

// ミノ移動処理
void Mino::update()
{
	fallframe++;



	// フレーム計算
	if (fallframe >= 60)
	{
		fallframe = 0;
		m_pos.y  += 20;		// 1フレームで20ずつ下げる
	
	}

	// ミノのパッド移動処理
	if (Pad::isPress( PAD_INPUT_DOWN))		// 下方向
	{
		m_pos.y += +20;
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))		// 左方向
	{
		m_pos.x += -20;
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT))	// 右方向
	{
		m_pos.x += +20;
	}

	// ミノが外に出ないようにする
	if (m_pos.x < 20)
	{
		m_pos.x = 20;
	}
	if (m_pos.x > Game::kScreenWindth - 40)
	{
		m_pos.x = Game::kScreenWindth - 40;
	}
	if (m_pos.y < 20)
	{
		m_pos.y = 20;
	}
	if (m_pos.y > Game::kScreenHeight - 40)
	{
		m_pos.y = Game::kScreenHeight - 40;
	}


}

// ミノの固定
void Mino::FixedUpdate()
{
	// 一番下の座標まで行ったらその場所に固定する



}

void Mino::draw()
{
	// ミノ(一個のみ仮)
	DrawBox(m_pos.x, m_pos.y, m_pos.x + 20, m_pos.y + 20, GetColor(225, 0, 225), true);
	
}