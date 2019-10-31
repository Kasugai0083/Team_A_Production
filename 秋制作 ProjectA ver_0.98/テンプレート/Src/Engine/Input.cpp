#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <Windows.h>
#include "../Utility/Vec.h"
#include "Window.h"
#include "Input.h"

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

struct INPUTSTATE
{
	DWORD now;
	DWORD trg;
	DWORD ntrg;
};

static LPDIRECTINPUT8 g_InputInterface;		//!< DIRECTINPUT8のポインタ
static LPDIRECTINPUTDEVICE8 g_MouseDevice;		//!< DIRECTINPUTDEVICE8のポインタ
static DIMOUSESTATE g_PrevMouseState;			//!< マウスの１フレーム前の入力情報
static DIMOUSESTATE g_CurrentMouseState;		//!< マウスの現在の入力情報
static Vec2 g_MousePos;
static Vec2 g_MouseMoveVec;

// 入力インターフェースの作成
bool CreateInputInterface();

// マウスデバイスの作成
bool CreateMouseDevice();

//キーボードデバイスの作成
bool CreateKeyboardDevice();

// マウスの更新
void UpdateMouse();

#define MOUSE_ON_VALUE (0x80)		// オン状態の値

static LPDIRECTINPUTDEVICE8 g_pKeyDevice;

// キー情報
static INPUTSTATE g_InputState;


bool InitInput()
{
	if (CreateInputInterface() == false)
	{
		return false;
	}

	if (CreateMouseDevice() == false)
	{
		EndInput();
		return false;
	}

	if (CreateKeyboardDevice() == false) {
		EndInput();
		return false;
	}

	ZeroMemory(&g_CurrentMouseState, sizeof(DIMOUSESTATE));
	ZeroMemory(&g_PrevMouseState, sizeof(DIMOUSESTATE));

	return true;
}

void EndInput()
{
	if (g_MouseDevice != nullptr)
	{
		g_MouseDevice->Release();
		g_MouseDevice = nullptr;
	}

	if (g_InputInterface != nullptr)
	{
		g_InputInterface->Release();
		g_InputInterface = nullptr;
	}

	if (g_pKeyDevice != nullptr)
	{
		g_pKeyDevice -> Release();
		g_pKeyDevice = nullptr;
	}
}

void UpdateKey()
{
	// キー情報取格納用
	BYTE KeyState[256];
	HRESULT hr;

	// キーボードデバイスのゲッター
	hr = g_pKeyDevice->GetDeviceState(256, KeyState);
	if (FAILED(hr)) {
		g_pKeyDevice->Acquire();
		hr = g_pKeyDevice->GetDeviceState(256, KeyState);
		
	}
	if (SUCCEEDED(hr))
	{
		// 1フレーム前のキー情報の確保
		DWORD old = g_InputState.now;

		// キー情報クリア
		g_InputState.now = CLEAR_KEY;

		// 上キー
		if (KeyState[DIK_UP] & 0x80)
		{
			g_InputState.now |= UP_KEY;
		}

		// 下キー
		if (KeyState[DIK_DOWN] & 0x80)
		{
			g_InputState.now |= DOWN_KEY;
		}

		// 左キー
		if (KeyState[DIK_LEFT] & 0x80)
		{
			g_InputState.now |= LEFT_KEY;
		}

		// 右キー
		if (KeyState[DIK_RIGHT] & 0x80)
		{
			g_InputState.now |= RIGHT_KEY;
		}

		// リターンキー
		if (KeyState[DIK_RETURN] & 0x80)
		{
			g_InputState.now |= RETURN_KEY;
		}
		if (KeyState[DIK_W] & 0x80)
		{
			g_InputState.now |= W_KEY;
		}
		if (KeyState[DIK_A] & 0x80)
		{
			g_InputState.now |= A_KEY;
		}
		if (KeyState[DIK_S] & 0x80)
		{
			g_InputState.now |= S_KEY;
		}
		if (KeyState[DIK_D] & 0x80)
		{
			g_InputState.now |= D_KEY;
		}
		if (KeyState[DIK_ESCAPE] & 0x80)
		{
			g_InputState.now |= ESCAPE_KEY;
		}
		if (KeyState[DIK_LCONTROL] & 0x80)
		{
			g_InputState.now |= CONTROL_KEY;
		}

		g_InputState.trg = (g_InputState.now & (~old));	// トリガー情報取得
		g_InputState.ntrg = (~g_InputState.now) & old;	// 逆トリガー情報取得

	}
	else if (hr == DIERR_INPUTLOST) {
		g_pKeyDevice->Acquire();
	}
}

