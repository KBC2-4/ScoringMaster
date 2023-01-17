#pragma once
class GameMain
{
private:

	int title_font;
	//ゲームクリア時のフラグ
	bool clear_flg;
	//制限時間
	int time_limit;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();

	bool GetClearFlg(void) const { return clear_flg; }
};

