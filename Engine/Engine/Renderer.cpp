#include "stdafx.h"

#include "Renderer.h"
#include "GlobalVariables.h"

void Renderer::Initialize()
{
	//Describe our Buffer
	DXGI_MODE_DESC bufferDesc;

	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

	bufferDesc.Width = Globals::getInstance().WindowWidth;
	bufferDesc.Height = Globals::getInstance().WindowHeight;
	bufferDesc.RefreshRate.Numerator = Globals::getInstance().ScreenRefreshRate;
	bufferDesc.RefreshRate.Denominator = 1;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	//Describe our SwapChain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;

	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDesc.BufferDesc = bufferDesc;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = Globals::getInstance().hWnd;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	
	//Create our SwapChain
	D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
		D3D11_SDK_VERSION, &swapChainDesc, SwapChain.GetAddressOf(), d3d11Device.GetAddressOf(), NULL, d3d11DevCon.GetAddressOf());

	//Create our BackBuffer
	ID3D11Texture2D* BackBuffer;
	SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer);

	//Create our Render Target
	d3d11Device->CreateRenderTargetView(BackBuffer, NULL, renderTargetView.GetAddressOf());
	BackBuffer->Release();

	//Set our Render Target
	d3d11DevCon->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), NULL);


}

void Renderer::Update()
{
	red += fmodf(0.001f, 1.0f);
	green += fmodf(0.001f, 1.0f);
	blue += fmodf(0.001f, 1.0f);
}

void Renderer::Render()
{

	

}

void Renderer::Present()
{
	//Clear our backbuffer to the updated color
	float bgColor[4] = { red, green, blue, 1.0f };

	d3d11DevCon->ClearRenderTargetView(renderTargetView.Get(), bgColor);

	//Present the backbuffer to the screen
	SwapChain->Present(0, 0);
}

void Renderer::ShutDown()
{
	SwapChain->Release();
	d3d11Device->Release();
	d3d11DevCon->Release();
}

