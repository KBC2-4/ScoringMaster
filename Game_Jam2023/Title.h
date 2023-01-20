#pragma once
class Title
{
private:
//ƒNƒ‰ƒX“à‚Åg‚¤•Ï”
	int title_font;
	int btitle_font;
	int guid_font;

	int menu;
	int menunumber;
	int titleimg;
	int input_margin;

	int select_se;
	int enter_se;
	int background_music;

public:
	enum class NextScene
	{
		NONE,
		PLAY,
		END
	};

	NextScene next_scene;


public:
//ŠÖ”‚ğ‚±‚±‚ÅéŒ¾‚·‚é
	Title();
	~Title();
	void Update();
	void Draw();

	NextScene GetNextScene() const { return next_scene; }
};

