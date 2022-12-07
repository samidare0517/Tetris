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

void Mino::update()
{
	// 移動処理

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

	// ミノが外に出そうになったら画面内に戻す
	/*if (m_pos.x < 0)
	{
		m_pos.x = 0;
	}
	if (m_pos.x > Game::kScreenWindth - 20)
	{
		m_pos.x = Game::kScreenWindth - 20;
	}
	if (m_pos.y < 0)
	{
		m_pos.y = 0;
	}
	if (m_pos.y > Game::kScreenHeight - 20)
	{
		m_pos.y = Game::kScreenHeight - 20;
	}*/

}

void Mino::draw()
{
	// ミノ(一個のみ仮)
	DrawBox(m_pos.x, m_pos.y, m_pos.x+20, m_pos.y + 20,GetColor(225, 0, 225), true);

}