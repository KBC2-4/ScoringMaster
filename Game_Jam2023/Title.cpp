#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"

Title::Title() {

	{
		//タイトル画像の読込
		if ((titleimg = LoadGraph("Resource/Images/title.png")) == -1);

	}
	
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	btitle_font = CreateFontToHandle("メイリオ", 40, 20,DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	input_margin = 0;
}

Title::~Title() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(btitle_font);
}

void Title::Update()
{

	if (input_margin <= 20) { ++input_margin; }

	if (PAD_INPUT::GetPadThumbLY() < -2000 && input_margin >= 20) {
		if (++menunumber > 1) menunumber = 0;
		input_margin = 0;
	}

	if (PAD_INPUT::GetPadThumbLY() > 2000 && input_margin >= 20) {
		if (--menunumber < 0) menunumber = 1;
		input_margin = 0;
	}
}

void Title::Draw()
{

	DrawGraph(0, 0, titleimg, FALSE);

	if (menunumber == 0) 
		DrawStringToHandle(200, 500, "スタート", 0xFF0000, btitle_font);
	else {
		DrawStringToHandle(200, 500, "スタート", 0x0000FF, btitle_font);
	}
	if (menunumber == 1)
		DrawStringToHandle(200, 600, "終了", 0xFF0000, btitle_font);
	else {
		DrawStringToHandle(200, 600, "終了", 0x0000FF, btitle_font);
	}

	menu = menunumber * 100;
	
}
