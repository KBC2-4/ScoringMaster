#pragma once
class Result
{
private:
	//クラス内で使う変数
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

	int enter_se;
	int result_bgm;

public:
	//関数をここで宣言する
	Result(short clear_count = 0);
	~Result();
	void Update();
	void Draw();

	bool GetNextScene() { return nextscene; };
};

