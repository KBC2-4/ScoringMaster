#pragma once
class Title
{
private:
//�N���X���Ŏg���ϐ�
	int title_font;
	int btitle_font;
	int menu;
	int menunumber = 0;
	int titleimg;
	int input_margin;


public:
//�֐��������Ő錾����
	Title();
	~Title();
	void Update();
	void Draw();
};

