#pragma once
class Player
{
private:
	//�N���X���Ŏg���ϐ�
	const char * q[5] = { "2+3", "5*3", "6/3" };  //���
	
	const char * a[3][2] = {//����([����][�듚])
		{"5","6"},
		{"15","8"},
		{"2","3"},
	};

	int i;//QRand����p
	int j;//QAand����p

	int qr;//���p����
	int ar;//�����p����(�Z,�~)
	

public:
	Player();
	~Player();
	//�֐��������Ő錾����
	void Update();
	void Draw();
	int QRand();//���p����
	int ARand();//�����p����(�Z,�~)
};

