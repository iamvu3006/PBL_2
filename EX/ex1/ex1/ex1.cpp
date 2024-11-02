#include <windows.h>
#include <strsafe.h> // Thêm thư viện này

// Định nghĩa hàm callback WindowProc
LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        // Tạo các ô nhập liệu
        CreateWindow(TEXT("STATIC"), TEXT("First Name:"), WS_VISIBLE | WS_CHILD,
            10, 10, 80, 20, hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
            100, 10, 200, 20, hwnd, (HMENU)1, NULL, NULL);

        CreateWindow(TEXT("STATIC"), TEXT("Last Name:"), WS_VISIBLE | WS_CHILD,
            10, 40, 80, 20, hwnd, NULL, NULL, NULL);
        CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
            100, 40, 200, 20, hwnd, (HMENU)2, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("Submit"), WS_VISIBLE | WS_CHILD,
            100, 70, 80, 25, hwnd, (HMENU)3, NULL, NULL);
        return 0;

    case WM_COMMAND:
        if (LOWORD(wParam) == 3) // Submit button được nhấn
        {
            wchar_t firstName[100];
            wchar_t lastName[100];

            // Lấy dữ liệu từ các ô nhập liệu
            GetWindowText(GetDlgItem(hwnd, 1), firstName, 100);
            GetWindowText(GetDlgItem(hwnd, 2), lastName, 100);

            // Hiển thị tên đầy đủ trong một MessageBox
            wchar_t fullName[200];
            StringCchPrintf(fullName, sizeof(fullName) / sizeof(fullName[0]), L"Full Name: %s %s", firstName, lastName);
            MessageBox(hwnd, fullName, TEXT("Submitted Name"), MB_OK);
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Name Input Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 320, 150,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
