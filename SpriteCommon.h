#pragma once
#include <d3d12.h>
#include <wrl.h>

#include "DirectXCommon.h"

class SpriteCommon
{
public: // メンバ関数
	// 初期化
	void Initialize(DirectXCommon* dxCommon_);
	// 描画
	void PreDraw();

public: // アクセッサ
	// getter
	DirectXCommon* GetDirectXCommon() { return dxCommon; }

private:
	DirectXCommon* dxCommon = nullptr;
	// パイプラインステート
	Microsoft::WRL::ComPtr<ID3D12PipelineState>pipelineState;
	// ループシグネチャ
	Microsoft::WRL::ComPtr<ID3D12RootSignature>rootSignature;
};
