#include "Result.h"
#include "PadInput.h"

Result::Result(short clear_count) {
	//最初に実行される関数
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	nextscene = false;
	this->clear_count = clear_count;
}

Result::~Result() {
	//最後に実行される関数
	DeleteFontToHandle(title_font);
}

void Result::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		nextscene = true;
	}
}

void Result::Draw()
{
	DrawBox(300, 200, 1000, 500, 0xFFFFFF, FALSE);
	DrawFormatString2ToHandle(400, 300, 0xFFFFFF, 0x000000, title_font, "%2d問正解");
}
