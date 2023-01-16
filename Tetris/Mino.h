#pragma once
#include "Vec2.h"
#include "Pad.h"
#include "SceneMain.h"
#include "common.h"

class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	virtual void update();
	virtual void FixedUpdate();
	virtual void draw();
	virtual int  Field(int field[BOAD_WINDTH][BOAD_HEIGHT]);

	bool RockBlock = true;		// �Œ�p�t���O
	bool Check = true;			// ���Ƀu���b�N�����邩�ǂ����̃`�F�b�N������t���O

	Vec2 getPos() const { return m_pos; }

private:
	// �\���ʒu
	Vec2 m_pos;

	// �ړ�
	Vec2 m_vec;

	int fallframe = 0;
};