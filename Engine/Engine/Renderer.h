#pragma once

#include <wrl.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <d3dcommon.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")

using namespace DirectX;

class Renderer
{
private:

	Microsoft::WRL::ComPtr<IDXGISwapChain> SwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device> d3d11Device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3d11DevCon;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> srv;
	
	

	float red = 0.0f;
	float green = 0.0f;
	float blue = 0.0f;

public:

	void Initialize();
	void Update();
	void Render();
	void Present();

	void ShutDown();

};