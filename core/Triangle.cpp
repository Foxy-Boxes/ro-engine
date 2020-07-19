#include "Triangle.h"
    Triangle::Triangle(Vertex* v1,Vertex* v2,Vertex* v3){
        points[0] = v1;
        points[1] = v2;
        points[2] = v3;
    }
    void Triangle::drawTri(Window* w){
        SDL_Renderer* renderer = w ->getRenderer();
        SDL_RenderDrawLine(renderer, points[0]->getX(), points[0]->getY(), points[1]->getX(), points[1]->getY());
        SDL_RenderDrawLine(renderer, points[1]->getX(), points[1]->getY(), points[2]->getX(), points[2]->getY());
        SDL_RenderDrawLine(renderer, points[2]->getX(), points[2]->getY(), points[0]->getX(), points[0]->getY());
    }
    Vertex* Triangle::getVertex(int i){
        return points[i];
    }