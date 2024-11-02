#include <windows.h>
#include <wchar.h>
#include <commctrl.h>

#define ID_BUTTON 2307

LRESULT CALLBACK winproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	static HWND listview;
	static HWND hbutton;
	static HWND hstatic;
	switch (msg)
	{
	case WM_CREATE:

		InitCommonControls();

		hbutton = CreateWindowEx
		(
			0,
			L"BUTTON",
			L"NHAN DE TIEP TUC`",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			50, 150, 
			100, 30,  
			hwnd,
			(HMENU)ID_BUTTON,
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
			NULL
		);

		hstatic = CreateWindowEx
		(
			0,
			L"STATIC",
			L"CHAO MUNG DEN VOI PBL2",
			WS_CHILD | WS_VISIBLE | SS_CENTER,
			50, 50,   
			200, 50,  
			hwnd,
			NULL,
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
			NULL
		);
		return 0;

	case WM_COMMAND:
		if (LOWORD(wparam) == ID_BUTTON)  
		{
			listview = CreateWindowEx
			(
				0,
				WC_LISTVIEW,
				NULL,
				WS_CHILD | WS_VISIBLE | LVS_REPORT,
				500, 500,
				200, 200,
				hwnd,
				NULL,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
				NULL
			);
		}
		return 0;

	case WM_CLOSE:
		if (MessageBox(hwnd, L"ban co muon thoat", L"Xac nhan", MB_OKCANCEL) == IDOK)
			DestroyWindow(hwnd);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}

int WINAPI WinMain(HINSTANCE current_instance, HINSTANCE pre_instance, LPSTR lpstr, int nCmdShow)
{
	const wchar_t firstprogram[] = L"FirstDemoPBL2";
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = current_instance;
	wc.lpszClassName = firstprogram;
	wc.lpfnWndProc = winproc;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"khong the dang ky lop", L"Loi", MB_OKCANCEL);
		return 0;
	}


	HWND hwnd = CreateWindowEx(
		0,
		firstprogram,
		L"FIRSTPROGRAMTEST",
		WS_POPUP | WS_SYSMENU | WS_BORDER | WS_VISIBLE,
		300, 300,
		600, 300,
		NULL,
		NULL,
		current_instance,
		NULL
	);

	if (!hwnd)
	{
		DWORD error = GetLastError();
		wchar_t msg[256];
		swprintf(msg, 256, L"KHÔNG TH? T?O C?A S?! Mã l?i: %lu", error);
		MessageBox(NULL, msg, L"L?i", MB_OK | MB_ICONERROR);
		return 0;
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
