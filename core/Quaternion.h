#include "../tools/SingleUseString.h"
#include "Vector2d.h"
#include "Vector3d.h"

class Quaternion
{
private:
    /* data */
    double x;
    double y;
    double z;
    double w;
    double length;
public:
    Quaternion(double,double,double,double);
    Quaternion* add(Quaternion *);
    Quaternion* mul(Quaternion *);
    Quaternion* mul(Vector3d *);
    Quaternion* sub(Quaternion *);
    Quaternion* div(Quaternion *);
    Quaternion* add(double);
    Quaternion* mul(double);
    Quaternion* sub(double);
    Quaternion* div(double);
    double dot(Quaternion *);
    Quaternion& rotateXY(double);
    Quaternion& normalize();
    Quaternion* cross(Quaternion *);
    Quaternion* conjugate();
    double getX();
    double getY();
    double getZ();
    double getW();
    double getLength();
    SingleUseString* getStrRepr();
    SingleUseString* getStrRepr(char);
    SingleUseString* getStrRepr(const char*);
    SingleUseString* getStrRepr(const char* ,const char* ,const char*);
};
