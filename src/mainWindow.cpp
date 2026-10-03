#include "mainWindow.hpp"
#include <stdexcept>

namespace thp
{
    // Constructor for the main_window class.
    // Throws a runtime_error if the window creation fails.
    main_window::main_window()
    {
        LPCWSTR class_name = L"xiaoditx.touhou-paperlily.MainWndClass";

        // Register a window class for the main application window.
        WNDCLASS wc = {0};
        wc.lpfnWndProc = window_proc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = class_name;

        if (!RegisterClass(&wc))
        {
            throw std::runtime_error("Failed to register window class.");
        }

        // Create the main window.
        hwnd_ = CreateWindowEx(
            0,                   // Optional window styles.
            class_name,          // Window class
            L"东方纸百合",       // Window text
            WS_OVERLAPPEDWINDOW, // Window style
            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            nullptr,                  // Parent window
            nullptr,                  // Menu
            GetModuleHandle(nullptr), // Instance handle
            // The following parameter will not be used for ever
            // because there's only one main window in this application.
            nullptr //                   Additional application data
            //          ↑ This weird indentation is to accommodate my formatting plugin
        );

        if (!hwnd_)
        {
            throw std::runtime_error("Failed to create main window.");
        }

        ShowWindow(hwnd_, SW_SHOW);
    }
}