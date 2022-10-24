#include "Input.h"
#include <cassert>

#pragma comment(lib, "dinput8.lib")

void Input::Initialize(HINSTANCE hInstance, HWND hwnd) {
	HRESULT result;

	// DirectInputオブジェクトの生成	
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	// キーボードデバイスの生成	
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	// 入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
	assert(SUCCEEDED(result));

	// 排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update() {
	keyboard->Acquire();	// キーボード動作開始

	// 前回のキー入力を保存
	memcpy(keyPre, key, sizeof(key));

	// キーの入力
	keyboard->GetDeviceState(sizeof(key), key);

}

bool Input::PushKey(BYTE keyNumber) {

}

bool Input::TiggerKey(BYTE keyNumber) {

}