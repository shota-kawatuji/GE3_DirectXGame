#pragma once
#include <d3d12.h>
#include <wrl.h>

#include "DirectXCommon.h"

class SpriteCommon
{
public: // �����o�֐�
	// ������
	void Initialize(DirectXCommon* dxCommon_);
	// �`��
	void PreDraw();

public: // �A�N�Z�b�T
	// getter
	DirectXCommon* GetDirectXCommon() { return dxCommon; }

private:
	DirectXCommon* dxCommon = nullptr;
	// �p�C�v���C���X�e�[�g
	Microsoft::WRL::ComPtr<ID3D12PipelineState>pipelineState;
	// ���[�v�V�O�l�`��
	Microsoft::WRL::ComPtr<ID3D12RootSignature>rootSignature;
};
