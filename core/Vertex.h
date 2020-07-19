#include "Vector3d.h"
class Vertex
{
private:
    /* data */
    Vector3d* p_posVec;
public:
    Vertex(Vector3d*);
    double getX();
    double getY();
    double getZ();
    Vector3d* getVec();
    void setX(double);
    void setY(double);
    void setZ(double);
    void incX(double);
    void incY(double);
    void incZ(double);
};
