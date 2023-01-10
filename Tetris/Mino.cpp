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
	// �����ʒu
	m_pos.x = 120.0f;
	m_pos.y = 20.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	RockBlock = true;		// �t���O�̏�����
}

// �~�m�ړ�����
void Mino::update()
{
	// �{�[�h�̈�ԉ��܂Ń~�m��������false��Ԃ�
	if (m_pos.y < 380)
	{
		RockBlock = true;
	}
	else
	{
		RockBlock = false;
	}
	fallframe++;

	// �t���[���v�Z
	if (fallframe >= 60)
	{
		fallframe = 0;
		m_pos.y  += 20;		// 1�t���[����20��������
	}


	// �~�m�̃p�b�h�ړ�����

	if (Pad::isPress(PAD_INPUT_UP))		// �����(�f�o�b�N�p)
	{
		m_pos.y += -20;
	}
	
	if (Pad::isPress( PAD_INPUT_DOWN))		// ������
	{
		m_pos.y += +20;
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))		// ������ 
	{
		m_pos.x += -20;
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT))	// �E����
	{
		m_pos.x += +20;
	}

	// �~�m���O�ɏo�Ȃ��悤�ɂ���
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
		m_pos.y = 20;
	}
	
}

int Mino::Field(int field[BOAD_WINDTH][BOAD_HEIGHT])
{
	for (int x = 0; x < BOAD_WINDTH; x++)        //field�̏�����
	{
		for (int y = 0; y < BOAD_HEIGHT; y++)
		{
			main.Field[y][x] = field[y][x];
		}
	}
	return 0;
}

// �~�m�̌Œ�
void Mino::FixedUpdate()
{
	// �Œ菈��
	int heignt, windth;

	heignt = (m_pos.y / 20);		// ���W�ʒu�𒲂ׂ�
	windth = (m_pos.x / 20);		// ���W�ʒu�𒲂ׂ�

	// �f�o�b�N�p
	DrawFormatString(50, 100, GetColor(225, 225, 225), "%f", m_pos.y);
	DrawFormatString(50, 150, GetColor(225, 225, 225), "%f", m_pos.x);
	DrawFormatString(50, 200, GetColor(0, 225, 225),   "%d", heignt);
	DrawFormatString(50, 250, GetColor(0, 225, 225),   "%d", windth);
	
	// �Œ蔻��		(false = �Œ肷��@�@true = �������Ȃ�)
	if (RockBlock == false)
	{
		int x = heignt, y = windth;
		
		if (main.Field[y][x] == 0)// �t�B�[���h��0����Ȃ��̂������Ă��Ȃ�������
		{
			main.Field[y][x] = 1;		// �w�i(case1)���Ăяo��
		}
	}
	if (RockBlock == true)
	{
		int x = heignt, y = windth;

		main.Field[y][x] = 0;		// ����ȊO�͉������Ȃ�
	}
}

void Mino::draw()
{	
	// �~�m(��̂݉�)
	SetFontSize(25);		// ���̃T�C�Y��25�ɒ���
	DrawString(m_pos.x -3 , m_pos.y -2 , "��", GetColor(225, 0, 225));
	

	// �t���O�̊m�F(�f�o�b�N�p)
	if (RockBlock == false)
	{
		DrawString(100, 300, "a", GetColor(0, 225, 0));
	}
	if (RockBlock == true)
	{
		DrawString(100, 300, "b", GetColor(0, 225, 0));
	}
}