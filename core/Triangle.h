#include "../core/Vertex.h"
#include "../render/Window.h"
class Triangle
{
private:
    /* data */
    Vertex *points[3];
public:
    Triangle(Vertex*,Vertex*,Vertex*);
    ~Triangle();
    void drawTri(Window*);
    Vertex* getVertex(int);
    Vector3d* NormalizedNormal();
};