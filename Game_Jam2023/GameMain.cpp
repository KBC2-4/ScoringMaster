#include "GameMain.h"
#include "PadInput.h"

#define QUESTION_NUM 32

GameMain::GameMain() {
	//最初に実行される関数
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	question_font = CreateFontToHandle("ＭＳ Ｐゴシック", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	time_font = CreateFontToHandle("メイリオ", 40, 10, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	student_font = LoadFontDataToHandle("Resource/Fonts/Student.dft", 1);
	student_dis_font = CreateFontToHandle(NULL, 40, 2, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	if ((background_image = LoadGraph("Resource/Images/gamemain.png")) == -1);
	if ((paper_image = LoadGraph("Resource/Images/paper.png")) == -1);

	wrong_se = LoadSoundMem("Resource/Sounds/wrong.mp3");
	correct_se = LoadSoundMem("Resource/Sounds/correct.mp3");
	background_music = LoadSoundMem("Resource/Sounds/bgm.mp3");

	clear_flg = false;

	time_limit = 0;

	start_count = GetNowCount() + 1000 * 100;

	anim_count = 60;
	size_anim_count = 0;
	answer_anim_count = -1;
	addtime_anim_count = -1;

	next_question = false;
	next_question_num = GetRand(QUESTION_NUM - 1);
	question_num.push_back(next_question_num);

	clear_count = 0;

	answer_correct = GetRand(1);

	question = new Question();

	//解答を未回答に初期化
	answer = GameMain::Answer::unanswered;

	PlaySoundMem(background_music, DX_PLAYTYPE_LOOP, TRUE);
}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(time_font);
	DeleteFontToHandle(question_font);
	DeleteFontToHandle(student_font);
	DeleteFontToHandle(student_dis_font);
	DeleteGraph(background_image);
	DeleteGraph(paper_image);
	DeleteSoundMem(wrong_se);
	DeleteSoundMem(correct_se);
	StopSoundMem(background_music);
	DeleteSoundMem(background_music);
	delete question;
	//最後に実行される関数
}

void GameMain::Update()
{

	////デバッグ
	////問題確認用
	//if (count < 20) { count++; }
	//if (count == 20) {
	//	count = 0;
	//	if (CheckHitKey(KEY_INPUT_RIGHT)) { question_count++; }
	//	if (CheckHitKey(KEY_INPUT_LEFT)) { if (question_count > 0) { question_count--; } }
	//}

	//制限時間の経過
	time_limit = GetNowCount() - start_count;

	//制限時間が0以下になった場合、リザルト画面へ
	if (time_limit > 0) { clear_flg = true; }

	//3門クリアした時
	if (question_count > QUESTION_NUM) {
		clear_flg = true;
	}


	slide_animation(next_question);

	if (size_anim_count < 60 && anim_count < 0) {
		size_anim_count++;

	}

	if (answer_anim_count > -1 && answer_anim_count < 255) { answer_anim_count += 8.5f; }
	if (addtime_anim_count > -1 && addtime_anim_count < 255) { addtime_anim_count += 8.5f; }

	if (next_question == false) {

		if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			if (answer_correct == 0) { answer = GameMain::Answer::wrong; }
			else { answer = GameMain::Answer::correct; }
		}
		else if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			if (answer_correct == 1) { answer = GameMain::Answer::wrong; }
			else { answer = GameMain::Answer::correct; }
		}


		//不正解だった場合、制限時間を減算させる
		if (answer == GameMain::Answer::wrong) {
			start_count -= 1000 * 5;
			PlaySoundMem(wrong_se, DX_PLAYTYPE_BACK, TRUE);
		}
		//正解だった場合、clear_countを加算する
		else if (answer == GameMain::Answer::correct) { 
			start_count += 1000 * 1;
			clear_count++; 
			PlaySoundMem(correct_se, DX_PLAYTYPE_BACK, TRUE);
		}

		//BボタンまたはAボタンを押した時
		if ((PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON)
			|| PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			next_question = true;
			//正誤のアニメーションを開始
			answer_anim_count = 0;
			//タイム加減算のアニメーションを開始
			addtime_anim_count = 0;
		}
	}

}

