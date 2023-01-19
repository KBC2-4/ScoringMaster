#include "main.h"
#include "PadInput.h"
#include "Title.h"
#include "GameMain.h"
#include "Result.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	double dNextTime = GetNowCount();

	SetMainWindowText("�̓_�}�X�^�[");
	SetMainWindowClassName("ScoringMaster");

	SetWindowIconID(01);
	ChangeWindowMode(TRUE);

	SetOutApplicationLogValidFlag(FALSE);   //���O�o�͂𖳌��ɂ���

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);

	SetAlwaysRunFlag(true);		//��ɃA�N�e�B�u�ɂ���

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	Title* title;
	GameMain* gamemain;
	Result* result;

	title = nullptr;
	gamemain = nullptr;
	result = nullptr;

	bool scene_change = false;

	short clear_count = 0;

	enum class GAME_STATE
	{
		TITLE = 0,     //�^�C�g��
		GAME_MAIN,          //���C��
		GAME_RESULT,    //�Q�[���N���A�`��
	};

	GAME_STATE GameState = GAME_STATE::TITLE;

	while (ProcessMessage() == 0) {


		ClearDrawScreen();
		switch (GameState)
		{
		case GAME_STATE::TITLE:
			if (scene_change == false) { title = new Title(); scene_change = true; }
			title->Update();
			title->Draw();

			if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
				delete title;
				GameState = GAME_STATE::GAME_MAIN;
				scene_change = false;
			}
			break;


		case GAME_STATE::GAME_MAIN:
			if (scene_change == false) { gamemain = new GameMain(); scene_change = true; }
			gamemain->Update();
			gamemain->Draw();

			if (gamemain->GetClearFlg() == true) {
				delete gamemain; 
				GameState = GAME_STATE::GAME_RESULT; 
				scene_change = false;
			}
			break;

		case GAME_STATE::GAME_RESULT:
			if (scene_change == false) { result = new Result(clear_count); scene_change = true; }
			
			result->Update();
			result->Draw();
			

			if(result->GetNextScene() == true){ 
				delete result; 
				GameState = GAME_STATE::TITLE; 
				scene_change = false;
			}
			break;
		}
			
		
		PAD_INPUT::UpdateKey();	//�p�b�h�̓��͏�Ԃ̍X�V
		//�t���[�����[�g�̐ݒ�
		dNextTime += static_cast<double>(1.0 / 60.0 * 1000.0);
		if (dNextTime > GetNowCount()) {
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//�␳


				//�f�o�b�O
		//���C�A�E�g�݌v�p
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			for (int x = 0; x < 1280; x += 40) {
				DrawLineAA(x, 0, x, 720, 0x000000, 0.01F);

				for (int y = 0; y < 720; y += 40) {
					DrawLineAA(0, y, 1280, y, 0x000000, 0.01F);
				}
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}


		ScreenFlip();





	}
	DxLib_End();

	return 0;
}