#include "Input.h"
#include <cassert>

#pragma comment(lib, "dinput8.lib")

void Input::Initialize(WinApp* winApp) {
	HRESULT result;
	// 借りてきたWinAppのインスタンスを記録
	this->winApp_ = winApp;

	// DirectInputオブジェクトの生成	
	result = DirectInput8Create(winApp->GetInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	// キーボードデバイスの生成	
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	// 入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
	assert(SUCCEEDED(result));

	// 排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update() {
	HRESULT result;

	// 前回のキー入力を保存
	memcpy(keyPre, key, sizeof(key));

	// キーボード動作開始
	result = keyboard->Acquire();
	// キーの入力
	result = keyboard->GetDeviceState(sizeof(key), key);

}

bool Input::PushKey(BYTE keyNumber) {
	// 0でなければ押している
	if (key[keyNumber]) {
		return true;
	}

	// 押していない
	return false;
}

bool Input::TriggerKey(BYTE keyNumber) {
	// 前回が0で、今回が0でなければトリガー
	if (!keyPre[keyNumber] && key[keyNumber]) {
		return true;
	}

	// トリガーでない
	return false;
}