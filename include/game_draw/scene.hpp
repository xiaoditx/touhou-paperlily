#ifndef SCENE_HPP
#define SCENE_HPP

#include "thp.hpp"
#include "gameHeader.hpp"

enum class update_return : char
{

    NO_CHANGE,         // Indicates that the manager function should remain unchanged.
    INDEX_INCREASE,    // Indicates that the scene index should be increased.
    INDEX_DECREASE,    // Indicates that the scene index should be decreased.
    INDEX_SWITCH_TO_0, // Indicates that the scene index should be switched to 0.
};

// The scene class serves as a ABC for all scenes in the game to more
// convenient to manage. It provides a common interface for updating
// and rendering game scenes.
class scene
{
public:
    virtual update_return update() = 0;
    virtual void render() = 0;
};

#endif