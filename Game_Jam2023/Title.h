#pragma once
class Title
{
private:
//ƒNƒ‰ƒX“à‚Åg‚¤•Ï”
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
//ŠÖ”‚ğ‚±‚±‚ÅéŒ¾‚·‚é
	Title();
	~Title();
	void Update();
	void Draw();
};

