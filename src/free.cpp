#include "thp.hpp"
#include "resource.hpp"
#include "mainWindow.hpp"

namespace thp
{
    void thp_end()
    {
        if (resource)
        {
            delete resource;
            resource = nullptr;
        }
        if (main_wnd)
        {
            delete main_wnd;
            main_wnd = nullptr;
        }
        CoUninitialize();
    }
}