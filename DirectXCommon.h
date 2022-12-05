#pragma once
#include "WinApp.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

// DirectX���
class DirectXCommon
{
public: // �����o�ϐ�
	// ������
	void Initialize();
	// �f�o�C�X�̏�����
	void InitializeDevice();
	// �R�}���h�֘A�̏�����
	void InitializeCommand();
	// �X���b�v�`�F�[���̏�����
	void InitializeSwapchain();
	// �����_�[�^�[�Q�b�g�r���[�̏�����
	void InitializeRenderTargetView();
	// �[�x�o�b�t�@�̏�����
	void InitializeDepthBuffer();
	// �t�F���X�̏�����
	void InitializeFence();

private:
	// DirectX12�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> device;
	// DXGI�t�@�N�g��
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;
	// �R�}���h�A���P�[�^
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	// �R�}���h���X�g
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	// �R�}���h�L���[
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	// �X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	// �����_�[�^�[�Q�b�g�r���[�q�[�v
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	// �o�b�N�o�b�t�@
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	// �[�x�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	// �f�X�N���v�^�q�[�v
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;
	// �t�F���X
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;

private:
	// WindowsAPI
	WinApp* winApp = nullptr;
};