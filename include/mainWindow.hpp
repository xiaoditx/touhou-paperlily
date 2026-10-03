#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "thp.hpp"
#include <windows.h>

namespace thp
{
    // The main_window class encapsulates the creation and
    // management of the main application window.
    class main_window
    {
    private:
        HWND hwnd_;
        // Constructor and destructor are private to control
        // instantiation. It can only be created by the
        // thp_init function.
        main_window();
        ~main_window();
        static LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    public:
        // Provides an inline method to retrieve the window handle (HWND).
        // This allows other parts of the application to access the window
        // handle such as for rendering or message handling.
        inline HWND get_hwnd() const { return hwnd_; };
        friend void thp_init();
    };

    // Global pointer to the main_window instance.
    inline main_window *main_wnd = nullptr;
}

#endif // MAINWINDOW_HPP