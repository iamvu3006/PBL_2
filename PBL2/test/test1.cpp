#include <windows.h>

// Khai báo hàm xử lý thông điệp
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Đăng ký lớp cửa sổ
void RegisterWindowClass(HINSTANCE hInstance);

// Tạo cửa sổ
HWND CreateMainWindow(HINSTANCE hInstance);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Đăng ký lớp cửa sổ
    RegisterWindowClass(hInstance);

    // Tạo cửa sổ chính
    HWND hwnd = CreateMainWindow(hInstance);

    if (hwnd == NULL) {
        return 0;
    }

    // Hiển thị cửa sổ
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Vòng lặp xử lý thông điệp
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

void RegisterWindowClass(HINSTANCE hInstance) {
    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = "SimpleWindowClass";

    RegisterClass(&wc);
}

HWND CreateMainWindow(HINSTANCE hInstance) {
    return CreateWindow(
        "SimpleWindowClass",     // Tên lớp cửa sổ
        "Simple GUI Application", // Tiêu đề cửa sổ
        WS_OVERLAPPEDWINDOW,      // Kiểu cửa sổ
        CW_USEDEFAULT,            // Vị trí X
        CW_USEDEFAULT,            // Vị trí Y
        500,                      // Chiều rộng
        400,                      // Chiều cao
        NULL,                     // Không có cửa sổ cha
        NULL,                     // Không có menu
        hInstance,                // Thực thể của ứng dụng
        NULL                      // Không có tham số tạo cửa sổ bổ sung
    );
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // Tạo một nút bấm
            CreateWindow(
                "BUTTON",         // Kiểu điều khiển
                "Click Me",       // Văn bản trên nút
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Kiểu nút
                20,               // Vị trí X
                20,               // Vị trí Y
                100,              // Chiều rộng
                30,               // Chiều cao
                hwnd,             // Cửa sổ cha
                (HMENU) 1,        // ID của nút
                (HINSTANCE) GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Thực thể của ứng dụng
                NULL              // Không có tham số tạo điều khiển bổ sung
            );
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                MessageBox(hwnd, "Button clicked!", "Information", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
