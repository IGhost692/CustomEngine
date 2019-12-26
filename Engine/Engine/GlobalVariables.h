#pragma once

class Globals
{
public:

	float WindowWidth = 1280.0f;
	float WindowHeight = 720.0f;

	float zNear = 0.3f;
	float zFar = 1000.0f;

	UINT ScreenRefreshRate = 60;

	bool EnableVSync = true;

	HWND hWnd;

	static Globals& getInstance()
	{
		static Globals    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
private:
	Globals() {}                    // Constructor? (the {} brackets) are needed here.

	//Globals(Globals const&);              // Don't Implement
	//void operator=(Globals const&); // Don't implement

public:
	Globals(Globals const&) = delete;
	void operator=(Globals const&) = delete;

};
