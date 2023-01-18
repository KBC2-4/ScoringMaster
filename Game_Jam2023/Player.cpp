#include "Player.h"
#include"PadInput.h"



Player::Player() {
	i = 0;
	j = 0;
	
	qr = QRand();
	ar = ARand();
	
}

Player::~Player() {

}

int Player::QRand() {
	i = GetRand(2);

	if (i == 0)return 0;
	if (i == 1)return 1;
	if (i == 2)return 2;

}

int Player::ARand() {
	j = GetRand(1);

	if (j == 0)return 0; //����
	if (j == 1)return 1; //�s����

}

void Player::Update()
{
	
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		qr = QRand();
		ar = ARand();
	}

	//A�{�^�����������Ƃ�(�񓚂��Z)
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::DOWN) {
		if (ar == 1) {
			DrawString(150, 150,"����", 0xffffff);
		}
		else if (ar == 0) {
			DrawString(150, 150, "�s����", 0xffffff);
		}
	}
	//B�{�^�����������Ƃ�(�񓚂��~)
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::DOWN) {
		if (ar == 0) {
			DrawString(150, 150,"����",0xffffff);
		}
		else if (ar == 1) {
			DrawString(150, 150, "�s����", 0xffffff);
		}
	}
}

void Player::Draw()
{
	DrawFormatString(100, 100, 0xffffff, "���:%s",q[qr]);
	DrawFormatString(120, 120, 0xffffff, "����:%s",a[qr][ar]);
}
