#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"

Title::Title() {

	{
		//タイトル画像の読込
		if ((titleimg = LoadGraph("str_image.jpg")) == -1);

	}
	
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	btitle_font = CreateFontToHandle("NULL", 40, 20);

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

	DrawStringToHandle(400, 100, "タイトル", 0x000000, title_font);
	DrawStringToHandle(400, 500, "スタート", 0x0000FF, btitle_font);
	DrawStringToHandle(400, 550, "終了", 0x0000FF, btitle_font);
	

	menu = menunumber * 52;
	DrawTriangle(350, 500 + menu, 350, 540 + menu, 390, 520 + menu, GetColor(255, 0, 0), TRUE);
	
}
