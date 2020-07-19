#include "Mesh.h"

    Mesh::Mesh(){
        p_triangles = NULL;
    }
    void Mesh::addTriangle(Triangle* p_t){
        if(!p_triangles){
            p_triangles = new std::vector<Triangle*>(1,p_t);
        }
        else{
            p_triangles -> push_back(p_t);
        }
    }
    void Mesh::drawMesh(Window* w,double near,double far,double fov){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        Matrix44* matProj = new Matrix44();
        matProj -> initProjection(w, near, far, fov);
        for(;it < p_triangles -> end(); it++){
            
            Triangle* joseph = new Triangle(new Vertex((*it) -> getVertex(0) -> getVec() -> mulwithMatrix(matProj))
            ,new Vertex((*it) -> getVertex(1) -> getVec() -> mulwithMatrix(matProj))
            ,new Vertex((*it) -> getVertex(2) -> getVec() -> mulwithMatrix(matProj)));

            joseph -> getVertex(0) -> incX(1);
            joseph -> getVertex(0) -> incY(1);
            joseph -> getVertex(1) -> incX(1);
            joseph -> getVertex(1) -> incY(1);
            joseph -> getVertex(2) -> incX(1);
            joseph -> getVertex(2) -> incY(1);

            joseph -> getVertex(0) -> setX(joseph -> getVertex(0) ->getX() * w ->getWidth() * 0.5);
            joseph -> getVertex(0) -> setY(joseph -> getVertex(0) ->getY() * w ->getHeight() * 0.5);
            joseph -> getVertex(1) -> setX(joseph -> getVertex(1) ->getX() * w ->getWidth() * 0.5);
            joseph -> getVertex(1) -> setY(joseph -> getVertex(1) ->getY() * w ->getHeight() * 0.5);
            joseph -> getVertex(2) -> setX(joseph -> getVertex(2) ->getX() * w ->getWidth() * 0.5);
            joseph -> getVertex(2) -> setY(joseph -> getVertex(2) ->getY() * w ->getHeight() * 0.5);

            joseph -> drawTri(w);
        }
    }
    Mesh& Mesh::translateMesh(double x, double y, double z){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> incX(x);
            (*it) -> getVertex(1) -> incY(y);
            (*it) -> getVertex(2) -> incZ(z);
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh(double x, double y, double z){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(x * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setY(y * (*it) -> getVertex(1) -> getY());
            (*it) -> getVertex(2) -> setZ(z * (*it) -> getVertex(2) -> getZ());
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh(double r){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(r * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setY(r * (*it) -> getVertex(1) -> getY());
            (*it) -> getVertex(2) -> setZ(r * (*it) -> getVertex(2) -> getZ());
        }
        return *this;
    }
    Mesh& Mesh::translateMesh2D(double x, double y){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> incX(x);
            (*it) -> getVertex(1) -> incY(y);
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh2D(double x, double y){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(x * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setY(y * (*it) -> getVertex(1) -> getY());
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh2D(double r){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(r * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setY(r * (*it) -> getVertex(1) -> getY());
        }
        return *this;
    }