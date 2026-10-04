#include "thp.hpp"
#include "resource.hpp"
#include "mainWindow.hpp"
#include "loop.hpp"

namespace thp
{
    void thp_init()
    {
        // Initialize the COM library.
        if (FAILED(CoInitialize(NULL)))
            throw std::runtime_error("Fail to initialize COM library");

        // Ensure that thp_init is called only once and that the main
        // window and resource manager are not already initialized.
        assert(main_wnd == nullptr);
        assert(resource == nullptr);
        if (main_wnd != nullptr || resource != nullptr)
        {
            throw std::runtime_error("thp_init called multiple times without cleanup.");
        }
        // Initialize resources and main window.
        main_wnd = new main_window();
        resource = new res_manager(main_wnd->get_hwnd());
        // Start the game loop (message loop).
        start_loop();
    }
}