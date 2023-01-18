#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//最初に実行される関数
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	question_font = CreateFontToHandle("ＭＳ Ｐゴシック", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	time_font = CreateFontToHandle("メイリオ", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	student_font = LoadFontDataToHandle("Resource/Fonts/Student.dft", 1);

	clear_flg = false;

	time_limit = 0;

	start_count = GetNowCount() + 1000 * 60;

	anim_count = 60;
	size_anim_count = 0;

	next_question = false;
	question_num = 0;

	answer_correct = GetRand(1);

	question = new Question();
}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(time_font);
	DeleteFontToHandle(question_font);
	DeleteFontToHandle(student_font);
	delete question;
	//最後に実行される関数
}

void GameMain::Update()
{
	//制限時間の経過
	time_limit = GetNowCount() - start_count;

	//制限時間が0以下になった場合、リザルト画面へ
	if (time_limit > 0) { clear_flg = true; }

	//3門クリアした時
	if (question_num > 15) {
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
		//キャンバス 描画
		DrawBoxAA(canvas_x1, canvas_y1, canvas_x2, canvas_y2, 0xFFFFFF, TRUE);


		DrawExtendFormatString2ToHandle(canvas_x1 + 320, canvas_y1 + 260, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, 0xFF0000, 0xFFFFFF, title_font, "%d問目", question_num + 1);

		//問題 描画
		DrawExtendFormatString2ToHandle(canvas_x1 - 200 + GetDrawCenterX(question->GetQuestion(question_num).c_str(), question_font), canvas_y1 + 400, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4,  0xFFFFFF, 0x000000, question_font, "%s", question->GetQuestion(question_num).c_str());

		//生徒の解答 描画
		DrawExtendFormatString2ToHandle(canvas_x1 + 200 + size_anim_count * 5, 570, size_anim_count * 0.01 + 1.0, size_anim_count * 0.01 + 1.0, 0xFFFFFF, 0x00FFFF, student_font, "%s", question->GetAnswer(question_num, answer_correct).c_str());
	}


	{//HUD
		DrawFormatString2ToHandle(1000, 50, 0xFF0000, 0xFFFFFF, time_font, "%5d.%.3d", -time_limit / 1000, -time_limit % 1000);
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
			if (anim_count == -90) {
				anim_count = 60;
				next_question = false; 
				//問題を切り替え
				++question_num;
				//生徒の正誤を乱数でランダムで取得
				answer_correct = GetRand(1);
			}
		}
	}
}


int GameMain::GetDrawCenterX(const char* string, int font_handle, int margin)const {

	//画面幅
	const int screenX = 1280;

	if (margin >= screenX || margin <= -screenX) {
		margin = 0;
	}

	if (font_handle == 0) {
		font_handle = DX_DEFAULT_FONT_HANDLE;
	}


	const int w = screenX / 2 + margin - (GetDrawFormatStringWidthToHandle(font_handle, string) / 2);
	return w;
}
