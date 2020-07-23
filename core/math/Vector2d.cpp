#include "Vector2d.h"
#include <math.h>
    Vector2d::Vector2d(double vx, double vy){
        x = vx;
        y = vy;
        length = sqrt(x * x + y * y);
    }
    Vector2d* Vector2d::add(Vector2d w){
        Vector2d* vp = new Vector2d(x + w.getX(), y + w.getY());
        return vp;
    }
    Vector2d* Vector2d::mul(Vector2d w){
        Vector2d* vp = new Vector2d(x * w.getX(), y * w.getY());
        return vp;
    }
    Vector2d* Vector2d::sub(Vector2d w){
        Vector2d* vp = new Vector2d(x - w.getX(), y - w.getY());
        return vp;
    }
    Vector2d* Vector2d::div(Vector2d w){
        Vector2d* vp = new Vector2d(x / w.getX(), y / w.getY());
        return vp;
    }
    Vector2d* Vector2d::add(double r){
        Vector2d* vp = new Vector2d(x + r, y + r);
        return vp;
    }
    Vector2d* Vector2d::mul(double r){
        Vector2d* vp = new Vector2d(x * r, y * r);
        return vp;
    }
    Vector2d* Vector2d::sub(double r){
        Vector2d* vp = new Vector2d(x - r, y - r);
        return vp;
    }
    Vector2d* Vector2d::div(double r){
        Vector2d* vp = new Vector2d(x / r, y / r);
        return vp;
    }
    double Vector2d::dot(Vector2d w){
        return x * w.getX() + y * w.getY();
    }
    Vector2d& Vector2d::rotate(double angle){
        double xtmp = x;
        double cosw = cos(angle);
        double sinw = sin(angle);
        x = x * cosw - y * sinw;
        y = xtmp * sinw + y * cosw;
        return *this;
    }
    Vector2d& Vector2d::normalize(){
        x = x/length;
        y = y/length;
        length = 1;
        return *this;
    }
    double Vector2d::getX(){
        return x;
    }
    double Vector2d::getY(){
        return y;
    }
    double Vector2d::getLength(){
        return length;
    }
    SingleUseString* Vector2d::getStrRepr(){
        SingleUseString openp("(");
        SingleUseString seperator(", ");
        SingleUseString closep(")");
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    SingleUseString* Vector2d::getStrRepr(char sep){
        SingleUseString openp("(");
        char seps[] ={sep};
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    SingleUseString* Vector2d::getStrRepr(const char* seps){
        SingleUseString openp("(");
        SingleUseString seperator(seps);
        SingleUseString closep(")");
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }
    SingleUseString* Vector2d::getStrRepr(const char* op,const char* seps,const char* cl){
        SingleUseString openp(op);
        SingleUseString seperator(seps);
        SingleUseString closep(cl);
        SingleUseString* retstr = new SingleUseString(&openp,x,&seperator,y,&closep);
        return retstr;
    }