#pragma once
#include "SwapChain.h"
#include "Util.h"

namespace DXH
{
class Shader;
struct Mesh;
struct Material;
struct Transform;
struct Camera;

class Renderer
{
public:
    
    ~Renderer() {}

    /// <summary>
    /// Initialize all the things DirectX will need to draw things
    /// </summary>
    void Init();
    void Destroy();

    /// <summary>
    /// Singleton
    /// </summary>
    static Renderer& GetInstance()
    {
        static Renderer instance;
        return instance;
    }

    /// <summary>
    /// Get the render context
    /// </summary>
    /// <returns>Pointer to the render context</returns>
    static RenderContext* GetRenderContext() { return GetInstance().m_pRenderContext; }

    /// <summary>
    /// Get the CBV_SRV descriptor heap
    /// </summary>
    /// <returns>Pointer to the CBV_SRV descriptor heap</returns>
    static ID3D12DescriptorHeap* GetCbvSrvHeap() { return GetInstance().m_pCbvSrvHeap; }

    /// <summary>
    /// Initialize the resources needed to draw to the back buffer
    /// </summary>
    void BeginFrame(const Camera& camera);

    /// <summary>
    /// Draw a mesh
    /// </summary>
    void Draw(Mesh& mesh, Transform& transform);

    /// <summary>
    /// End the frame and present the back buffer
    /// </summary>
    void EndFrame();

    /// <summary>
    /// Resize the swap chain
    /// </summary>
    void OnResize();

    /// <summary>
    /// waits for the GPU to finish executing the command list
    /// </summary>
    void FlushCommandQueue();

    /// <summary>
    /// Clear the back buffer and depth stencil buffer
    /// </summary>
    inline void Clear();

    /// <summary>
    /// Create a default buffer to store vertices, indices, etc.
    /// </summary>
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


