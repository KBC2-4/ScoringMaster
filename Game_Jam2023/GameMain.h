#pragma once
class GameMain
{
private:

	int title_font;
	//�Q�[���N���A���̃t���O
	bool clear_flg;
	//��������
	int time_limit;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();

	bool GetClearFlg(void) const { return clear_flg; }
};

