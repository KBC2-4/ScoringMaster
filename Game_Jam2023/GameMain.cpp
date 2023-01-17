#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//�ŏ��Ɏ��s�����֐�
	title_font = CreateFontToHandle("���C���I", 120, 1);
	time_font = CreateFontToHandle("���C���I", 40,1);
	 

	clear_flg = false;

	
	start_count = GetNowCount() + 1000 * 60;

}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	//�Ō�Ɏ��s�����֐�
}

void GameMain::Update()
{
	time_limit =  GetNowCount() - start_count;

	//B�{�^������������
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		clear_flg = true;
	}
}

void GameMain::Draw()
{
	DrawStringToHandle(400, 300, "�Q�[�����C��", 0xFF5F0F, title_font);
	DrawFormatString2(1000, 50, 0xFF0000, 0xFFFFFF, "%5d.%.3d", -time_limit / 1000, -time_limit % 1000);
}
