#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"

Title::Title() {

	{
		select_se = LoadSoundMem("Resource/Sounds/select.mp3");
		enter_se = LoadSoundMem("Resource/Sounds/enter.mp3");
		background_music = LoadSoundMem("Resource/Sounds/bgm.mp3");

		//タイトル画像の読込
		if ((titleimg = LoadGraph("Resource/Images/title.png")) == -1);

	}
	
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	btitle_font = CreateFontToHandle("メイリオ", 40, 20,DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	input_margin = 0;

	PlaySoundMem(background_music, DX_PLAYTYPE_LOOP, TRUE);
}

Title::~Title() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(btitle_font);
	DeleteGraph(titleimg);
	DeleteSoundMem(enter_se);
	DeleteSoundMem(select_se);
	StopSoundMem(background_music);
	DeleteSoundMem(background_music);
}

void Title::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		PlaySoundMem(enter_se, DX_PLAYTYPE_BACK, TRUE);
	}

	if (input_margin <= 20) { ++input_margin; }

	if (PAD_INPUT::GetPadThumbLY() < -2000 && input_margin >= 20) {
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (++menunumber > 1) menunumber = 0;
		input_margin = 0;
	}

	if (PAD_INPUT::GetPadThumbLY() > 2000 && input_margin >= 20) {
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
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
