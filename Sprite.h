#pragma once
#include <DirectXMath.h>
#include "SpriteCommon.h"

class Sprite
{
public: // �����o�֐�
	// ������
	void Initialize(SpriteCommon* spriteCommon_);
	// �`��
	void Draw();

private:
	// �X�v���C�g
	SpriteCommon* spriteCommon = nullptr;
	// ���_�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource>vertBuff;
	// ���_�o�b�t�@�r���[
	D3D12_VERTEX_BUFFER_VIEW vbView{};

};
