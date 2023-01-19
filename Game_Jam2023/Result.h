#pragma once
class Result
{
private:
	//ƒNƒ‰ƒX“à‚Åg‚¤•Ï”
	int title_font;
	int bottun_font;
	
	bool nextscene;
	


public:
	//ŠÖ”‚ğ‚±‚±‚ÅéŒ¾‚·‚é
	Result();
	~Result();
	void Update();
	void Draw();

	bool GetNextScene() { return nextscene; };
};

