#include <SDL2/SDL.h>
#include <iostream>
#include "Time.h"
#include "Input.h"
#include "../render/TextureManager.h"
#include "../tools/Log.h"
#include "Mesh.h"

int main(void){
    SDL_Init(SDL_INIT_EVERYTHING);
    Window windowinstance("Game Window", false);
    //windowinstance.clearWindow();//you shouldnt do this of course.
    /*'cause you need to init first*/
    windowinstance.initWindow(900,700,SDL_WINDOW_SHOWN);
    TextureManager texmexinstance(&windowinstance);
    texmexinstance.addTop(texmexinstance.createTexture("../assets/boi.png")->setDest(64,64));
    windowinstance.clearWindow(230, 255, 255, 255);
    Vertex* ver[12][3] = {  {new Vertex(0.0,0.0,0.0), new Vertex(0.0,1.0,0.0), new Vertex(1.0,1.0,0.0)},
                            {new Vertex(0.0,0.0,0.0), new Vertex(1.0,1.0,0.0), new Vertex(1.0,0.0,0.0)},
                            {new Vertex(1.0,0.0,0.0), new Vertex(1.0,1.0,0.0), new Vertex(1.0,1.0,1.0)},
                            {new Vertex(1.0,0.0,0.0), new Vertex(1.0,1.0,1.0), new Vertex(1.0,0.0,1.0)},
                            {new Vertex(1.0,0.0,1.0), new Vertex(1.0,1.0,1.0), new Vertex(0.0,1.0,1.0)},
                            {new Vertex(1.0,0.0,1.0), new Vertex(0.0,1.0,1.0), new Vertex(0.0,0.0,1.0)},
                            {new Vertex(0.0,0.0,1.0), new Vertex(0.0,1.0,1.0), new Vertex(0.0,1.0,0.0)},
                            {new Vertex(0.0,0.0,1.0), new Vertex(0.0,1.0,0.0), new Vertex(0.0,0.0,0.0)},
                            {new Vertex(0.0,1.0,0.0), new Vertex(0.0,1.0,1.0), new Vertex(1.0,1.0,1.0)},
                            {new Vertex(0.0,1.0,0.0), new Vertex(1.0,1.0,1.0), new Vertex(1.0,1.0,0.0)},
                            {new Vertex(1.0,0.0,1.0), new Vertex(0.0,0.0,1.0), new Vertex(0.0,0.0,0.0)},
                            {new Vertex(1.0,0.0,1.0), new Vertex(0.0,0.0,0.0), new Vertex(1.0,0.0,0.0)}};
    Triangle* tri[12] = {new Triangle(ver[0][0],ver[0][1],ver[0][2]),
                        new Triangle(ver[1][0],ver[1][1],ver[1][2]),
                        new Triangle(ver[2][0],ver[2][1],ver[2][2]),
                        new Triangle(ver[3][0],ver[3][1],ver[3][2]), 
                        new Triangle(ver[4][0],ver[4][1],ver[4][2]),
                        new Triangle(ver[5][0],ver[5][1],ver[5][2]),
                        new Triangle(ver[6][0],ver[6][1],ver[6][2]),
                        new Triangle(ver[7][0],ver[7][1],ver[7][2]),
                        new Triangle(ver[8][0],ver[8][1],ver[8][2]),
                        new Triangle(ver[9][0],ver[9][1],ver[9][2]),
                        new Triangle(ver[10][0],ver[10][1],ver[10][2]),
                        new Triangle(ver[11][0],ver[11][1],ver[11][2])};
    Mesh Cube(tri,12);
    Mesh CubeAnimated;
    Cube.scaleMesh(2.0);
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
    double dtheta = 0;
    Matrix44 matRotZ, matRotX, matProj;
    matRotZ.initIdentity(); matRotX.initIdentity(); matProj.initProjection(&windowinstance, 0.1, 1000.0, 90.0);
    long double framecounter = 0;
    timeinstance.start();
    while (running)
    {
        
        
        framecounter += timeinstance.update();
        while (timeinstance.frame())
        {
            frames++;
            dtheta = (dtheta > 360.0) ? (dtheta - 360.0) : (dtheta + 0.01);

            matRotZ.setVal(0,0,cos(dtheta));
            matRotZ.setVal(0,1,sin(dtheta));
            matRotZ.setVal(1,0,-sin(dtheta));
            matRotZ.setVal(1,1,cos(dtheta));
            matRotX.setVal(1,1,cos(dtheta * 0.5));
            matRotX.setVal(1,2,sin(dtheta * 0.5));
            matRotX.setVal(2,1,-sin(dtheta * 0.5));
            matRotX.setVal(2,2,cos(dtheta * 0.5));
            
            Cube.transformMesh(&CubeAnimated,matRotZ.mul(&matRotX)) -> translateMesh(0,0,8);
            SDL_PollEvent(&event);
            windowinstance.render();
            texmexinstance.render();
            
            CubeAnimated.drawMesh(&windowinstance, &matProj);

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