void UpdateInput()
{
	UpdateMouse();

	UpdateKey();


	g_PrevMouseState = g_CurrentMouseState;
	// マウスの状態を取得します
	HRESULT	hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	if (FAILED(hr))
	{
		g_MouseDevice->Acquire();
		hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	}
}


bool OnMouseDown(MouseButton button_type)
{
	if (!(g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE) &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}

bool OnMousePush(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}

bool OnMouseUp(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		!(g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE))
	{
		return true;
	}

	return false;
}

void UpdateMouse()
{
	Vec2 prev = g_MousePos;
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(FindWindowA(WINDOW_CLASS_NAME, nullptr), &p);

	g_MousePos.X = (float)p.x;
	g_MousePos.Y = (float)p.y;

	g_MouseMoveVec.X = g_MousePos.X - prev.X;
	g_MouseMoveVec.Y = g_MousePos.Y - prev.Y;
}

Vec2 GetMousePos()
{
	return g_MousePos;
}

bool CreateInputInterface()
{
	HRESULT ret = DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)& g_InputInterface, nullptr);
	if (FAILED(ret))
	{
		return false;	// 作成に失敗
	}

	return true;
}

bool CreateMouseDevice()
{
	// マウス用にデバイスオブジェクトを作成
	if (FAILED(g_InputInterface->CreateDevice(GUID_SysKeyboard, &g_pKeyDevice, nullptr)))
	{
		// デバイスの作成に失敗
		return false;
	}

	// データフォーマットを設定
	if (FAILED(g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		// データフォーマットに失敗
		return false;
	}

	// モードを設定（フォアグラウンド＆非排他モード）
	if (FAILED(g_pKeyDevice->SetCooperativeLevel(
		FindWindowA(WINDOW_CLASS_NAME, nullptr),
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		// モードの設定に失敗
		return false;
	}

	// デバイスの設定
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;	// 相対値モードで設定（絶対値はDIPROPAXISMODE_ABS）

	if (FAILED(g_pKeyDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// デバイスの設定に失敗
		return false;
	}

	// 入力制御開始
	g_pKeyDevice->Acquire();

	return true;
}


bool CreateKeyboardDevice()
{
	// マウス用にデバイスオブジェクトを作成
	if (FAILED(g_InputInterface->CreateDevice(GUID_SysMouse, &g_MouseDevice, nullptr)))
	{
		// デバイスの作成に失敗
		return false;
	}

	// データフォーマットを設定
	if (FAILED(g_MouseDevice->SetDataFormat(&c_dfDIMouse)))
	{
		// データフォーマットに失敗
		return false;
	}

	// モードを設定（フォアグラウンド＆非排他モード）
	if (FAILED(g_MouseDevice->SetCooperativeLevel(
		FindWindowA(WINDOW_CLASS_NAME, nullptr),
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		// モードの設定に失敗
		return false;
	}

	// デバイスの設定
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;	// 相対値モードで設定（絶対値はDIPROPAXISMODE_ABS）

	if (FAILED(g_MouseDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// デバイスの設定に失敗
		return false;
	}

	// 入力制御開始
	g_MouseDevice->Acquire();

	return true;
}

bool GetKey(DWORD key_code)
{
	return g_InputState.now& key_code;
}

bool GetKeyDown(DWORD key_code)
{
	return g_InputState.trg& key_code;
}

bool GetKeyUp(DWORD key_code)
{
	return g_InputState.ntrg& key_code;
}
