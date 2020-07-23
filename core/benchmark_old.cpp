//this is part of a benchmark test on mesh implementations.
#include <SDL2/SDL.h>
#include <iostream>
#include "Time.h"
#include "Input.h"
#include "../render/TextureManager.h"
#include "../tools/Log.h"
#include "math/Mesh.h"

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
    Time  timeinstance(600000);
    Log loginstance;
    bool running = true;
    int frames = 0;
    double dtheta = 0;
    Matrix44 matRotZ, matRotX, matProj;
    matRotZ.initIdentity(); matRotX.initIdentity(); matProj.initProjection(&windowinstance, 0.1, 1000.0, 90.0);
    long int counter = 0;
    bool render;
    time_t start = timeinstance.start();
    while (running)
    {
        render = false;
        timeinstance.update();
        while (timeinstance.frame()){
            dtheta = (dtheta > 360.0) ? (dtheta - 360.0) : (dtheta + 10 * timeinstance.getDelta());
            render = true;
            matRotZ.setVal(0,0,cos(dtheta));
            matRotZ.setVal(0,1,sin(dtheta));
            matRotZ.setVal(1,0,-sin(dtheta));
            matRotZ.setVal(1,1,cos(dtheta));
            matRotX.setVal(1,1,cos(dtheta * 0.5));
            matRotX.setVal(1,2,sin(dtheta * 0.5));
            matRotX.setVal(2,1,-sin(dtheta * 0.5));
            matRotX.setVal(2,2,cos(dtheta * 0.5));
        }
        if(render){
            counter++;
            windowinstance.render();
            texmexinstance.render();
            Cube.transformMesh(&CubeAnimated,matRotZ.mul(&matRotX)) -> translateMesh(0,0,8);
            CubeAnimated.drawMesh(&windowinstance, &matProj);
            if(counter > (1 << 16)){
                std::cout << "Average FPS is : " << (double)counter/timeinstance.getTimepassed_from(start) << std::endl;
                std::cout << "Elapsed time is : " << timeinstance.getTimepassed_from(start) << std::endl;
                running = 0;
                break;
        }
        }
        
    }
}