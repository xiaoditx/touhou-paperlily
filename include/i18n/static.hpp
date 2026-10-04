/* i18n/static.hpp
-------------------------------------------------------------------------
This file provide the i18n ability to all the static datas used in application
that can hardly be wrote into a isolate file to achieve more flexible i18n
supply such as the erro string showed in exception class.
*/

namespace thp
{
    constexpr wchar_t *EN_ERRO_CO_INIT = L"Fail to initialize COM library.";
    constexpr wchar_t *EN_ERRO_THP_INIT_MUL = L"The \"htp_init\" function has been called multiple times without cleanup.";
    constexpr wchar_t *CN_ERRO_CO_INIT = L"COM库初始化失败";
    constexpr wchar_t *CN_ERRO_THP_INIT_MUL = L"函数 \"htp_init\" 在资源未清理的条件下被多次调用";

}