#pragma once

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720

struct VERTEX
{
	FLOAT x, y, z;
	D3DXCOLOR Color;
};

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);