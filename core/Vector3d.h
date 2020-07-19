#include "../tools/SingleUseString.h"
#include "Matrix44.h"
#include "Vector2d.h"
class Vector3d
{
private:
    /* data */
    double x;
    double y;
    double z;
    double length;
public:
    Vector3d(double,double,double);
    Vector3d* add(Vector3d *);
    Vector3d* mul(Vector3d *);
    Vector3d* sub(Vector3d *);
    Vector3d* div(Vector3d *);
    Vector3d* add(double);
    Vector3d* mul(double);
    Vector3d* sub(double);
    Vector3d* div(double);
    double dot(Vector3d *);
    Vector3d& rotateXY(double);
    Vector3d& normalize();
    Vector3d* cross(Vector3d *);
    Vector3d* mulwithMatrix(Matrix44*);
    double getX();
    double getY();
    double getZ();
    void setX(double);
    void setY(double);
    void setZ(double);
    double getLength();
    SingleUseString* getStrRepr();
    SingleUseString* getStrRepr(char);
    SingleUseString* getStrRepr(const char*);
    SingleUseString* getStrRepr(const char* ,const char* ,const char*);
};