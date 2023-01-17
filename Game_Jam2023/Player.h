#pragma once
class Player
{
private:
	//クラス内で使う変数
	const char * q[5] = { "2+3", "5*3", "6/3" };  //問題
	
	const char * a[3][2] = {//答え([正答][誤答])
		{"5","6"},
		{"15","8"},
		{"2","3"},
	};

	int i;//QRand代入用
	int j;//QAand代入用

	int qr;//問題用乱数
	int ar;//答え用乱数(〇,×)
	

public:
	Player();
	~Player();
	//関数をここで宣言する
	void Update();
	void Draw();
	int QRand();//問題用乱数
	int ARand();//答え用乱数(〇,×)
};

