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

	int select_se;
	int enter_se;
	int background_music;


public:
//�֐��������Ő錾����
	Title();
	~Title();
	void Update();
	void Draw();
};

