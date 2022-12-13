#include "DxLib.h"

#include "game.h"
#include "SceneMain.h"





// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	
	// �E�C���h�E���ݒ�
	SetMainWindowText("�Q�[����");

	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWindth, Game::kScreenHeight, Game::kColorDepth);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);
	SceneMain scenemain;
	scenemain.init();
	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		// ��ʂ̃N���A
		ClearDrawScreen();
	
		scenemain.update();

		scenemain.draw();
		
		// ����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}
//	scenemain.end();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}



