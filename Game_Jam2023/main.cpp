#include "main.h"

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

	while (ProcessMessage() == 0 && GameState != 99) {



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