#include "Result.h"
#include "PadInput.h"

Result::Result(short clear_count) {
	//�ŏ��Ɏ��s�����֐�
	
	title_font = CreateFontToHandle("���C���I", 120, 1);
	bottun_font = CreateFontToHandle("���C���I", 60, 1);
	
	nextscene = false;
}

Result::~Result() {
	//�Ō�Ɏ��s�����֐�
	DeleteFontToHandle(title_font);
}

void Result::Update()
{
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		nextscene = true;
	}
}

void Result::Draw()
{

	DrawBox(300, 200, 1000, 500, 0xFFFFFF, FALSE);
	DrawFormatString2ToHandle(400, 300, 0xFFFFFF, 0x000000, title_font, "%2d�␳��");
	DrawStringToHandle(300, 600, "B�{�^���Ń^�C�g���֖߂�", 0xFF0000, bottun_font);
}
