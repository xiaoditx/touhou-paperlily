#include "resource.hpp"

namespace thp
{
    res_manager::res_manager(HWND hwnd)
    {
        D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
        factory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(hwnd),
            &renderTarget);
        // renderTarget->CreateBitmap();
    }
}