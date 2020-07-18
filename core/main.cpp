#include <SDL2/SDL.h>
#include <iostream>
#include "Time.h"
#include "Input.h"
#include "../tools/Log.h"

int main(void){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *screen = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
                          SDL_SWSURFACE);
    SDL_Event event;
    Input inputinstance(&event);
    Time  timeinstance(60);
    Log loginstance;
    bool running = true;
    int frames = 0;
    long double framecounter = 0;
    timeinstance.start();
    while (running)
    {
        
        
        framecounter += timeinstance.update();
        while (timeinstance.frame())
        {
            frames++;
            SDL_PollEvent(&event);

            inputinstance.update();
            if(inputinstance.getKey(SDL_SCANCODE_ESCAPE)){
                running = 0;
                break;
            }
            if(inputinstance.getKeyPressed(SDL_SCANCODE_UP)){
                loginstance.print("you have pressed up");
            }
            if(inputinstance.getKeyReleased(SDL_SCANCODE_UP)){
                loginstance.print("you have released up");
            }
            if(inputinstance.getMousePressed(SDL_BUTTON_LEFT)){
                loginstance.print("you have pressed left mouse button");
            }
            if(inputinstance.getMouseReleased(SDL_BUTTON_LEFT)){
                loginstance.print("you have released left mouse button");
            }
            
            if(framecounter >= 1){
                std::cout << frames << std::endl;
                loginstance.print(inputinstance.getPosStr("< X:", " | Y:"," >"));
                frames=0;
                framecounter=0;
            }
        }
        
    }
    
}