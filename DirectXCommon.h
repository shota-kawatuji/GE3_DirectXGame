#pragma once
#include "WinApp.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

// DirectX基盤
class DirectXCommon
{
public: // メンバ変数
	// 初期化
	void Initialize();
	// デバイスの初期化
	void InitializeDevice();
	// コマンド関連の初期化
	void InitializeCommand();
	// スワップチェーンの初期化
	void InitializeSwapchain();
	// レンダーターゲットビューの初期化
	void InitializeRenderTargetView();
	// 深度バッファの初期化
	void InitializeDepthBuffer();
	// フェンスの初期化
	void InitializeFence();

private:
	// DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	// DXGIファクトリ
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	// コマンドアロケータ
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	// コマンドリスト
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	// コマンドキュー
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	// スワップチェーン
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	// レンダーターゲットビューヒープ
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	// バックバッファ
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	// 深度バッファ
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	// デスクリプタヒープ
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	// フェンス
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;

private:
	// WindowsAPI
	WinApp* winApp = nullptr;
};