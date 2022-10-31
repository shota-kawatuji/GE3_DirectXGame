#include "Input.h"
#include <cassert>

#pragma comment(lib, "dinput8.lib")

void Input::Initialize(WinApp* winApp) {
	HRESULT result;
	// �؂�Ă���WinApp�̃C���X�^���X���L�^
	this->winApp_ = winApp;

	// DirectInput�I�u�W�F�N�g�̐���	
	result = DirectInput8Create(winApp->GetInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	// �L�[�{�[�h�f�o�C�X�̐���	
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	// ���̓f�[�^�`���̃Z�b�g
	result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
	assert(SUCCEEDED(result));

	// �r�����䃌�x���̃Z�b�g
	result = keyboard->SetCooperativeLevel(winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update() {
	HRESULT result;

	// �O��̃L�[���͂�ۑ�
	memcpy(keyPre, key, sizeof(key));

	// �L�[�{�[�h����J�n
	result = keyboard->Acquire();
	// �L�[�̓���
	result = keyboard->GetDeviceState(sizeof(key), key);

}

bool Input::PushKey(BYTE keyNumber) {
	// 0�łȂ���Ή����Ă���
	if (key[keyNumber]) {
		return true;
	}

	// �����Ă��Ȃ�
	return false;
}

bool Input::TriggerKey(BYTE keyNumber) {
	// �O��0�ŁA����0�łȂ���΃g���K�[
	if (!keyPre[keyNumber] && key[keyNumber]) {
		return true;
	}

	// �g���K�[�łȂ�
	return false;
}