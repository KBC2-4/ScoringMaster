#pragma once
class GameMain
{
private:
	//フォントハンドル
	int title_font, time_font, student_font;
	//ゲームクリア時のフラグ
	bool clear_flg;
	//制限時間
	int time_limit;
	//ゲーム開始時のカウント
	int start_count;
	//アニメーション用カウント
	int anim_count;
	int size_anim_count;

	bool next_question;


	short question_num;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();

	void slide_animation(bool end);

	bool GetClearFlg(void) const { return clear_flg; }
};

