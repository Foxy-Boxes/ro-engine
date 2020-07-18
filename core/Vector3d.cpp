#include "Vector3d.h"
#include <math.h>
    Vector3d::Vector3d(double vx, double vy,double vz){
        x = vx;
        y = vy;
        z = vz;
        length = sqrt(x * x + y * y + z * z);
    }
    Vector3d* Vector3d::add(Vector3d* w){
        Vector3d* vp = new Vector3d(x + w->getX(), y + w->getY(), z + w->getZ());
        return vp;
    }
    Vector3d* Vector3d::mul(Vector3d* w){
        Vector3d* vp = new Vector3d(x * w->getX(), y * w->getY(), z * w->getZ());
        return vp;
    }
    Vector3d* Vector3d::sub(Vector3d* w){
        Vector3d* vp = new Vector3d(x - w->getX(), y - w->getY(), z - w->getZ());
        return vp;
    }
    Vector3d* Vector3d::div(Vector3d* w){
        Vector3d* vp = new Vector3d(x / w->getX(), y / w->getY(), z / w->getY());
        return vp;
    }
    Vector3d* Vector3d::add(double r){
        Vector3d* vp = new Vector3d(x + r, y + r, z + r);
        return vp;
    }
    Vector3d* Vector3d::mul(double r){
        Vector3d* vp = new Vector3d(x * r, y * r, z * r);
        return vp;
    }
    Vector3d* Vector3d::sub(double r){
        Vector3d* vp = new Vector3d(x - r, y - r, z - r);
        return vp;
    }
    Vector3d* Vector3d::div(double r){
        Vector3d* vp = new Vector3d(x / r, y / r, z / r);
        return vp;
    }
    double Vector3d::dot(Vector3d* w){
        return x * w->getX() + y * w->getY() + z * w->getZ();
    }
    Vector3d& Vector3d::rotateXY(double angle){
        double xtmp = x;
        double cosw = cos(angle);
        double sinw = sin(angle);
        x = x * cosw - y * sinw;
        y = xtmp * sinw + y * cosw;
        return *this;
    }
    Vector3d& Vector3d::normalize(){
        x = x/length;
        y = y/length;
        z = z/length;
        length = 1;
        return *this;
    }
    Vector3d* Vector3d::cross(Vector3d* w){
        double vx = y * w->getZ() - z * w->getY();
        double vy = z * w->getX() - x * w->getZ();
        double vz = x * w->getY() - y * w->getX();
        Vector3d *vp = new Vector3d(vx, vy, vz);
        return vp;
    }
    double Vector3d::getX(){
        return x;
    }
    double Vector3d::getY(){
        return y;
    }
    double Vector3d::getZ(){
        return z;
    }
    double Vector3d::getLength(){
        return length;
    }
    SingleUseString* Vector3d::getStrRepr(){
        SingleUseString openp("(");
        SingleUseString seperator(", ");
        SingleUseString closep(")");
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        interstr.concat(z).concat(&closep);
        SingleUseString* retstr = new SingleUseString(&interstr);
        return retstr;
    }
    SingleUseString* Vector3d::getStrRepr(char sep){
        SingleUseString openp("(");
        char seps[] ={sep};
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        interstr.concat(z).concat(&closep);
        SingleUseString* retstr = new SingleUseString(&interstr);
        return retstr;
    }
    SingleUseString* Vector3d::getStrRepr(const char* seps){
        SingleUseString openp("(");
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        interstr.concat(z).concat(&closep);
        SingleUseString* retstr = new SingleUseString(&interstr);
        return retstr;
    }
    SingleUseString* Vector3d::getStrRepr(const char* op,const char* seps,const char* cl){
        SingleUseString openp(op);
        SingleUseString seperator(seps);
        SingleUseString closep(cl);
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        interstr.concat(z).concat(&closep);
        SingleUseString* retstr = new SingleUseString(&interstr);
        return retstr;
    }