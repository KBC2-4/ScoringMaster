#pragma once
class GameMain
{
private:
	//�t�H���g�n���h��
	int title_font, time_font, student_font;
	//�Q�[���N���A���̃t���O
	bool clear_flg;
	//��������
	int time_limit;
	//�Q�[���J�n���̃J�E���g
	int start_count;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();

	bool GetClearFlg(void) const { return clear_flg; }
};

