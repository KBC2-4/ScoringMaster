#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//最初に実行される関数
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	time_font = CreateFontToHandle("メイリオ", 40,1);
	 

	clear_flg = false;

	
	start_count = GetNowCount() + 1000 * 60;

}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	//最後に実行される関数
}

void GameMain::Update()
{
	time_limit =  GetNowCount() - start_count;

	//Bボタンを押した時
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		clear_flg = true;
	}
}

void GameMain::Draw()
{
	DrawStringToHandle(400, 300, "ゲームメイン", 0xFF5F0F, title_font);
	DrawFormatString2(1000, 50, 0xFF0000, 0xFFFFFF, "%5d.%.3d", -time_limit / 1000, -time_limit % 1000);
}
