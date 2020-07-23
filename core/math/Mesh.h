#include <vector>
#include "Triangle.h"
class Mesh
{
private:
    /* data */
    std::vector<Triangle*> * p_triangles;
    void resetMesh();
public:
    Mesh();
    Mesh(Triangle*[],int);
    void addTriangle(Triangle*);
    void drawMesh(Window*,Matrix44*,Uint8,Uint8,Uint8,Uint8);
    void drawMesh(Window*,Matrix44*);
    void clearMesh();
    ~Mesh();
    Mesh& translateMesh(double,double,double);
    Mesh& scaleMesh(double,double,double);
    Mesh& scaleMesh(double);
    Mesh& translateMesh2D(double,double);
    Mesh& scaleMesh2D(double,double);
    Mesh& scaleMesh2D(double);
    Mesh* transformMesh(Mesh*, Matrix44*);
    int getTriCount();
};
