#include "main.hpp"
#include <exception>

// the main function of the program
// which initializes the application and handles any exceptions that may occur during initialization
int WINAPI wWinMain(
    // the arguments passed to the main function, which are not used in this implementation
    [[maybe_unused]] HINSTANCE, [[maybe_unused]] HINSTANCE,
    [[maybe_unused]] LPWSTR, [[maybe_unused]] int)
{
    // try to initialize the application
    try
    {
        thp::thp_init();
    }
    catch (const std::exception &e)
    {
        // we'll catch all exceptions and show a message box to user now
        // but in the future we may want to catch exceptions more detailed
        // and log this to a file instead
        MessageBoxA(nullptr, e.what(), "Error", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
}