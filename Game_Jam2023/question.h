#pragma once
#include<string>
#include<vector>
#define MONDAI 60 //–â‘è”‚Ìƒ}ƒNƒ’è‹`

class Question
{
private:
	//ƒNƒ‰ƒX“à‚ÅŽg‚¤•Ï”
	std::vector<std::string> question =
	{ "ŒŽ—j“ú‚Ì–¾Œã“ú‚Ì‚T“ú‘O‚Í\n@@@‰½—j“ú‚©“š‚¦‚È‚³‚¢",
		"‚P‚SŽž‚Ì‚WŽžŠÔ‘O‚Ì‚RŽžŠÔŒã‚Í\n@‰½Žž‚©“š‚¦‚È‚³‚¢" ,
		"‚P‚RŒÂ‚ ‚éƒŠƒ“ƒS‚ð‚SŒÂH‚×‚Ä\n‚VŒÂ‚à‚ç‚¢‚TŒÂ—F’B‚É‚ ‚°‚Ü‚µ‚½B\n¡‚ ‚éƒŠƒ“ƒS‚ÌŒÂ”‚ð“š‚¦‚È‚³‚¢",
		"u“ïv‚Ì‰æ”‚ð“š‚¦‚È‚³‚¢",
		"‚P‚O‚O‚O‚Om‘–‚Í‚S‚O‚Omƒgƒ‰ƒbƒN\n‰½Žü•ª‚©“š‚¦‚È‚³‚¢",
		"‚P‚OŒŽ‚Q‚Q“ú¶‚Ü‚ê‚Í‰½À‚©\n“š‚¦‚È‚³‚¢",
		"‚R‚O‚Oml‚Ì…‚ª“ü‚Á‚½ƒJƒbƒv‚ð\n‚VL“ü‚éƒoƒPƒc‚ÉˆÚ‚·‚Æ‰½”t‚Å\nƒoƒPƒc‚Ì…‚Í–žƒ^ƒ“‚É‚È‚é‚©“š‚¦‚È‚³‚¢",
		"Œ»Ý”­s‚³‚ê‚Ä‚¢‚é“ú–{‚Ì‚¨‹à‚Í\n‘S•”‚Å‰½Ží—Þ‚ ‚é‚©“š‚¦‚È‚³‚¢",
		"‹ãB’n•û‚É‚ ‚éŒ§‚Í\n‘S•”‚Å‚¢‚­‚Â‚©“š‚¦‚È‚³‚¢",
		"‰”•M‚ÆÁ‚µƒSƒ€‚Í‡‚í‚¹‚Ä‚P‚P‚O‰~‚Å\n‰”•M‚ÍÁ‚µƒSƒ€‚æ‚è‚P‚O‚O‰~‚‚¢B\nÁ‚µƒSƒ€‚Ì’l’i‚ð“š‚¦‚È‚³‚¢",
		"“s“¹•{Œ§‚Ì“s“¹•{‚Í\n‚¢‚­‚Â‚ ‚é‚©“š‚¦‚È‚³‚¢",
		"‚P`‚P‚O‚Ü‚Å‚ÌŠï”‚ð‘«‚µ‚½”‚ð\n“š‚¦‚È‚³‚¢",
		"ƒoƒX‚É‚Wlæ‚Á‚Ä‚¢‚Ü‚·B \n‚»‚Ì‚¤‚¿‚Rl‚ª~‚è‚Ü‚µ‚½B\nƒoƒX‚Ì‹q‚Í‰½l‚©“š‚¦‚È‚³‚¢",
		"‚ ‚È‚½‚Í‚Q‚O‚O‰~Ž‚Á‚Ä‚¢‚Ü‚·B\n‚P‚O‚O‰~‚Ì‚à‚Ì‚ð”ƒ‚¤‚Æ‚¨‚Â‚è‚Í\n‚¢‚­‚ç‚É‚È‚é‚©“š‚¦‚È‚³‚¢",
		"tA‰ÄAHA“~Aˆê”N‚Ì’†‚Å\nˆê”Ô’·‚¢‚Ì‚Í‚Ç‚ê‚©“š‚¦‚È‚³‚¢"
	};  // –â‘è—p‚Ì“ñŽŸŒ³”z—ñ
	//"‚XˆÊ‚Å‘–‚Á‚Ä‚¢‚éƒ}ƒ‰ƒ\ƒ“‘IŽè‚ª\n ‚W,‚V,‚UˆÊ‚ð‚Ü‚Æ‚ß‚Ä”²‚«‚Ü‚µ‚½B\n@@Œ»Ý‚Ì‡ˆÊ‚ð“š‚¦‚È‚³‚¢"
	std::vector<std::vector<std::string>> answer = {
		{ "‹à—j“ú", "‚XŽž", "‚P‚PŒÂ", "‚P‚W‰æ", "‚Q‚TŽü", "‚Ä‚ñ‚Ñ‚ñÀ", "‚Q‚S”t", "‚P‚OŽí—Þ",
		"‚W‚Â", "‚T‰~", "‚S‚Â", "‚Q‚T", "‚Sl", "‚O‰~", "ˆê”N"},

		{"“ú—j“ú" , "‚P‚OŽž", "‚XŒÂ", "‚Q‚O‰æ", "‚R‚OT", "‚¤‚¨À", "‚Q‚P”t", "‚XŽí—Þ", "‚V‚Â",
		"‚P‚O‰~", "‚R‚Â", "‚Q‚S", "‚Tl", "‚P‚O‚O‰~", "‰Ä"},
	};  // ‰ñ“š—p‚Ì“ñŽŸŒ³”z—ñ

public:
	//ŠÖ”‚ð‚±‚±‚ÅéŒ¾‚·‚é
	Question();
	~Question();
	void Update();
	void Draw();

	std::string GetQuestion(int num) { return question.at(num); }
	std::string GetAnswer(int num, bool correct) { return answer.at(correct).at(num); }

};