void GameMain::Draw()
{

	DrawGraph(0, 0, background_image, FALSE);

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
		//DrawBoxAA(canvas_x1, canvas_y1, canvas_x2, canvas_y2, 0xFFFFFF, TRUE);
		DrawExtendGraph(canvas_x1, canvas_y1, canvas_x2, canvas_y2, paper_image, TRUE);


		DrawExtendFormatString2ToHandle(canvas_x1 + 280, canvas_y1 + 260, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, 0xFF0000, 0xFFFFFF, title_font, "%2d問目", question_count + 1);

		//問題 描画
		DrawExtendFormatString2ToHandle(canvas_x1 - 200 + GetDrawCenterX(question->GetQuestion(next_question_num).c_str(), question_font), canvas_y1 + 400, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, 0xF5A000, 0xEFBD00, question_font, "%s", question->GetQuestion(next_question_num).c_str());

		//生徒の解答 描画
		DrawExtendStringToHandle(canvas_x1 + 80 + size_anim_count * 5, 570, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, "生徒の答え", 0xFFFFFF, student_dis_font, 0x000000);
		int char_num = GetDrawFormatStringWidthToHandle(student_font, question->GetAnswer(next_question_num, answer_correct).c_str());
		for (int i = 0; i < char_num / 20; i++) {
			DrawExtendStringToHandle(canvas_x1 + 300 + i * 20 + size_anim_count * 5, 580, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, "_", 0xFFFFFF, student_dis_font, 0x000000);
			//DrawLineAA(canvas_x1 + 300, 640, canvas_x1 + 300 + i * 20, 580, 0x000000, size_anim_count * 0.01 + 0.8);
		}

		DrawExtendFormatString2ToHandle(canvas_x1 + 300 + size_anim_count * 5, 570, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, 0x00D64E, 0x00584E, student_font, "%6s", question->GetAnswer(next_question_num, answer_correct).c_str());
	}

	//正誤表示の座標
	int x = 660;
	int y = 400;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(answer_anim_count));
	//正誤表示
	switch (answer)
	{

		/*case GameMain::Answer::unanswered:
			break;*/
	case GameMain::Answer::wrong:

		{//キャンバス
			float canvas_x1 = x;
			float canvas_x2;
			float canvas_y1 = y;
			float canvas_y2;
			DrawCircleAA(canvas_x1 - 200, canvas_y1 - 200, 25, 30, 0x4171bb, 50.0F);
			DrawCircleAA(canvas_x1 + 200, canvas_y1 + 200, 25, 30, 0x4171bb, 50.0F);
			DrawCircleAA(canvas_x1 + 200, canvas_y1 - 200, 25, 30, 0x4171bb, 50.0F);
			DrawCircleAA(canvas_x1 - 200, canvas_y1 + 200, 25, 30, 0x4171bb, 50.0F);
			DrawLineAA(canvas_x1 - 200, canvas_y1 - 200, canvas_x1 + 200, canvas_y1 + 200, 0x4171bb, 50.0F);
			DrawLineAA(canvas_x1 + 200, canvas_y1 - 200, canvas_x1 - 200, canvas_y1 + 200, 0x4171bb, 50.0F);

			DrawStringToHandle(1000, 90, "- 5.000", 0xFF0000,time_font);
		}
		break;
	case GameMain::Answer::correct:
		DrawCircleAA(x, y, 200, 30, 0xd2672f, FALSE, 50.0F);
		DrawStringToHandle(1000, 90, "+ 1.000", 0xFFFF00,time_font);
		break;
	default:
		break;
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	{//HUD
		DrawFormatString2ToHandle(1000, 50, 0x4E75ED, 0xFFFFFF, time_font, "%5d.%.3d", -time_limit / 1000, -time_limit % 1000);
		DrawFormatString2ToHandle(50, 50, 0xFF0000, 0xFFFFFF, time_font, "正解数：%2d", clear_count);
		DrawStringToHandle(600 + 150, 655, "×", 0xFFFFFF, question_font, 0x000000);
		DrawCircleAA(600 + 123, 685, 30, 20, 0x5AFF19, 1);
		DrawStringToHandle(600 + 103	, 654, "A",  0x16F002, question_font, 0x000000);

		DrawStringToHandle(700 - 160, 655, "○", 0xFFFFFF, question_font, 0x000000);
		DrawCircleAA(700 - 199, 685, 30, 20, 0xff0000, 1);
		DrawStringToHandle(700 - 217, 654, "B", 0xEB7415, question_font, 0x000000);
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
				//問題のカウントを加算
				++question_count;
				//生徒の正誤を乱数でランダムで取得
				answer_correct = GetRand(1);
				//まだ出されていない問題を次に出す
				next_question_num = GetRand(QUESTION_NUM - 1);

				while (std::find(question_num.begin(), question_num.end(), next_question_num) != question_num.end()) {

					next_question_num = GetRand(QUESTION_NUM - 1);

					//printfDx("next_question_num:%d", next_question_num);
					////デバッグ
					//for (int num : question_num) {
					//	printfDx("[%d]", num);

								//解答をリセット
					
				}
				//解答状況を未回答にリセット
				answer = GameMain::Answer::unanswered;
				//次の問題番号をプッシュ
				question_num.push_back(next_question_num);
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
