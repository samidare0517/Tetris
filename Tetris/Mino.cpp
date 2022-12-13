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
	// �����ʒu
	m_pos.x = 120.0f;
	m_pos.y = 20.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

// �~�m�ړ�����
void Mino::update()
{
	fallframe++;



	// �t���[���v�Z
	if (fallframe >= 60)
	{
		fallframe = 0;
		m_pos.y  += 20;		// 1�t���[����20��������
	
	}

	// �~�m�̃p�b�h�ړ�����
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
	}


}

// �~�m�̌Œ�
void Mino::FixedUpdate()
{
	// ��ԉ��̍��W�܂ōs�����炻�̏ꏊ�ɌŒ肷��



}

void Mino::draw()
{
	// �~�m(��̂݉�)
	DrawBox(m_pos.x, m_pos.y, m_pos.x + 20, m_pos.y + 20, GetColor(225, 0, 225), true);
	
}