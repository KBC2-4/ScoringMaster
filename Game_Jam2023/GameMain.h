#pragma once
#include "question.h"

class GameMain
{
private:
	//フォントハンドル
	int title_font;
	int time_font;
	int student_font;
	int question_font;

	int background_image;

	//ゲームクリア時のフラグ
	bool clear_flg;
	//制限時間
	int time_limit;
	//ゲーム開始時のカウント
	int start_count;
	//アニメーション用カウント
	int anim_count;
	int size_anim_count;

	//次の問題へ移行するフラグ
	bool next_question;

	//問題番号
	short question_num;
	//生徒の解答の正誤
	bool answer_correct;


	//オブジェクト変数
	Question* question;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();
	/// <summary>
	/// スライドアニメーション
	/// </summary>
	/// <param name="end">開始時(右から左にスライド)はfalse, 終了時はtrue</param>
	void slide_animation(bool end);

	bool GetClearFlg(void) const { return clear_flg; }
	/// <summary>
	/// 文字の描画するX座標が中心になるX座標を取得する。
	/// </summary>
	/// <param name="string">描画する文字列</param>
	/// <param name="font_handle">描画に使用するフォントハンドル(未入力又は0の場合はデフォルトフォントハンドルを使用</param>
	/// <param name="margin">中央のX座標に間隔を空ける値</param>
	int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0)const;
};

