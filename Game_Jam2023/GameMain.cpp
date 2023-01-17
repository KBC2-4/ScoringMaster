#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//�ŏ��Ɏ��s�����֐�
	title_font = CreateFontToHandle("���C���I", 120, 1);
	clear_flg = false;

}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	//�Ō�Ɏ��s�����֐�
}

void GameMain::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		clear_flg = true;
	}
}

void GameMain::Draw()
{
	DrawStringToHandle(400, 300, "�Q�[�����C��", 0xFF5F0F, title_font);
}
