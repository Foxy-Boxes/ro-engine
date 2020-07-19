#include "../render/Window.h"
class Matrix44
{
private:
    /* data */
    double m[4][4];
public:
    Matrix44();
    Matrix44(double (*M)[4][4]);
    Matrix44& initIdentity();
    Matrix44& initProjection(Window*,double,double,double);
    Matrix44* mul(Matrix44*);
    void setVal(int, int, double);
    double getVal(int, int);
    void setM(double (*m)[4][4]);
    Matrix44* copyMatrix();
};