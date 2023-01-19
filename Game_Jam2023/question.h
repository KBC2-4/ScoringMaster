#pragma once
#include<string>
#include<vector>
#define MONDAI 60 //問題数のマクロ定義

class Question
{
private:
	//クラス内で使う変数
	std::vector<std::string> question =
	{ "　月曜日の明後日の５日前は\n　　　　何曜日か答えなさい",
		"　１４時の８時間前の３時間後は\n　　　　　何時か答えなさい" ,
		"　１３個あるリンゴを４個食べて\n　７個もらい５個友達にあげました\n　今あるリンゴの個数を答えなさい",
		"　 「難」の画数を答えなさい",
		"　１００００m走は４００mトラック\n　　　 何周分か答えなさい",
		"　 １０月２２日生まれは\n　　 何座か答えなさい",
		"　　 ３００mlの水が入ったカップを\n　　　　７L入るバケツに移すと\n　何杯で満タンになるか答えなさい",
		"　　現在発行されている\n　　日本のお金は全部で\n　　何種類あるか答えなさい",
		"　　　九州地方にある県は\n　 全部でいくつか答えなさい",
		"　 鉛筆と消しゴムの合計は１１０円\n　で鉛筆は消しゴムより１００円高い\n　　 消しゴムの値段を答えなさい",
		"　 都道府県の都道府は\n　 いくつあるか答えなさい",
		"　 １〜１０までの奇数を\n　 足した数を答えなさい",
		"　　バスに８人乗っています。\n　　そのうち３人が降りました。\n　　バスの客は何人か答えなさい。",
		"　あなたは２００円持っています。\n　１００円のものを買うとおつりは\n　　 いくらになるか答えなさい",
		"　　春、夏、秋、冬、一年の中で、\n　一番長いのはどれか答えなさい",
		"９位で走っているマラソン選手が\n ８,７,６位をまとめて抜きました。\n　現在の順位を答えなさい",
		"アルファベットのQは\nAから数えて何番目か答えなさい"
		"２０２３年２月１日は\n何曜日か答えなさい"
		"英語のアルファベットの\n一番最初の文字はAでBの前にあります。\nでは、一番最後の文字は何でしょう？",
		"日本で一番北にある県は何県?",
		"幼稚園、小学生、大人の\n中で、一番大きいのは？",
		"２２時の１４時間前の６時間後は\n何時か答えなさい",
		"６０分の動画を１.５倍速で\n再生した場合、何分かかるか答えなさい",
		"１年で３１日がある月は\n７回あります。２８日がある月は\nいくつあるでしょう？",
		"花束を２束と３束、\n合わせると何束になる？",
		"ハングル語というのは\nどこの国の言葉？",
		"アメリカの総理大臣は？",
		"イカをあげるとイカリング\n首にかけるアクセサリーと言えば？",
		"１７個あるミカンを１２個食べて\n９個もらい６個友達にあげました。\n今あるミカンの個数を答えなさい",
		"「驚」の画数を答えなさい",
		"１〜１０までの偶数を足した数を\n答えなさい",
		"５０００ｍ走は４００ｍトラック何周分か\n答えなさい",
		"「議」の画数を答えなさい",
		"金曜日の６日後の３日前は/n何曜日か答えなさい"
	};  // 問題用の二次元配列
	//"９位で走っているマラソン選手が\n ８,７,６位をまとめて抜きました。\n　　現在の順位を答えなさい"
	std::vector<std::vector<std::string>> answer = {
		{ "金曜日", "９時", "１１個", "１８画", "２５周", "てんびん座", "２４杯", "１０種類",
		"８つ", "５円", "４つ", "２５", "４人", "０円", "一年","６位","１７番目","水曜日","T",
		"青森県","幼稚園","１４時","４０分","１２","１束","日本語","いない","ネックレス","８個",
		"２２画","３０","１２周半","２０画","月曜日"},

		{"日曜日" , "１０時", "９個", "２０画", "３０週", "うお座", "２１杯", "９種類", "７つ",
		"１０円", "３つ", "２４", "５人", "１００円", "夏","５位","１８番目","火曜日","Z","北海道",
		"大人","１２時","４５分","１","５束","韓国語","ジョー・バイデン","イヤリング","９個","２１画",
		"２８","１２週","２１画","日曜日"},
	};  // 回答用の二次元配列

public:
	//関数をここで宣言する
	Question();
	~Question();
	void Update();
	void Draw();

	std::string GetQuestion(int num) { return question.at(num); }
	std::string GetAnswer(int num, bool correct) { return answer.at(correct).at(num); }

};