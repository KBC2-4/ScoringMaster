#pragma once
class Title
{
private:
//クラス内で使う変数
	int title_font;
	int btitle_font;
	int menu;
	int menunumber = 0;
	int titleimg;
	int input_margin;


public:
//関数をここで宣言する
	Title();
	~Title();
	void Update();
	void Draw();
};

