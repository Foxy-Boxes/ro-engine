#include <SDL2/SDL.h>
#include <iostream>
#include "Time.h"
#include "Input.h"
#include "../render/Window.h"
#include "../render/TextureManager.h"
#include "../tools/Log.h"

int main(void){
    SDL_Init(SDL_INIT_EVERYTHING);
    Window windowinstance("Game Window", false);
    //windowinstance.clearWindow();//you shouldnt do this of course.
    /*'cause you need to init first*/
    windowinstance.initWindow(900,700,SDL_WINDOW_SHOWN);
    TextureManager texmexinstance(windowinstance.getRenderer());
    texmexinstance.addTop(texmexinstance.createTexture("../assets/boi.png")->setDest(64,64));
    windowinstance.clearWindow(255, 255, 255, 255);
    /*SDL_Window *screen = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
                          SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    Window Object handles these now;
    */
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
            texmexinstance.render();


            inputinstance.update();
            if(inputinstance.getKey(SDL_SCANCODE_ESCAPE)){
                running = 0;
                break;
            }
            if(inputinstance.getKeyPressed(SDL_SCANCODE_UP)){
                texmexinstance.getTexturefromPos(0) -> updatePosY(-2);
                loginstance.print("you have pressed up");
            }
            else if(inputinstance.getKey(SDL_SCANCODE_UP)){
                texmexinstance.getTexturefromPos(0) -> updatePosY(-1);
            }
            if(inputinstance.getKeyReleased(SDL_SCANCODE_UP)){
                loginstance.print("you have released up");
            }
            if(inputinstance.getKeyPressed(SDL_SCANCODE_DOWN)){
                texmexinstance.getTexturefromPos(0) -> updatePosY(2);
                loginstance.print("you have pressed down");
            }
            else if(inputinstance.getKey(SDL_SCANCODE_DOWN)){
                texmexinstance.getTexturefromPos(0) -> updatePosY(1);
            }
            if(inputinstance.getKeyReleased(SDL_SCANCODE_DOWN)){
                loginstance.print("you have released down");
            }
            if(inputinstance.getKeyPressed(SDL_SCANCODE_RIGHT)){
                texmexinstance.getTexturefromPos(0) -> updatePosX(2);
                loginstance.print("you have pressed right");
            }
            else if(inputinstance.getKey(SDL_SCANCODE_RIGHT)){
                texmexinstance.getTexturefromPos(0) -> updatePosX(1);
            }
            if(inputinstance.getKeyReleased(SDL_SCANCODE_RIGHT)){
                loginstance.print("you have released right");
            }
            if(inputinstance.getKeyPressed(SDL_SCANCODE_LEFT)){
                texmexinstance.getTexturefromPos(0) -> updatePosX(-2);
                loginstance.print("you have pressed left");
            }
            else if(inputinstance.getKey(SDL_SCANCODE_LEFT)){
                texmexinstance.getTexturefromPos(0) -> updatePosX(-1);
            }
            if(inputinstance.getKeyReleased(SDL_SCANCODE_LEFT)){
                loginstance.print("you have released left");
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