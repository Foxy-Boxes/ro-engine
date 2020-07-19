#include "Vertex.h"
    Vertex::Vertex(Vector3d* p_v){
        p_posVec = p_v;
    }
    double Vertex::getX(){
        return p_posVec -> getX();
    }
    double Vertex::getY(){
        return p_posVec -> getY();
    }
    double Vertex::getZ(){
        return p_posVec -> getZ();
    }
    Vector3d* Vertex::getVec(){
        return p_posVec;
    }
    void Vertex::setX(double x){
        p_posVec -> setX(x);
    }
    void Vertex::setY(double y){
        p_posVec -> setY(y);
    }
    void Vertex::setZ(double z){
        p_posVec -> setZ(z);
    }
    void Vertex::incX(double x){
        p_posVec -> setX(p_posVec ->getX()+ x);
    }
    void Vertex::incY(double y){    
        p_posVec -> setY(p_posVec ->getY()+ y);
    }
    void Vertex::incZ(double z){    
        p_posVec -> setZ(p_posVec ->getZ()+ z);
    }