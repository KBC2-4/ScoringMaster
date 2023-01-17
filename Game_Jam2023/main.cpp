#include "main.h"
#include "PadInput.h"
#include "Title.h"
#include "GameMain.h"
#include "Result.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	double dNextTime = GetNowCount();

	SetMainWindowText("Game_Jam2023");
	SetMainWindowClassName("Game_Jam2023");
	ChangeWindowMode(TRUE);

	SetOutApplicationLogValidFlag(FALSE);   //ログ出力を無効にする

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_4X4);

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);

	SetAlwaysRunFlag(true);		//常にアクティブにする

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	Title* title;
	GameMain* gamemain;
	Result* result;

	title = nullptr;
	gamemain = nullptr;
	result = nullptr();

	bool scene_change = false;

	enum class GAME_STATE
	{
		TITLE = 0,     //タイトル
		GAME_MAIN,          //メイン
		GAME_RESULT,    //ゲームクリア描画
	};

	GAME_STATE GameState = GAME_STATE::TITLE;

	while (ProcessMessage() == 0) {


		ClearDrawScreen();
		switch (GameState)
		{
		case GAME_STATE::TITLE:
			if (scene_change == false) { title = new Title(); scene_change = true; }
			title->Update();
			title->Draw();

			if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_B && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
				delete title;
				GameState = GAME_STATE::GAME_MAIN;
				scene_change = false;
			}
			break;


		case GAME_STATE::GAME_MAIN:
			if (scene_change == false) { gamemain = new GameMain(); scene_change = true; }
			gamemain->Update();
			gamemain->Draw();

			if (gamemain->GetClearFlg() == true) {
				delete gamemain; 
				GameState = GAME_STATE::GAME_RESULT; 
				scene_change = false;
			}
			break;

		case GAME_STATE::GAME_RESULT:
			if (scene_change == false) { result = new Result(); scene_change = true; }
			
			result->Update();
			result->Draw();
			

			if(result->GetNextScene() == true){ 
				delete result; 
				GameState = GAME_STATE::TITLE; 
				scene_change = false;
			}
			break;
		}
			
		
		PAD_INPUT::UpdateKey();	//パッドの入力状態の更新
		//フレームレートの設定
		dNextTime += static_cast<double>(1.0 / 60.0 * 1000.0);
		if (dNextTime > GetNowCount()) {
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//補正

		//DrawBoxAA(50, 50, 600, 600, 0xFFFFFF, TRUE, 3.0f);


		ScreenFlip();





	}
	DxLib_End();

	return 0;
}