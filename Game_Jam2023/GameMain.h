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
	//�A�j���[�V�����p�J�E���g
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

