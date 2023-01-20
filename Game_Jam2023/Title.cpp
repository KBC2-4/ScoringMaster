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
	guid_font = CreateFontToHandle("ＭＳ Ｐゴシック", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	input_margin = 0;
	menunumber = 0;
	next_scene = NextScene::NONE;
	PlaySoundMem(background_music, DX_PLAYTYPE_LOOP, TRUE);
}

Title::~Title() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(btitle_font);
	DeleteFontToHandle(guid_font);
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

	next_scene = static_cast<NextScene>(menunumber + 1);

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

	//DrawStringToHandle(600 + 150, 655, "×", 0xFFFFFF, question_font, 0x000000);
	//DrawCircleAA(600 + 123, 685, 30, 20, 0x5AFF19, 1);
	//DrawStringToHandle(600 + 103, 654, "A", 0x16F002, question_font, 0x000000);

	const int joystick_x = 340;
	const int joystick_y = 670;

	DrawOvalAA(joystick_x, joystick_y + 6, 18, 10, 20, 0x000000, TRUE);
	DrawBoxAA(joystick_x - 5, joystick_y, joystick_x + 7, joystick_y + 23, 0x000000, TRUE);
	DrawOvalAA(joystick_x, joystick_y + 23, 22, 8, 20, 0x000000, TRUE);
	DrawString(joystick_x - 2, joystick_y - 2, "L", 0xFFFFFF);
	DrawStringToHandle(joystick_x + 30, 668, "移動", 0xFFFFFF, guid_font, 0x000000);

	const int b_x = 1000;
	const int b_y = 685;

	DrawStringToHandle(b_x - 180, b_y  - 20, "決定", 0xFFFFFF, guid_font, 0x000000);
	DrawCircleAA(b_x - 199, b_y, 20, 20, 0xff0000, 1);
	DrawStringToHandle(b_x - 210, b_y - 21, "B", 0xEB7415, guid_font, 0x000000);

	menu = menunumber * 100;
	
}
