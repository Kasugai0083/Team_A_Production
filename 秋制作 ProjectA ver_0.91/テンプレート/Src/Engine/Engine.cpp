#include "Window.h"
#include "Graphics.h"
#include "Input.h"
#include "../Texture/Texture.h"
#include "Engine.h"

bool InitEngine(int width, int height, const char* title_name, bool isFull)
{
	if (MakeWindow(width, height, title_name) == false)
	{
		return false;
	}

	if (InitGraphics(isFull) == false)
	{
		return false;
	}

	if (InitInput() == false)
	{
		return false;
	}

	InitTexture();

	return true;
}

void EndEngine()
{
	AllReleaseTexture();
	EndGraphics();
	EndInput();
}
