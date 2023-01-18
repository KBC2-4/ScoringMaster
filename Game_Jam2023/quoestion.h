#pragma once
#include<string>
#define MONDAI 60 //問題数のマクロ定義

class Question
{
private:
	//クラス内で使う変数
	const std::string question[MONDAI];  // 問題用の二次元配列
	const std::string answer[MONDAI][MONDAI];  // 回答用の二次元配列
		
public:
	//関数をここで宣言する
	Question();
	~Question();
	void Update();
	void Draw();
};

