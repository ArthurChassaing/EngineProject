#pragma once
#include "SwapChain.h"

namespace DXH
{
class Shader;
struct Mesh;

class Renderer
{
public:
	
	~Renderer() {}

	void Init();
	void Destroy();

	static Renderer& GetInstance()
	{
		static Renderer instance;
		return instance;
	}

	static RenderContext* GetRenderContext() { return GetInstance().m_pRenderContext; }
	static ID3D12DescriptorHeap* GetCbvSrvHeap() { return GetInstance().m_pCbvSrvHeap; }

	void BeginFrame();
	void Draw(Mesh* mesh);
	void EndFrame();

	void Clear()
	{
		m_pCommandList->ClearRenderTargetView(
			m_pSwapChain->GetCurrentBackBufferDescriptorHeap(),
			DirectX::Colors::Magenta,
			0, nullptr);
		m_pCommandList->ClearDepthStencilView(
			m_pSwapChain->GetDepthStencilDescriptorHeap(),
			D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL,
			1.0f, 0, 0, nullptr
		);
	}

	void OnResize();
	void FlushCommandQueue();

	ID3D12Resource* CreateDefaultBuffer(void* data, int64_t byteSize);

private:
	RenderContext* m_pRenderContext = nullptr;
	SwapChain* m_pSwapChain = nullptr;
	ID3D12CommandQueue* m_pCommandQueue = nullptr;
	ID3D12CommandAllocator* m_pCommandAllocator = nullptr;
	ID3D12GraphicsCommandList* m_pCommandList = nullptr;
	ID3D12Fence* m_pFence = nullptr;
	ID3D12DescriptorHeap* m_pCbvSrvHeap = nullptr;
	uint32_t m_CbvSrvIndex = 0;
	uint32_t m_FenceValue = 0;

private:
	Renderer() {}
};
}


