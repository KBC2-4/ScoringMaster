#include "Title.h"
#include "DxLib.h"

Title::Title() {
	title_font = CreateFontToHandle("メイリオ", 120, 1);
}

Title::~Title() {
	DeleteFontToHandle(title_font);
}

void Title::Update()
{
}

void Title::Draw()
{
	DrawStringToHandle(400, 300, "タイトル", 0xFFFFFF, title_font);
}
