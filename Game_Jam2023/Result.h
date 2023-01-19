#pragma once
class Result
{
private:
	//�N���X���Ŏg���ϐ�
	int title_font;
	int bottun_font;
	int rank_font;
	int guid_font;

	int gcrown_img;
	int scrown_img;
	int bcrown_img;
	int background_image;
	
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
	//�֐��������Ő錾����
	Result(short clear_count = 0);
	~Result();
	void Update();
	void Draw();

	bool GetNextScene() { return nextscene; };
};

