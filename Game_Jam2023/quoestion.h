#pragma once
#include<string>
#define MONDAI 60 //��萔�̃}�N����`

class Question
{
private:
	//�N���X���Ŏg���ϐ�
	const std::string question[MONDAI];  // ���p�̓񎟌��z��
	const std::string answer[MONDAI][MONDAI];  // �񓚗p�̓񎟌��z��
		
public:
	//�֐��������Ő錾����
	Question();
	~Question();
	void Update();
	void Draw();
};

