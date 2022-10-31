#pragma once
#include <wrl.h>
#include <dinput.h>
#include "WinApp.h"
#define DIRECTINPUT_VERSION 0x0800 // DirectInput�̃o�[�W�����w��

// ����
class Input
{
public:
	// namespace�ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: // �����o�֐�
	// ������
	void Initialize(WinApp* winApp);
	// �X�V
	void Update();

	/// <summary>
	/// �L�[�̉���
	/// </summary>
	/// <param name="keyNumber">�L�[�ԍ�( DIK_0 ��)</param>
	/// <returns>������Ă��邩</returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// �L�[�̃g���K�[���`�F�b�N
	/// </summary>
	/// <param name="keyNumber">�L�[�ԍ�( DIK_0 �� )</param>
	/// <returns>�g���K�[��</returns>
	bool TriggerKey(BYTE keyNumber);

private: // �����o�ϐ�
	// �L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> keyboard;
	ComPtr<IDirectInput8> directInput;
	// WindowsAPI
	WinApp* winApp_ = nullptr;
	// �S�L�[�̏��
	BYTE key[256] = {};
	// �O��̑S�L�[�̏��
	BYTE keyPre[256] = {};
};