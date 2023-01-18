#include "Result.h"
#include "PadInput.h"

Result::Result() {
	//�ŏ��Ɏ��s�����֐�
	title_font = CreateFontToHandle("���C���I", 120, 1);
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
	
}
