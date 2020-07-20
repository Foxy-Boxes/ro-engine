#pragma once
#include <SDL2/SDL.h>
#include "../tools/SingleUseString.h"
#include <iostream>
class Window
{
private:
    /* data */
    int width;
    int height;
    char* p_label;
    Uint32 flag;
    SDL_Window *screen;
    SDL_Renderer **p_renderer;
    bool fullscreen;
public:
    Window(const char*, bool);
    Window(SingleUseString*, bool);
    void initWindow(int, int, Uint32);
    void initWindow(Uint32);
    void initWindow();
    void clearWindow();
    void clearWindow(int, int, int, int);
    void render();
    int getHeight();
    int getWidth();
    SingleUseString* getLabel();
    void setFullscreen(bool);
    SDL_Renderer** getRendererPointer();
};