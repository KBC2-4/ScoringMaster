#include "main.h"
#include "PadInput.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	double dNextTime = GetNowCount();

	SetMainWindowText("Game_Jam2023");
	SetMainWindowClassName("Game_Jam2023");
	ChangeWindowMode(TRUE);

	SetOutApplicationLogValidFlag(FALSE);   //ログ出力を無効にする

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);

	SetAlwaysRunFlag(true);		//常にアクティブにする

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	enum class GAME_STATE
	{
		TITLE = 0,     //タイトル
		GAME_INIT,          //初期処理
		GAME_MAIN,          //メイン
		GAME_RESULT,    //ゲームクリア描画
	};

	GAME_STATE GameState = GAME_STATE::TITLE;

	while (ProcessMessage() == 0) {

		switch (GameState)
		{
		case GAME_STATE::TITLE:
			//GameTitle();                //ゲームタイトル処理           
			break;

		case GAME_STATE::GAME_INIT:
			//Gameinit();                       //ゲーム初期処理
			break;

		case GAME_STATE::GAME_MAIN:
			//GameMain();                       //ゲームメイン処理
			break;

		case GAME_STATE::GAME_RESULT:
			//GameClear();                   //ゲームリザルト処理
			break;
		}

		ClearDrawScreen();
		PAD_INPUT::UpdateKey();	//パッドの入力状態の更新
		//フレームレートの設定
		dNextTime += static_cast<double>(1.0 / 60.0 * 1000.0);
		if (dNextTime > GetNowCount()) {
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//補正

		DrawBoxAA(50, 50, 600, 600, 0xFFFFFF, TRUE, 3.0f);


		ScreenFlip();





	}
	DxLib_End();

	return 0;
}