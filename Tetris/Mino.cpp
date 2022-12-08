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
	m_pos.x = 20.0f;
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

	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	// ミノのパッド移動処理
	if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y += +20;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x += -20;
	}
	if (padState & PAD_INPUT_RIGHT)
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

void Mino::draw()
{
	// ミノ(一個のみ仮)
	DrawBox(m_pos.x, m_pos.y, m_pos.x+20, m_pos.y + 20,GetColor(225, 0, 225), true);

}