#pragma once

#include <Windows.h>
#include <string>

void DisplayErrorBox(const char *message)
{
	MessageBoxA(NULL, message, NULL, MB_OK);
	throw std::exception(message);
}