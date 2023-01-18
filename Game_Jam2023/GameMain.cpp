#include "GameMain.h"
#include "PadInput.h"

GameMain::GameMain() {
	//�ŏ��Ɏ��s�����֐�
	title_font = CreateFontToHandle("���C���I", 120, 1);
	question_font = CreateFontToHandle("�l�r �o�S�V�b�N", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	time_font = CreateFontToHandle("���C���I", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	student_font = LoadFontDataToHandle("Resource/Fonts/Student.dft", 1);

	clear_flg = false;

	time_limit = 0;

	start_count = GetNowCount() + 1000 * 60;

	anim_count = 60;
	size_anim_count = 0;

	next_question = false;
	question_num = 0;

	answer_correct = GetRand(1);

	question = new Question();
}

GameMain::~GameMain() {
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(time_font);
	DeleteFontToHandle(question_font);
	DeleteFontToHandle(student_font);
	delete question;
	//�Ō�Ɏ��s�����֐�
}

void GameMain::Update()
{
	//�������Ԃ̌o��
	time_limit = GetNowCount() - start_count;

	//�������Ԃ�0�ȉ��ɂȂ����ꍇ�A���U���g��ʂ�
	if (time_limit > 0) { clear_flg = true; }

	//3��N���A������
	if (question_num > 15) {
		clear_flg = true;
	}

	
	slide_animation(next_question);

	if (size_anim_count < 60 && anim_count < 0) {
		size_anim_count++;

	}

	if (next_question == false) {

		if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			;;
		}
		else if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			;;
		}

		//B�{�^���܂���A�{�^������������
		if ((PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON)
			|| PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
			next_question = true;
		}
	}

}

void GameMain::Draw()
{

	{//�L�����o�X
		int canvas_x1;
		int canvas_x2;
		int canvas_y1;
		int canvas_y2;
		short speed = 5;

		canvas_x1 = 490 - size_anim_count * speed + anim_count * 15;
		canvas_y1 = 150 - size_anim_count * speed;
		canvas_x2 = 820 + size_anim_count * speed + anim_count * 15;
		canvas_y2 = 650 + size_anim_count * speed;
		//�L�����o�X �`��
		DrawBoxAA(canvas_x1, canvas_y1, canvas_x2, canvas_y2, 0xFFFFFF, TRUE);


		DrawExtendFormatString2ToHandle(canvas_x1 + 320, canvas_y1 + 260, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4, 0xFF0000, 0xFFFFFF, title_font, "%d���", question_num + 1);

		//��� �`��
		DrawExtendFormatString2ToHandle(canvas_x1 - 200 + GetDrawCenterX(question->GetQuestion(question_num).c_str(), question_font), canvas_y1 + 400, size_anim_count * 0.01 + 0.4, size_anim_count * 0.01 + 0.4,  0xFFFFFF, 0x000000, question_font, "%s", question->GetQuestion(question_num).c_str());

		//���k�̉� �`��
		DrawExtendFormatString2ToHandle(canvas_x1 + 200 + size_anim_count * 5, 570, size_anim_count * 0.01 + 1.0, size_anim_count * 0.01 + 1.0, 0xFFFFFF, 0x00FFFF, student_font, "%s", question->GetAnswer(question_num, answer_correct).c_str());
	}


	{//HUD
		DrawFormatString2ToHandle(1000, 50, 0xFF0000, 0xFFFFFF, time_font, "%5d.%.3d", -time_limit / 1000, -time_limit % 1000);
	}
}

void GameMain::slide_animation(bool end)
{
	if (!end) {
		if (anim_count >= 0) {
			anim_count--;
		}
	}
	else {
		if (anim_count > -90) {
			anim_count--;
			if (anim_count == -90) {
				anim_count = 60;
				next_question = false; 
				//����؂�ւ�
				++question_num;
				//���k�̐���𗐐��Ń����_���Ŏ擾
				answer_correct = GetRand(1);
			}
		}
	}
}


int GameMain::GetDrawCenterX(const char* string, int font_handle, int margin)const {

	//��ʕ�
	const int screenX = 1280;

	if (margin >= screenX || margin <= -screenX) {
		margin = 0;
	}

	if (font_handle == 0) {
		font_handle = DX_DEFAULT_FONT_HANDLE;
	}


	const int w = screenX / 2 + margin - (GetDrawFormatStringWidthToHandle(font_handle, string) / 2);
	return w;
}
