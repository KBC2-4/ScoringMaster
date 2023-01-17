#pragma once
class GameMain
{
private:
	//ゲームクリア時のフラグ
	int title_font;
	bool clear_flg;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();

	bool GetClearFlg(void) const { return clear_flg; }
};

