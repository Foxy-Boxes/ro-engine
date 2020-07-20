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
    void Mesh::drawMesh(Window* w,Matrix44* matProj, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
        Uint8 *pr,*pg,*pb,*pa,rv=230,gv=255,bv=255,av=255;
        pr = &rv; pg = &gv; pb = &bv; pa = &av;
        SDL_GetRenderDrawColor(*w->getRendererPointer(),pr,pg,pb,pa);
        SDL_SetRenderDrawColor(*w->getRendererPointer(),r,g,b,a);
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
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
        SDL_SetRenderDrawColor(*w->getRendererPointer(),*pr,*pg,*pb,*pa);
    }
    void Mesh::drawMesh(Window* w,Matrix44* matProj){
        Uint8 *pr,*pg,*pb,*pa,r=230,g=255,b=255,a=255;
        pr = &r; pg = &g; pb = &b; pa = &a;
        SDL_GetRenderDrawColor(*w->getRendererPointer(),pr,pg,pb,pa);
        SDL_SetRenderDrawColor(*w->getRendererPointer(),0,0,0,255);
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
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
        SDL_SetRenderDrawColor(*w->getRendererPointer(),*pr,*pg,*pb,*pa);
    }
    void Mesh::resetMesh(){
        if(p_triangles)
            p_triangles->clear();
    }
    Mesh& Mesh::translateMesh(double x, double y, double z){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> incX(x);
            (*it) -> getVertex(1) -> incX(x);
            (*it) -> getVertex(2) -> incX(x);
            (*it) -> getVertex(0) -> incY(y);
            (*it) -> getVertex(1) -> incY(y);
            (*it) -> getVertex(2) -> incY(y);
            (*it) -> getVertex(0) -> incZ(z);
            (*it) -> getVertex(1) -> incZ(z);
            (*it) -> getVertex(2) -> incZ(z);
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh(double x, double y, double z){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(x * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setX(x * (*it) -> getVertex(1) -> getX());
            (*it) -> getVertex(2) -> setX(x * (*it) -> getVertex(2) -> getX());
            (*it) -> getVertex(0) -> setY(y * (*it) -> getVertex(0) -> getY());
            (*it) -> getVertex(1) -> setY(y * (*it) -> getVertex(1) -> getY());
            (*it) -> getVertex(2) -> setY(y * (*it) -> getVertex(2) -> getY());
            (*it) -> getVertex(0) -> setZ(z * (*it) -> getVertex(0) -> getZ());
            (*it) -> getVertex(1) -> setZ(z * (*it) -> getVertex(1) -> getZ());
            (*it) -> getVertex(2) -> setZ(z * (*it) -> getVertex(2) -> getZ());
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh(double r){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(r * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setX(r * (*it) -> getVertex(1) -> getX());
            (*it) -> getVertex(2) -> setX(r * (*it) -> getVertex(2) -> getX());
            (*it) -> getVertex(0) -> setY(r * (*it) -> getVertex(0) -> getY());
            (*it) -> getVertex(1) -> setY(r * (*it) -> getVertex(1) -> getY());
            (*it) -> getVertex(2) -> setY(r * (*it) -> getVertex(2) -> getY());
            (*it) -> getVertex(0) -> setZ(r * (*it) -> getVertex(0) -> getZ());
            (*it) -> getVertex(1) -> setZ(r * (*it) -> getVertex(1) -> getZ());
            (*it) -> getVertex(2) -> setZ(r * (*it) -> getVertex(2) -> getZ());
        }
        return *this;
    }
    Mesh& Mesh::translateMesh2D(double x, double y){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> incX(x);
            (*it) -> getVertex(1) -> incX(x);
            (*it) -> getVertex(0) -> incY(y);
            (*it) -> getVertex(1) -> incY(y);
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh2D(double x, double y){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(x * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setX(x * (*it) -> getVertex(1) -> getX());
            (*it) -> getVertex(0) -> setY(y * (*it) -> getVertex(0) -> getY());
            (*it) -> getVertex(1) -> setY(y * (*it) -> getVertex(1) -> getY());
        }
        return *this;
    }
    Mesh& Mesh::scaleMesh2D(double r){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        for(;it < p_triangles -> end(); it++){
            (*it) -> getVertex(0) -> setX(r * (*it) -> getVertex(0) -> getX());
            (*it) -> getVertex(1) -> setX(r * (*it) -> getVertex(1) -> getX());
            (*it) -> getVertex(0) -> setY(r * (*it) -> getVertex(0) -> getY());
            (*it) -> getVertex(1) -> setY(r * (*it) -> getVertex(1) -> getY());
        }
        return *this;
    }
    Mesh* Mesh::transformMesh(Mesh* outMesh, Matrix44* t_matrix){
        std::vector<Triangle*>::iterator it = p_triangles -> begin();
        outMesh -> resetMesh();
        for(;it < p_triangles -> end(); it++){
            Triangle* joseph = new Triangle(new Vertex((*it) -> getVertex(0) -> getVec() -> mulwithMatrix(t_matrix))
            ,new Vertex((*it) -> getVertex(1) -> getVec() -> mulwithMatrix(t_matrix))
            ,new Vertex((*it) -> getVertex(2) -> getVec() -> mulwithMatrix(t_matrix)));
            //printf("%lf , ",joseph -> getVertex(0) ->getX());
            //printf("%lf \n",joseph -> getVertex(0) ->getY());
            //printf("%lf , ",joseph -> getVertex(1) ->getX());
            //printf("%lf \n",joseph -> getVertex(1) ->getY());
            //printf("%lf , ",joseph -> getVertex(2) ->getX());
            //printf("%lf \n",joseph -> getVertex(2) ->getY());
            //printf("==========================\n");
            outMesh->addTriangle(joseph);
        }
        return outMesh;
    }
    int Mesh::getTriCount(){
        return p_triangles -> size();
    }