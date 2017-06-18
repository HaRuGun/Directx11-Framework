#include "stdafx.h"


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass";

	RegisterClassEx(&wc);

	RECT wr = { 0, 0, 1280, 720 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(NULL, "WindowClass", "Framework DX11", WS_OVERLAPPEDWINDOW,
		100, 50, wr.right - wr.left, wr.bottom - wr.top, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	MSG msg = { 0 };

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) break;
		}
		else
		{
			//RUN
		}
	}

	return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}