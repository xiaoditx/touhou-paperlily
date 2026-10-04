/* thp.hpp
------------------------------------------------
thp.hpp is the header file that all the code file should include directly
or indirectly. It provides the necessary macros, helper functions,header
files and some constants to simplify the establish of new code file.
*/

#ifndef THP_HPP
#define THP_HPP

// Macros that used to conditional compilation

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

// Headers that important for debuging
#include <cassert>
// include <yumo/debug.hpp>

// Other important headers
#include <stdexcept>

// Only prepared for main.cpp
// todo : Clean these functions out to a isolate file.
namespace thp
{
    void thp_init();
    void thp_end();
} // namespace thp

#endif // THP_HPP