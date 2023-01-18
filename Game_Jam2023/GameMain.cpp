#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//最初に実行される関数
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	time_font = CreateFontToHandle("メイリオ", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	student_font = LoadFontDataToHandle("Resource/Fonts/Student.dft", 1);

	clear_flg = false;

	time_limit = 0;

	start_count = GetNowCount() + 1000 * 60;

	anim_count = 60;
	size_anim_count = 0;

	next_question = false;
	question_num = 0;

}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(time_font);
	DeleteFontToHandle(student_font);
	//最後に実行される関数
}

void GameMain::Update()
{
	//制限時間の経過
	time_limit = GetNowCount() - start_count;

	//制限時間が0以下になった場合、リザルト画面へ
	if (time_limit > 0) { clear_flg = true; }

	//3門クリアした時
	if (question_num > 3) {
		clear_flg = true;
	}

	
	slide_animation(next_question);

	if (size_anim_count < 60 && anim_count < 0) {
		size_anim_count++;

	}

	if (next_question == false) {

		if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			;;
		}
		else if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			;;
		}

		//BボタンまたはAボタンを押した時
		if ((PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON)
			|| PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			next_question = true;
			++question_num;
		}
	}

}

void GameMain::Draw()
{

	{//キャンバス
		int canvas_x1;
		int canvas_x2;
		int canvas_y1;
		int canvas_y2;
		short speed = 5;

		canvas_x1 = 490 - size_anim_count * speed + anim_count * 15;
		canvas_y1 = 150 - size_anim_count * speed;
		canvas_x2 = 820 + size_anim_count * speed + anim_count * 15;
		canvas_y2 = 650 + size_anim_count * speed;

		DrawBoxAA(canvas_x1, canvas_y1, canvas_x2, canvas_y2, 0xFFFFFF, TRUE);

		DrawExtendStringToHandle(canvas_x1 + 200 + size_anim_count * 5, 570, size_anim_count * 0.01 + 1.0, size_anim_count * 0.01 + 1.0, "織田信長", 0xFFFFFF, student_font, 0x00FFFF);
	}


	{//HUD
		DrawStringToHandle(320, 300, "ゲームメイン", 0xFF5F0F, title_font);
		DrawFormatString2ToHandle(1000, 50, 0xFF0000, 0xFFFFFF, time_font, "%5d.%.3d", -time_limit / 1000, -time_limit % 1000);
		DrawFormatString2ToHandle(80, 50, 0xFF0000, 0xFFFFFF, time_font, "%d問目", question_num + 1);
	}
}

void GameMain::slide_animation(bool end)
{
	if (!end) {
		if (anim_count >= 0) {
			anim_count--;

		}
	}
	else {
		if (anim_count > -90) {
			anim_count--;
			if (anim_count == -90) { anim_count = 60; next_question = false; }
		}
	}
}
