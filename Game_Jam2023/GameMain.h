#pragma once
#include "question.h"

class GameMain
{
private:
	//�t�H���g�n���h��
	int title_font;
	int time_font;
	int student_font;
	int question_font;

	int background_image;

	//�Q�[���N���A���̃t���O
	bool clear_flg;
	//��������
	int time_limit;
	//�Q�[���J�n���̃J�E���g
	int start_count;
	//�A�j���[�V�����p�J�E���g
	int anim_count;
	int size_anim_count;

	//���̖��ֈڍs����t���O
	bool next_question;

	//���ԍ�
	short question_num;
	//���k�̉𓚂̐���
	bool answer_correct;


	//�I�u�W�F�N�g�ϐ�
	Question* question;

public:
	GameMain();
	~GameMain();
	void Update();
	void Draw();
	/// <summary>
	/// �X���C�h�A�j���[�V����
	/// </summary>
	/// <param name="end">�J�n��(�E���獶�ɃX���C�h)��false, �I������true</param>
	void slide_animation(bool end);

	bool GetClearFlg(void) const { return clear_flg; }
	/// <summary>
	/// �����̕`�悷��X���W�����S�ɂȂ�X���W���擾����B
	/// </summary>
	/// <param name="string">�`�悷�镶����</param>
	/// <param name="font_handle">�`��Ɏg�p����t�H���g�n���h��(�����͖���0�̏ꍇ�̓f�t�H���g�t�H���g�n���h�����g�p</param>
	/// <param name="margin">������X���W�ɊԊu���󂯂�l</param>
	int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0)const;
};

