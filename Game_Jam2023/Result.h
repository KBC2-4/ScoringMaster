#pragma once
class Result
{
private:
	//�N���X���Ŏg���ϐ�
	int title_font;
	int bottun_font;
	
	bool nextscene;
	


public:
	//�֐��������Ő錾����
	Result();
	~Result();
	void Update();
	void Draw();

	bool GetNextScene() { return nextscene; };
};

