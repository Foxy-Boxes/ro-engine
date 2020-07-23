#include "Mesh_new.h"

    Mesh_new::Mesh_new(){
        p_Vertices = NULL;
        pos_handle = NULL;
        triangle_count = 0;
        vertex_count = 0;
    }
    void Mesh_new::drawMesh(Window* w,Matrix44* matProj, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
        Uint8 *pr,*pg,*pb,*pa,rv=230,gv=255,bv=255,av=255;
        pr = &rv; pg = &gv; pb = &bv; pa = &av;
        SDL_Renderer* renderer = *w -> getRendererPointer();
        SDL_GetRenderDrawColor(renderer,pr,pg,pb,pa);
        SDL_SetRenderDrawColor(renderer,r,g,b,a);
        for (int i = 1; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].mulwithMatrixUpdateSelf(matProj);
            p_Vertices[i].OrientX(1, w ->getWidth() * 0.5);
            p_Vertices[i].OrientY(1, w ->getHeight() * 0.5);
        }
        for (int i = 0; i < triangle_count; i++)
        {
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY(),
                                p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY(), 
                                p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY(), p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY());
        }
        SDL_SetRenderDrawColor(renderer,*pr,*pg,*pb,*pa);
    }
    void Mesh_new::drawMesh(Window* w,Matrix44* matProj){
        Uint8 *pr,*pg,*pb,*pa,r=230,g=255,b=255,a=255;
        pr = &r; pg = &g; pb = &b; pa = &a;
        SDL_Renderer* renderer = *w -> getRendererPointer();
        SDL_GetRenderDrawColor(renderer,pr,pg,pb,pa);
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        for (int i = 1; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].mulwithMatrixUpdateSelf(matProj);
            p_Vertices[i].OrientX(1, w ->getWidth() * 0.5);
            p_Vertices[i].OrientY(1, w ->getHeight() * 0.5);
        }
        for (int i = 0; i < triangle_count; i++)
        {
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY(), 
                p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY(),  
                p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY(), 
                p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY());
        }
        SDL_SetRenderDrawColor(renderer,*pr,*pg,*pb,*pa);
    }
    Mesh_new::~Mesh_new(){ 
        deallochandle<posStruct>(pos_handle);
        deallochandle<Vertex>(p_Vertices);
    }
    Mesh_new& Mesh_new::loadOBJfile(const char* filename){
        std::ifstream f(filename);
        if (f.is_open()){
            while (!f.eof())
            {
                char line[128];
                f.getline(line, 128);
                (line[0] == 'v' && ++vertex_count);
                (line[0] == 'f' && ++triangle_count);
            }
            f.clear();f.seekg(0, std::ios::beg);
            allocateWithArena<Vertex>(vertex_count*2,Mesh_Alloc_Helper.hint,1200,&Mesh_Alloc_Helper);
            p_Vertices = (Vertex*)Mesh_Alloc_Helper.handle;
            allocateWithArena<posStruct>(triangle_count,Mesh_Alloc_Helper.hint,1200,&Mesh_Alloc_Helper);
            pos_handle = (positions)Mesh_Alloc_Helper.handle;
            int vert_i = 0, pos_i = 0;

            while (!f.eof())
            {
                char line[128];
                f.getline(line, 128);

                std::strstream stream;
                stream << line;
                char head;
                if(line[0] == 'v'){
                    double x,y,z;
                    stream >> head >> x >> y >> z;
                    p_Vertices[vert_i].setX(x);
                    p_Vertices[vert_i].setY(y);
                    p_Vertices[vert_i].setZ(z);
                    p_Vertices[vert_i+1].setX(x);
                    p_Vertices[vert_i+1].setY(y);
                    p_Vertices[vert_i+1].setZ(z);
                    vert_i+=2;
                }
                if(line[0] == 'f'){
                    stream >> head >> pos_handle[pos_i].i >> pos_handle[pos_i].j >> pos_handle[pos_i].k;
                    pos_handle[pos_i].i--,pos_handle[pos_i].j--,pos_handle[pos_i].k--;
                    //indexing in OBJ files starts from 1
                    pos_i++;
                }
                if(pos_i >= triangle_count && vert_i >= 2 * vertex_count) break;
            }
            
        }
        return *this;
    }
    Mesh_new& Mesh_new::translateMesh(double x, double y, double z){
        for (int i = 0; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].incX(x);
            p_Vertices[i].incY(y);
            p_Vertices[i].incZ(z);
        }
        return *this;
    }
    Mesh_new& Mesh_new::offsetMesh(double x, double y, double z){
        for (int i = 1; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].incX(x);
            p_Vertices[i].incY(y);
            p_Vertices[i].incZ(z);
        }
        return *this;
    }
    Mesh_new& Mesh_new::scaleMesh(double x, double y, double z){
        for (int i = 0; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].ScaleX(x);
            p_Vertices[i].ScaleY(y);
            p_Vertices[i].ScaleZ(z);
        }
        return *this;
    }
    Mesh_new& Mesh_new::scaleMesh(double r){
        for (int i = 0; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].ScaleX(r);
            p_Vertices[i].ScaleY(r);
            p_Vertices[i].ScaleZ(r);
        }
        return *this;
    }
    Mesh_new& Mesh_new::translateMesh2D(double x, double y){
        for (int i = 0; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].incX(x);
            p_Vertices[i].incY(y);
        }
        return *this;
    }
    Mesh_new& Mesh_new::scaleMesh2D(double x, double y){
        for (int i = 0; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].ScaleX(x);
            p_Vertices[i].ScaleY(y);
        }
        return *this;
    }
    Mesh_new& Mesh_new::scaleMesh2D(double r){
        for (int i = 0; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].ScaleX(r);
            p_Vertices[i].ScaleY(r);
        }
        return *this;
    }
    Mesh_new& Mesh_new::transformMesh(Matrix44* t_matrix){
        for (int i = 1; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].setX(p_Vertices[i-1].getX());
            p_Vertices[i].setY(p_Vertices[i-1].getY());
            p_Vertices[i].setZ(p_Vertices[i-1].getZ());
            p_Vertices[i].mulwithMatrixUpdateSelf(t_matrix);
        }
        return *this;
    }
    Mesh_new& Mesh_new::transform_drawMesh(Window* w,Matrix44* t_matrix,Matrix44* matProj, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
        Uint8 *pr,*pg,*pb,*pa,rv=230,gv=255,bv=255,av=255;
        pr = &rv; pg = &gv; pb = &bv; pa = &av;
        SDL_Renderer* renderer = *w -> getRendererPointer();
        SDL_GetRenderDrawColor(renderer,pr,pg,pb,pa);
        SDL_SetRenderDrawColor(renderer,r,g,b,a);
        for (int i = 1; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].setX(p_Vertices[i-1].getX());
            p_Vertices[i].setY(p_Vertices[i-1].getY());
            p_Vertices[i].setZ(p_Vertices[i-1].getZ());
            p_Vertices[i].mulwithMatrixUpdateSelf(t_matrix);
            p_Vertices[i].mulwithMatrixUpdateSelf(matProj);
            p_Vertices[i].OrientX(1, w ->getWidth() * 0.5);
            p_Vertices[i].OrientY(1, w ->getHeight() * 0.5);
        }
        for (int i = 0; i < triangle_count; i++)
        {
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY(),
                                p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY(), 
                                p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY(), p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY());
        }
        SDL_SetRenderDrawColor(*w->getRendererPointer(),*pr,*pg,*pb,*pa);
        return *this;
    }
    Mesh_new& Mesh_new::transform_drawMesh(Window* w,Matrix44* t_matrix,Matrix44* matProj){
        Uint8 *pr,*pg,*pb,*pa,rv=230,gv=255,bv=255,av=255;
        pr = &rv; pg = &gv; pb = &bv; pa = &av;
        SDL_Renderer* renderer = *w -> getRendererPointer();
        SDL_GetRenderDrawColor(renderer,pr,pg,pb,pa);
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        for (int i = 1; i < vertex_count*2; i+=2)
        {
            p_Vertices[i].setX(p_Vertices[i-1].getX());
            p_Vertices[i].setY(p_Vertices[i-1].getY());
            p_Vertices[i].setZ(p_Vertices[i-1].getZ());
            p_Vertices[i].mulwithMatrixUpdateSelf(t_matrix);
            p_Vertices[i].mulwithMatrixUpdateSelf(matProj);
            p_Vertices[i].OrientX(1, w ->getWidth() * 0.5);
            p_Vertices[i].OrientY(1, w ->getHeight() * 0.5);
        }
        for (int i = 0; i < triangle_count; i++)
        {
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY(),
                                p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].j * 2 + 1].getX(), p_Vertices[pos_handle[i].j * 2 + 1].getY(), 
                                p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY());
            SDL_RenderDrawLine(renderer, p_Vertices[pos_handle[i].k * 2 + 1].getX(), p_Vertices[pos_handle[i].k * 2 + 1].getY(), p_Vertices[pos_handle[i].i * 2 + 1].getX(), p_Vertices[pos_handle[i].i * 2 + 1].getY());
        }
        SDL_SetRenderDrawColor(*w->getRendererPointer(),*pr,*pg,*pb,*pa);
        return *this;
    }
    int Mesh_new::getTriCount(){
        return triangle_count;
    }