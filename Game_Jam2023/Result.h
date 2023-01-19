#pragma once
class Result
{
private:
	//ƒNƒ‰ƒX“à‚Åg‚¤•Ï”
	int title_font;
	int bottun_font;
	int rank_font;
	
	bool nextscene;
	short clear_count;

	enum class Rank {
		S,
		A,
		B,
		C,
		D,
		E
	};
	Rank rank;


public:
	//ŠÖ”‚ğ‚±‚±‚ÅéŒ¾‚·‚é
	Result(short clear_count = 0);
	~Result();
	void Update();
	void Draw();

	bool GetNextScene() { return nextscene; };
};

