#pragma once
class GameMain
{
private:
	//�Q�[���N���A���̃t���O
	int title_font;
	bool clear_flg;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();

	bool GetClearFlg(void) const { return clear_flg; }
};

