#include <vector>
#include "Triangle.h"
class Mesh
{
private:
    /* data */
    std::vector<Triangle*> *p_triangles;
public:
    Mesh();
    void addTriangle(Triangle*);
    void drawMesh(Window*,double,double,double);
    Mesh& translateMesh(double,double,double);
    Mesh& scaleMesh(double,double,double);
    Mesh& scaleMesh(double);
    Mesh& translateMesh2D(double,double);
    Mesh& scaleMesh2D(double,double);
    Mesh& scaleMesh2D(double);
};
