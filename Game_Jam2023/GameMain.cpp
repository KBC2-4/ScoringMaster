#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//最初に実行される関数
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	clear_flg = false;

}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	//最後に実行される関数
}

void GameMain::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		clear_flg = true;
	}
}

void GameMain::Draw()
{
	DrawStringToHandle(400, 300, "ゲームメイン", 0xFF5F0F, title_font);
}
