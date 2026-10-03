#ifndef SCENE_MENU_HPP
#define SCENE_MENU_HPP

#include "game_draw/scene.hpp"

// The scene_menu class represents the main menu scene of the game. It
// inherits from the base scene class and implements the update and
// render methods specific to the menu.
class scene_menu : public scene
{
public:
    update_return update() override;
    void render() override;
} inline menu_object; // Inline instance of scene_menu.

#endif