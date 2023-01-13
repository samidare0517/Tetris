#include "Mino.h"
#include "game.h"
#include "SceneMain.h"
#include "common.h"
#include "DxLib.h"

namespace
{
	SceneMain main;
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
	RockBlock = true;		// フラグの初期化
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

	if (Pad::isPress(PAD_INPUT_UP))		// 上方向(デバック用)
	{
		m_pos.y += -20;
	}
	
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
		RockBlock = false;
	}

	// 380の位置まではtrueを返す(実験中のため数字直記入)
	if (m_pos.y < 380)
	{
		RockBlock = true;	// 未固定
	}
	else if(RockBlock = false)
	{	
		m_pos.y = 20; 
	}
}

int Mino::Field(int field[BOAD_WINDTH][BOAD_HEIGHT])
{
	for (int x = 0; x < BOAD_WINDTH; x++)        //fieldの初期化
	{
		for (int y = 0; y < BOAD_HEIGHT; y++)
		{
			main.Field[y][x] = field[y][x];
		}
	}
	return 0;
}

// ミノの固定
void Mino::FixedUpdate()
{
	// 固定処理
	int heignt, windth;

	heignt = (m_pos.y / 20);		// 座標位置を調べる
	windth = (m_pos.x / 20);		// 座標位置を調べる

	// デバック用
	DrawFormatString(50, 100, GetColor(225, 225, 225), "%f", m_pos.y);
	DrawFormatString(50, 150, GetColor(225, 225, 225), "%f", m_pos.x);
	DrawFormatString(50, 200, GetColor(0, 225, 225),   "%d", heignt);
	DrawFormatString(50, 250, GetColor(0, 225, 225),   "%d", windth);
	
	// 固定判定		(false = 固定する　　true = 何もしない)
	if (RockBlock == false)
	{
		int x = heignt, y = windth;
		
		if (main.Field[y][x] == 0)// フィールドに0じゃないのが入っていなかったら
		{
			main.Field[y][x] = 1;		// 背景(case1)を呼び出す
		}
	}
	if (RockBlock == true)
	{
		int x = heignt, y = windth;

		main.Field[y][x] = 0;		// それ以外は何もしない
	}
	
}

void Mino::draw()
{	
	// ミノ(一個のみ仮)
	SetFontSize(25);		// ■のサイズを25に調整
	DrawString(m_pos.x - 3, m_pos.y - 2, "■", GetColor(225, 0, 225));

	// フラグの確認(デバック用)
	if (RockBlock == false)		// 固定されている
	{
		DrawString(50, 300, "a 固定 \n  false", GetColor(0, 225, 0));
	}
	if (RockBlock == true)		// 固定されていない
	{
		DrawString(50, 300, "b 未固定 \n  true", GetColor(0, 225, 0));
	}

}

//struct Minos
//{
//	int cells[4][4];	// ブロックの配置
//};
//
//Minos minos[8] =
//{
//	// Oテトリミノ
//	{
//		0,0,0,0,
//		0,3,3,0,
//		0,3,3,0,
//		0,0,0,0
//	},
//
//	// Iテトリミノ
//	{
//		0,0,0,0,
//		0,0,0,0,
//		3,3,3,3,
//		0,0,0,0
//	},
//
//	// Sテトリミノ
//	{
//		0,0,0,0,
//		0,3,3,0,
//		3,3,0,0,
//		0,0,0,0
//	},
//
//	// Zテトリミノ
//	{
//		0,0,0,0,
//		0,3,3,0,
//		0,0,3,3,
//		0,0,0,0
//	},
//
//	// Jテトリミノ
//	{
//		0,0,3,0,
//		0,0,3,0,
//		0,3,3,0,
//		0,0,0,0
//	},
//
//	// Lテトリミノ
//	{
//		0,3,0,0,
//		0,3,0,0,
//		0,3,3,0,
//		0,0,0,0
//	},
//
//	// Tテトリミノ
//	{
//		0,0,0,0,
//		0,3,0,0,
//		3,3,3,0,
//		0,0,0,0,
//	},
//};