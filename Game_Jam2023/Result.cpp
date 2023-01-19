#include "Result.h"
#include "PadInput.h"

Result::Result(short clear_count) {
	//最初に実行される関数

	enter_se = LoadSoundMem("Resource/Sounds/select.mp3");
	
	title_font = CreateFontToHandle("メイリオ", 120, 1);
	bottun_font = CreateFontToHandle("メイリオ", 30, 1);
	rank_font = CreateFontToHandle("メイリオ", 60, 10);

	gcrown_img = LoadGraph("Resource/Images/gold.png");
	scrown_img = LoadGraph("Resource/Images/silver.png");
	bcrown_img = LoadGraph("Resource/Images/bronz.png");
	if ((background_image = LoadGraph("Resource/Images/gamemain.png")) == -1);
	

	nextscene = false;

	this->clear_count = clear_count;

	if (clear_count >= 20) {
		rank = Rank::S;
	}
	else if (clear_count >= 15) {
		rank = Rank::A;
	}
	else if (clear_count >= 10) {
		rank = Rank::B;
	}
	else if (clear_count >= 5) {
		rank = Rank::C;
	}
	else if (clear_count >= 3) {
		rank = Rank::D;
	}
	else if (clear_count >= 0) {
		rank = Rank::E;
	}
}

Result::~Result() {
	//最後に実行される関数
	DeleteFontToHandle(title_font);

	DeleteGraph(background_image);
}

void Result::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		PlaySoundMem(enter_se, DX_PLAYTYPE_BACK, TRUE);
		nextscene = true;
	}
}

void Result::Draw()
{

	DrawGraph(0, 0, background_image, FALSE);


	DrawBox(290, 400, 990, 700, 0xFFFFFF, FALSE);
	DrawBox(560, 230, 720, 360, 0xFFFFFF, FALSE);
	DrawFormatString2ToHandle(400, 500, 0xFFFFFF, 0x000000, title_font, "%2d問正解", clear_count);
	DrawStringToHandle(300, 600, "Bボタンでタイトルへ戻る", 0xFF0000, bottun_font);

	switch (rank)
	{
	case Result::Rank::S:
		DrawStringToHandle(615, 325, "S", 0xe1bb2b, rank_font);
		DrawGraph(490, 40, gcrown_img, TRUE);
		break;
	case Result::Rank::A:
		DrawStringToHandle(615, 325, "A", 0xc7c9cb, rank_font);
		DrawGraph(490, 40, scrown_img, TRUE);
		break;
	case Result::Rank::B:
		DrawStringToHandle(615, 325, "B", 0xc4b790, rank_font);
		DrawGraph(490, 40, bcrown_img, TRUE);
		break;
	case Result::Rank::C:
		DrawStringToHandle(615, 325, "C", 0x00FF00, rank_font);
		DrawGraph(490, 40, gcrown_img, TRUE);
		break;
	case Result::Rank::D:
		DrawStringToHandle(615, 325, "D", 0xff0000, rank_font);
		DrawGraph(490, 40, gcrown_img, TRUE);
		break;
	case Result::Rank::E:
		DrawStringToHandle(615, 325, "E", 0xC0C0C0, rank_font);
		DrawGraph(490, 40, gcrown_img, TRUE);
		break;
	default:
		break;
	}
}
