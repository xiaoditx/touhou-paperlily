/* FILE: game_draw/gd_main.cpp
-----------------------------------------------------------------
    This file is the manager of all scenes. With a update() function, it
    will smartly route the update request to the current scene.
*/

#include "game_draw/scene_menu.hpp"
#include <functional>

namespace
{
    // Array of pointers to all scenes in the game. Each scene is derived
    // from the base scene class and implements its own update and render
    // methods.
    scene *scene_array[] = {&menu_object};
    int current_scene_index = 0; // Index of the currently active scene.
}

namespace thp
{
    void update()
    {
        // Call the update method of the currently active scene.
        auto ret = scene_array[current_scene_index]->update();
        // Handle the return value from the scene's update method to
        // determine if the scene index should change.
        switch (ret)
        {
        case update_return::NO_CHANGE:
            // No change in scene index; do nothing.
            break;
        case update_return::INDEX_INCREASE:
            // Increase the scene index, wrapping around if necessary.
            current_scene_index = (current_scene_index + 1) % (sizeof(scene_array) / sizeof(scene_array[0]));
            break;
        case update_return::INDEX_DECREASE:
            // Decrease the scene index, wrapping around if necessary.
            current_scene_index = (current_scene_index - 1 + (sizeof(scene_array) / sizeof(scene_array[0]))) % (sizeof(scene_array) / sizeof(scene_array[0]));
            break;
        case update_return::INDEX_SWITCH_TO_0:
            // Switch to the first scene (index 0).
            current_scene_index = 0;
            break;
        }
    }
}