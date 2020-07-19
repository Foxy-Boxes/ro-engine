#include "../core/Vertex.h"
#include "../render/Window.h"
class Triangle
{
private:
    /* data */
    Vertex *points[3];
public:
    Triangle(Vertex*,Vertex*,Vertex*);
    void drawTri(Window*);
    Vertex* getVertex(int);
};