#include "Triangle.h"
    Triangle::Triangle(Vertex* v1,Vertex* v2,Vertex* v3){
        points[0] = v1;
        points[1] = v2;
        points[2] = v3;
    }
    Triangle::~Triangle(){
        delete points[0];
        delete points[1]; 
        delete points[2];
    }  
    void Triangle::drawTri(Window* w){
        SDL_Renderer** p_renderer = w -> getRendererPointer();
        SDL_RenderDrawLine(*p_renderer, points[0]->getX(), points[0]->getY(), points[1]->getX(), points[1]->getY());
        SDL_RenderDrawLine(*p_renderer, points[1]->getX(), points[1]->getY(), points[2]->getX(), points[2]->getY());
        SDL_RenderDrawLine(*p_renderer, points[2]->getX(), points[2]->getY(), points[0]->getX(), points[0]->getY());
    }
    Vertex* Triangle::getVertex(int i){
        return points[i];
    }
    Vector3d* Triangle::NormalizedNormal(){
        Vector3d line1(points[1]->getX()-points[0]->getX(),points[1]->getY()-points[0]->getY(),points[1]->getZ()-points[0]->getZ());
        Vector3d line2(points[2]->getX()-points[0]->getX(),points[2]->getY()-points[0]->getY(),points[2]->getZ()-points[0]->getZ());
        return &(line1.cross(&line2) -> normalize());
    }