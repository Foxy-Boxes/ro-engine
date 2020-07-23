#pragma once
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_joystick.h>
#include <bitset>
#include "math/Vector2d.h"
#include "../tools/SingleUseString.h"
class Input
{
private:
    /* data */
    SDL_Event* m_event_pointer;
    Uint32 MouseState;
    std::bitset<5> mousebits;
    std::bitset<5> lastmousebits;
    std::bitset<5> pressedmousebits;
    std::bitset<5> releasedmousebits;
    int x,y;
    const Uint8* KeyboardState;
    std::bitset<512> keyboardbits;
    std::bitset<512> lastkeyboardbits;
    std::bitset<512> pressedkeyboardbits;
    std::bitset<512> releasedkeyboardbits;
    int numkeys;
public:
    Input(SDL_Event*);
    void update();
    bool getKey(SDL_Scancode);
    bool getKeyPressed(SDL_Scancode);
    bool getKeyReleased(SDL_Scancode);
    bool getMouse(Uint8);
    bool getMousePressed(Uint8);
    bool getMouseReleased(Uint8);
    int getMouseX();
    int getMouseY();
    SingleUseString* getPosStr();
    SingleUseString* getPosStr(char);
    SingleUseString* getPosStr(const char*);
    SingleUseString* getPosStr(const char* ,const char* ,const char*);
    Vector2d* getPosVec();
};
