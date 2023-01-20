#include "Result.h"
#include "PadInput.h"

Result::Result(short clear_count) {
	//最初に実行される関数

	enter_se = LoadSoundMem("Resource/Sounds/enter.mp3");
	result_bgm = LoadSoundMem("Resource/Sounds/result.mp3");
	
	title_font = CreateFontToHandle("メイリオ", 120, 1,DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	bottun_font = CreateFontToHandle("メイリオ", 30, 1);
	rank_font = CreateFontToHandle("メイリオ", 200, 10,DX_FONTTYPE_ANTIALIASING_EDGE_4X4,-1,10);
	guid_font= CreateFontToHandle("ＭＳ Ｐゴシック", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	gcrown_img = LoadGraph("Resource/Images/gold.png");
	scrown_img = LoadGraph("Resource/Images/silver.png");
	bcrown_img = LoadGraph("Resource/Images/bronz.png");
	if ((background_image = LoadGraph("Resource/Images/gamemain.png")) == -1);
	

	nextscene = false;
	
	this->clear_count = clear_count;

	if (this->clear_count >= 20) {
		rank = Rank::S;
	}
	else if (this->clear_count >= 15) {
		rank = Rank::A;
	}
	else if (this->clear_count >= 10) {
		rank = Rank::B;
	}
	else if (this->clear_count >= 5) {
		rank = Rank::C;
	}
	else if (this->clear_count >= 3) {
		rank = Rank::D;
	}
	else if (this->clear_count >= 0) {
		rank = Rank::E;
	}

	PlaySoundMem(result_bgm, DX_PLAYTYPE_LOOP, TRUE);

	anim_timer = 0;
}

Result::~Result() {
	//最後に実行される関数
	DeleteFontToHandle(title_font);
	DeleteSoundMem(enter_se);
	DeleteFontToHandle(bottun_font);
	StopSoundMem(result_bgm);
	DeleteSoundMem(result_bgm);
}

void Result::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		PlaySoundMem(enter_se, DX_PLAYTYPE_BACK, TRUE);
		nextscene = true;
	}

	if (anim_timer < 180) { anim_timer++; }
}

void Result::Draw()
{

	DrawGraph(0, 0, background_image, FALSE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anim_timer * 1.41);

	if (anim_timer > 30) {
		DrawFormatString2ToHandle(395, 500, 0xF5FF00, 0xFFFFFF, title_font, "%2d問正解", clear_count);
	}
	if (anim_timer > 100) {

		int rank_x = 565;
		int rank_y = 270;

		switch (rank)
		{
		case Result::Rank::S:
			DrawStringToHandle(rank_x, rank_y, "S", 0xe1bb2b, rank_font, 0xFFFFFF);
			DrawGraph(490, 40, gcrown_img, TRUE);
			break;
		case Result::Rank::A:
			DrawStringToHandle(rank_x, rank_y, "A", 0xc7c9cb, rank_font, 0xFFFFFF);
			DrawGraph(490, 40, scrown_img, TRUE);
			break;
		case Result::Rank::B:
			DrawStringToHandle(rank_x, rank_y, "B", 0xc4b790, rank_font, 0x6a624c);
			DrawGraph(490, 40, bcrown_img, TRUE);
			break;
		case Result::Rank::C:
			DrawStringToHandle(rank_x, rank_y - 100, "C", 0x00FF00, rank_font, 0xFFFFFF);
			break;
		case Result::Rank::D:
			DrawStringToHandle(rank_x, rank_y - 100, "D", 0xff0000, rank_font, 0xFFFFFF);
			break;
		case Result::Rank::E:
			DrawStringToHandle(rank_x, rank_y - 100, "E", 0xC0C0C0, rank_font, 0xFFFFFF);
			break;
		default:
			break;
		}
	}
	if(anim_timer >= 180) {

		int button_x = 670;
		DrawStringToHandle(button_x - 160, 655, "タイトルへ戻る", 0xFFFFFF, guid_font, 0x000000);
		DrawCircleAA(button_x - 199, 685, 30, 20, 0xff0000, 1);
		DrawStringToHandle(button_x - 217, 654, "B", 0xEB7415, guid_font, 0x000000);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
