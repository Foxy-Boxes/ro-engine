#include "Quaternion.h"

#include <math.h>
    /*The problem with these math classes are that i've copied them along, didnt erase any
    sorry about the laziness*/
    Quaternion::Quaternion(double vx, double vy, double vz, double vw){
        x = vx;
        y = vy;
        z = vz;
        w = vw;
        length = sqrt(x * x + y * y + z * z + w * w);
    }
    Quaternion* Quaternion::add(Quaternion* v){
        Quaternion* vp = new Quaternion(x + v->getX(), y + v->getY(), z + v->getZ(), w + v->getW());
        return vp;
    }
    Quaternion* Quaternion::mul(Quaternion* v){
        double vw = - x * v->getX() - y * v->getY() - z * v->getZ() + w * v->getW();
        double vx = x * v->getW() + w * v->getX() + y * v->getZ() - z * v->getY();
        double vy = y * v->getW() + w * v->getY() + z * v->getX() - x * v->getZ();
        double vz = z * v->getW() + w * v->getZ() + x * v->getY() - y * v->getX();
        

        Quaternion* vp = new Quaternion(vx, vy, vz, vw);
        return vp;
    }
    Quaternion* Quaternion::mul(Vector3d* v){
        double vw = -x * v->getX() - y * v->getY() - z * v->getZ();
        double vx = w * v->getX() + y * v->getZ() - z * v->getY();
        double vy = w * v->getY() + z * v->getX() - x * v->getZ();
        double vz = w * v->getZ() + x * v->getY() - y * v->getX();
        

        Quaternion* vp = new Quaternion(vx, vy, vz, vw);
        return vp;
    }
    Quaternion* Quaternion::sub(Quaternion* v){
        Quaternion* vp = new Quaternion(x - v->getX(), y - v->getY(), z - v->getZ(), w - v->getW());
        return vp;
    }
    Quaternion* Quaternion::div(Quaternion* v){
        Quaternion* vp = new Quaternion(x / v->getX(), y / v->getY(), z / v->getZ(), w / v->getW());
        return vp;
    }
    Quaternion* Quaternion::add(double r){
        Quaternion* vp = new Quaternion(x + r, y + r, z + r, w + r);
        return vp;
    }
    Quaternion* Quaternion::mul(double r){
        Quaternion* vp = new Quaternion(x * r, y * r, z * r, w * r);
        return vp;
    }
    Quaternion* Quaternion::sub(double r){
        Quaternion* vp = new Quaternion(x - r, y - r, z - r, w - r);
        return vp;
    }
    Quaternion* Quaternion::div(double r){
        Quaternion* vp = new Quaternion(x / r, y / r, z / r, w / r);
        return vp;
    }
    double Quaternion::dot(Quaternion* v){
        return x * v->getX() + y * v->getY() + z * v->getZ() + w * v->getW();
    }
    Quaternion& Quaternion::rotateXY(double angle){
        double xtmp = x;
        double cosw = cos(angle);
        double sinw = sin(angle);
        x = x * cosw - y * sinw;
        y = xtmp * sinw + y * cosw;
        return *this;
    }
    Quaternion& Quaternion::normalize(){
        x = x/length;
        y = y/length;
        z = z/length;
        w = w/length;
        length = 1;
        return *this;
    }
    Quaternion* Quaternion::cross(Quaternion* v){
        double vx = y * v->getZ() - z * v->getY();
        double vy = z * v->getX() - x * v->getZ();
        double vz = x * v->getY() - y * v->getX();
        Quaternion *vp = new Quaternion(vx, vy, vz,0);
        return vp;
    }
    Quaternion* Quaternion::conjugate(){
        Quaternion* retQ = new Quaternion(-x, -y, -z, w);
    }
    double Quaternion::getX(){
        return x;
    }
    double Quaternion::getY(){
        return y;
    }
    double Quaternion::getZ(){
        return z;
    }
    double Quaternion::getW(){
        return w;
    }
    double Quaternion::getLength(){
        return length;
    }
    SingleUseString* Quaternion::getStrRepr(){
        SingleUseString openp("(");
        SingleUseString seperator(", ");
        SingleUseString closep(")");
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        SingleUseString* retstr = new SingleUseString(&interstr,z,&seperator,w,&closep);
        return retstr;
    }
    SingleUseString* Quaternion::getStrRepr(char sep){
        SingleUseString openp("(");
        char seps[] ={sep};
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        SingleUseString* retstr = new SingleUseString(&interstr,z,&seperator,w,&closep);
        return retstr;
    }
    SingleUseString* Quaternion::getStrRepr(const char* seps){
        SingleUseString openp("(");
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        SingleUseString* retstr = new SingleUseString(&interstr,z,&seperator,w,&closep);
        return retstr;
    }
    SingleUseString* Quaternion::getStrRepr(const char* op,const char* seps,const char* cl){
        SingleUseString openp(op);
        SingleUseString seperator(seps);
        SingleUseString closep(cl);
        SingleUseString interstr(&openp,x,&seperator,y,&seperator);
        SingleUseString* retstr = new SingleUseString(&interstr,z,&seperator,w,&closep);
        return retstr;
    }