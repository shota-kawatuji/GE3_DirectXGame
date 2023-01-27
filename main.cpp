#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
#pragma region 基盤システムの初期化

#pragma region WindowsAPI初期化処理
	WinApp* winApp = nullptr;
	//windowsAPIの初期化
	winApp = new WinApp();
	winApp->Initialize();
#pragma endregion

#pragma region DirectX初期化
	DirectXCommon* dxCommon = nullptr;
	//DirectX12初期化
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);
#pragma endregion

#pragma region 入力初期化
	Input* input = nullptr;
	//入力の初期化
	input = new Input();
	input->Initialize(winApp);
#pragma endregion

#pragma region スプライトの初期化
	SpriteCommon* spriteCommon = nullptr;
	// スプライト共通部分の初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);
#pragma endregion

#pragma endregion

#pragma region 最初のシーンの初期化
	Sprite* sprite = new Sprite;
	sprite->Initialize(spriteCommon);
#pragma endregion

	while (true) {
#pragma region 基盤システムの更新
		if (winApp->ProcessMessage()) {
			// ゲームループを抜ける
			break;
		}
#pragma endregion
		//入力の更新
		input->Update();
		// 描画前処理
		dxCommon->PreDraw();
#pragma region 最初のシーンの描画
		// スプライトの描画
		spriteCommon->PreDraw();
#pragma endregion
		//描画後処理
		dxCommon->PostDraw();
	}

#pragma region 最初のシーンの初期化

#pragma endregion

#pragma region 基盤システムの終了
	// 入力解放
	delete input;
	// DirectX解放
	delete dxCommon;
	// Spriteの解放
	delete sprite;
	// SpriteCommonの解放
	delete spriteCommon;
	//WindowsAPIの終了処理
	winApp->Finalize();
	// WindowAPI解放
	delete winApp;

#pragma endregion
	return 0;
}