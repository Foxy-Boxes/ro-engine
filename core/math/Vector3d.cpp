#include "Vector3d.h"
#include <math.h>
    Vector3d::Vector3d(double vx, double vy,double vz){
        x = vx;
        y = vy;
        z = vz;
        length = sqrt(x * x + y * y + z * z);
    }
    Vector3d::Vector3d(){
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
    Vector3d* Vector3d::mulwithMatrix(Matrix44* matrix){
         double ox = x * matrix -> getVal(0,0) + y * matrix -> getVal(1,0) + z * matrix -> getVal(2,0) + matrix -> getVal(3,0);
         double oy = x * matrix -> getVal(0,1) + y * matrix -> getVal(1,1) + z * matrix -> getVal(2,1) + matrix -> getVal(3,1);
         double oz = x * matrix -> getVal(0,2) + y * matrix -> getVal(1,2) + z * matrix -> getVal(2,2) + matrix -> getVal(3,2);
         double ow = x * matrix -> getVal(0,3) + y * matrix -> getVal(1,3) + z * matrix -> getVal(2,3) + matrix -> getVal(3,3);

        if(ow){
            ox/=ow,oy/=ow,oz/=ow;
        }
        return new Vector3d(ox,oy,oz);
    }
    Vector3d& Vector3d::mulwithMatrixUpdateSelf(Matrix44* matrix){
         double ox = x * matrix -> getVal(0,0) + y * matrix -> getVal(1,0) + z * matrix -> getVal(2,0) + matrix -> getVal(3,0);
         double oy = x * matrix -> getVal(0,1) + y * matrix -> getVal(1,1) + z * matrix -> getVal(2,1) + matrix -> getVal(3,1);
         double oz = x * matrix -> getVal(0,2) + y * matrix -> getVal(1,2) + z * matrix -> getVal(2,2) + matrix -> getVal(3,2);
         double ow = x * matrix -> getVal(0,3) + y * matrix -> getVal(1,3) + z * matrix -> getVal(2,3) + matrix -> getVal(3,3);

        if(ow){
            ox/=ow,oy/=ow,oz/=ow;
        }
        x = ox;
        y = oy;
        z = oz;

        return *this;
    }
    Vector3d* Vector3d::decDistortion(Vector3d* befMul){
        z -= ((befMul -> getZ() < 3) * (4 - befMul -> getZ())) * (z * 0.001);
        y -= ((befMul -> getZ() < 3) * (4 - befMul -> getZ())) * (y * 0.001);
        x -= ((befMul -> getZ() < 3) * (4 - befMul -> getZ())) * (x * 0.001);
        return this;
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
    void Vector3d::setX(double vx){
        x = vx;
    }
    void Vector3d::setY(double vy){
        y = vy;
    }
    void Vector3d::setZ(double vz){
        z = vz;
    }
    void Vector3d::incX(double vx){
        x += vx;
    }
    void Vector3d::incY(double vy){    
        y += vy;
    }
    void Vector3d::incZ(double vz){    
        z += vz;
    }
    void Vector3d::ScaleX(double vx){
        x *= vx;
    }
    void Vector3d::ScaleY(double vy){    
        y *= vy;
    }
    void Vector3d::ScaleZ(double vz){    
        z *= vz;
    }
    void Vector3d::OrientX(double addx,double mulx){
        x = (x + addx)*mulx;
    }
    void Vector3d::OrientY(double addy,double muly){    
        y = (y + addy)*muly;
    }
    void Vector3d::OrientZ(double addz,double mulz){    
        z = (z + addz)*mulz;
    }
    double Vector3d::getLength(){
        return length;
    }
    void Vector3d::updateLength(){
        length = sqrt(x * x + y * y + z * z);
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