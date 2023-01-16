#include "main.h"
#include "PadInput.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	double dNextTime = GetNowCount();

	SetMainWindowText("Game_Jam2023");
	SetMainWindowClassName("Game_Jam2023");
	ChangeWindowMode(TRUE);

	SetOutApplicationLogValidFlag(FALSE);   //���O�o�͂𖳌��ɂ���

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);

	SetAlwaysRunFlag(true);		//��ɃA�N�e�B�u�ɂ���

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	enum class GAME_STATE
	{
		TITLE = 0,     //�^�C�g��
		GAME_INIT,          //��������
		GAME_MAIN,          //���C��
		GAME_RESULT,    //�Q�[���N���A�`��
	};

	GAME_STATE GameState = GAME_STATE::TITLE;

	while (ProcessMessage() == 0) {

		switch (GameState)
		{
		case GAME_STATE::TITLE:
			//GameTitle();                //�Q�[���^�C�g������           
			break;

		case GAME_STATE::GAME_INIT:
			//Gameinit();                       //�Q�[����������
			break;

		case GAME_STATE::GAME_MAIN:
			//GameMain();                       //�Q�[�����C������
			break;

		case GAME_STATE::GAME_RESULT:
			//GameClear();                   //�Q�[�����U���g����
			break;
		}

		ClearDrawScreen();
		PAD_INPUT::UpdateKey();	//�p�b�h�̓��͏�Ԃ̍X�V
		//�t���[�����[�g�̐ݒ�
		dNextTime += static_cast<double>(1.0 / 60.0 * 1000.0);
		if (dNextTime > GetNowCount()) {
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//�␳

		DrawBoxAA(50, 50, 600, 600, 0xFFFFFF, TRUE, 3.0f);


		ScreenFlip();





	}
	DxLib_End();

	return 0;
}