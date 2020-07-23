#pragma once
#include "../../tools/SingleUseString.h"
class Vector2d
{
private:
    /* data */
    double x;
    double y;
    double length;
public:
    Vector2d(double,double);
    Vector2d* add(Vector2d);
    Vector2d* mul(Vector2d);
    Vector2d* sub(Vector2d);
    Vector2d* div(Vector2d);
    Vector2d* add(double);
    Vector2d* mul(double);
    Vector2d* sub(double);
    Vector2d* div(double);
    double dot(Vector2d);
    Vector2d& rotate(double);
    Vector2d& normalize();
    double getX();
    double getY();
    double getLength();
    SingleUseString* getStrRepr();
    SingleUseString* getStrRepr(char);
    SingleUseString* getStrRepr(const char*);
    SingleUseString* getStrRepr(const char* ,const char* ,const char*);
};
