#include <loop.hpp>
#include <windows.h>
#include <stdexcept>
#include <thread>

namespace
{
    enum class loop_return : bool
    {
        // This enum class defines return codes for the message loop.
        // It can be extended in the future to include more specific
        // error codes.(If so, we should also change the enum type
        // to int or another suitable type, but for now, bool is
        // sufficient.)
        QUIT = 1,  // Indicates that a WM_QUIT message was received.
        NORMAL = 0 // Indicates that the loop is still running normally.
    };
}

namespace thp
{
    // When performing long-running operations, call this
    // function periodically to process pending messages.
    //
    // warning: Must be careful about preventing reentrancy
    // issues when calling this function.
    loop_return pump_pending_messages()
    {
        MSG msg;
        // Using PM_REMOVE ensures that messages are
        // removed from the queue after processing
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            // When encountering WM_QUIT, special handling is
            // needed, usually to exit the entire operation
            if (msg.message == WM_QUIT)
            {
                // Indicate that a quit message was received
                return loop_return::QUIT;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return loop_return::NORMAL; // Default return value
    }

    // This function starts the main message loop for the application.
    void start_loop()
    {
        // Initialize variables for time tracking and frame rate control.
        double accumulator = 0.0;
        LARGE_INTEGER freq, last_time, current_time;
        // Retrieve the frequency of the high-resolution performance
        // counter (ticks/second).
        QueryPerformanceFrequency(&freq);
        // Initialize the last frame time (ticks).
        QueryPerformanceCounter(&last_time);
        // Fix the time step to 1/60 seconds (60 FPS).
        // In the future, we may consider using a variable time step.
        const double FIXED_DT = 1.0 / 60.0;

        // Define a boolean signal to control the loop's execution.
        // It will be set to false when a quit message is received.
        bool running = true;
        while (running)
        {
            // Process any pending messages in the message queue.
            // If a quit message was received, set the running
            // flag to false to exit the loop.
            if (pump_pending_messages() == loop_return::QUIT)
                running = false;

            // Calculate the time elapsed since the last frame.
            QueryPerformanceCounter(&current_time);
            // The deltaTime is calculated in seconds, and the
            // loop aims to maintain a frame rate of 60 FPS.
            // In there passed time is passed count divided by
            // frequency, which is the number of counts per second.
            double deltaTime = (double)(current_time.QuadPart - last_time.QuadPart) / freq.QuadPart;

            // Clamp deltaTime to a maximum of 0.25 seconds to avoid
            // issues with very large time steps, which can occur if
            // the application is paused or debugged or running slowly.
            if (deltaTime > 0.25)
                deltaTime = 0.25;

            // Accumulate the deltaTime to control the update rate.
            accumulator += deltaTime;
            // Loop until the accumulator is less than the fixed time
            // step (FIXED_DT) to update the game state at a consistent
            // rate.
            while (accumulator >= FIXED_DT)
            {
                // update_game(deltaTime);
                last_time = current_time;
                accumulator -= FIXED_DT;
            }

            // Sleep for 1 millisecond to reduce CPU usage.
            std::this_thread::sleep_for(
                std::chrono::milliseconds(1));
        }
    }
}