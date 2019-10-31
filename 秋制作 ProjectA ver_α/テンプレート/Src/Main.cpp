#include <Windows.h>
#include "Engine/Engine.h"
#include "Scene/Scene.h"
#include "Texture/Texture.h"
#include "Engine/Input.h"
#include "Engine/Graphics.h"
#include "Engine/Lib/Lib.h"


enum WINDOW_MODE {
	WINDOWED,
	FULL_SCLEEN
};

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{

	// エンジンの初期化
	if (InitEngine(1920, 1080, "FaNF2", FULL_SCLEEN) == false)
	{
		return 0;
	}

	while (TransButton()->Research(SceneTransition::Id::Finish) == false)
	{
		bool message_ret = false;
		MSG msg;



		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

			}
		}
		else
		{

			UpdateScene();

		}
	}
	EndEngine();

	return 0;
}

