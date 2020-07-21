#include "Vertex.h"
    Vertex::Vertex(double x,double y,double z){
        this -> setX(x);
        this -> setY(y);
        this -> setZ(z);
        this -> updateLength();
    }
    Vertex::Vertex(Vector3d* V){
        this -> setX(V -> getX());
        this -> setY(V -> getY());
        this -> setZ(V -> getZ());
        this -> updateLength();
        delete[] V;
    }
    void Vertex::incX(double vx){
        this -> setX(this ->getX() + vx);
    }
    void Vertex::incY(double vy){    
        this -> setY(this ->getY() + vy);
    }
    void Vertex::incZ(double vz){    
        this -> setZ(this ->getZ() + vz);
    }