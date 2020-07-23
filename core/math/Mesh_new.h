#include <vector>
#include "Vertex.h"
#include "../../tools/Arena.h"
#include <fstream>
#include <strstream>

class Mesh_new
{
private:
    /* data */
    Vertex *p_Vertices;
    int triangle_count;
    int vertex_count;
    inline static HandleandNexthint Mesh_Alloc_Helper = {NULL, NULL};
public:
    struct posStruct{int i;int j;int k;};
    typedef posStruct* positions;
    Mesh_new();
    void drawMesh(Window*,Matrix44*,Uint8,Uint8,Uint8,Uint8);
    void drawMesh(Window*,Matrix44*);
    ~Mesh_new();
    
    Mesh_new& loadOBJfile(const char*);
    Mesh_new& translateMesh(double,double,double);
    Mesh_new& offsetMesh(double,double,double);
    Mesh_new& scaleMesh(double,double,double);
    Mesh_new& scaleMesh(double);
    Mesh_new& translateMesh2D(double,double);
    Mesh_new& scaleMesh2D(double,double);
    Mesh_new& scaleMesh2D(double);
    Mesh_new& transformMesh(Matrix44*);
    Mesh_new& transform_drawMesh(Window*,Matrix44* t_m,Matrix44* p_m,Uint8,Uint8,Uint8,Uint8);
    Mesh_new& transform_drawMesh(Window*,Matrix44* t_m,Matrix44* p_m);
    int getTriCount();
private:
    posStruct* pos_handle;
};
