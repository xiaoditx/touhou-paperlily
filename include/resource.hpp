#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "thp.hpp"
#include "gameHeader.hpp"

namespace thp
{
    // Resource manager class.
    class res_manager
    {
    private:
        // Constructor and destructor are all private,
        // so that only thp_init() can create and destroy
        // the resource manager.
        res_manager(HWND hwnd);
        ~res_manager();

    public:
        ID2D1Factory *factory = nullptr;
        ID2D1HwndRenderTarget *renderTarget = nullptr;
        ID2D1Bitmap *bitmap = nullptr;
        friend void thp_init();
        friend void thp_end();
    };

    inline res_manager *resource;
}

#endif // RESOURCE_HPP