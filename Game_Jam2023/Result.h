#pragma once
class Result
{
private:
	//クラス内で使う変数
	int title_font;
	int bottun_font;
	
	bool nextscene;
	


public:
	//関数をここで宣言する
	Result();
	~Result();
	void Update();
	void Draw();

	bool GetNextScene() { return nextscene; };
};

