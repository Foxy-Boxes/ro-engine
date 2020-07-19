#include "Matrix44.h"
    Matrix44::Matrix44(){
    }
    Matrix44::Matrix44(double (*M)[4][4]){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                m[i][j] = *M[i][j];
            }
        }
    }
    Matrix44& Matrix44::initIdentity(){
        m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0; 
        m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0; 
        m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
        m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
    }
    Matrix44* Matrix44::mul(Matrix44* M){
        register double matrix[4][4];
        matrix[0][0] = m[0][0] * M->getVal(0,0) + m[0][1] * M->getVal(1,0) + m[0][2] * M->getVal(2,0) + m[0][3] * M->getVal(3,0); 
        matrix[0][1] = m[0][0] * M->getVal(0,1) + m[0][1] * M->getVal(1,1) + m[0][2] * M->getVal(2,1) + m[0][3] * M->getVal(3,1); 
        matrix[0][2] = m[0][0] * M->getVal(0,2) + m[0][1] * M->getVal(1,2) + m[0][2] * M->getVal(2,2) + m[0][3] * M->getVal(3,2); 
        matrix[0][3] = m[0][0] * M->getVal(0,3) + m[0][1] * M->getVal(1,3) + m[0][2] * M->getVal(2,3) + m[0][3] * M->getVal(3,3); 
        matrix[1][0] = m[1][0] * M->getVal(0,0) + m[1][1] * M->getVal(1,0) + m[1][2] * M->getVal(2,0) + m[1][3] * M->getVal(3,0); 
        matrix[1][1] = m[1][0] * M->getVal(0,1) + m[1][1] * M->getVal(1,1) + m[1][2] * M->getVal(2,1) + m[1][3] * M->getVal(3,1); 
        matrix[1][2] = m[1][0] * M->getVal(0,2) + m[1][1] * M->getVal(1,2) + m[1][2] * M->getVal(2,2) + m[1][3] * M->getVal(3,2); 
        matrix[1][3] = m[1][0] * M->getVal(0,3) + m[1][1] * M->getVal(1,3) + m[1][2] * M->getVal(2,3) + m[1][3] * M->getVal(3,3); 
        matrix[2][0] = m[2][0] * M->getVal(0,0) + m[2][1] * M->getVal(1,0) + m[2][2] * M->getVal(2,0) + m[2][3] * M->getVal(3,0); 
        matrix[2][1] = m[2][0] * M->getVal(0,1) + m[2][1] * M->getVal(1,1) + m[2][2] * M->getVal(2,1) + m[2][3] * M->getVal(3,1); 
        matrix[2][2] = m[2][0] * M->getVal(0,2) + m[2][1] * M->getVal(1,2) + m[2][2] * M->getVal(2,2) + m[2][3] * M->getVal(3,2); 
        matrix[2][3] = m[2][0] * M->getVal(0,3) + m[2][1] * M->getVal(1,3) + m[2][2] * M->getVal(2,3) + m[2][3] * M->getVal(3,3); 
        matrix[3][0] = m[3][0] * M->getVal(0,0) + m[3][1] * M->getVal(1,0) + m[3][2] * M->getVal(2,0) + m[3][3] * M->getVal(3,0); 
        matrix[3][1] = m[3][0] * M->getVal(0,1) + m[3][1] * M->getVal(1,1) + m[3][2] * M->getVal(2,1) + m[3][3] * M->getVal(3,1); 
        matrix[3][2] = m[3][0] * M->getVal(0,2) + m[3][1] * M->getVal(1,2) + m[3][2] * M->getVal(2,2) + m[3][3] * M->getVal(3,2); 
        matrix[3][3] = m[3][0] * M->getVal(0,3) + m[3][1] * M->getVal(1,3) + m[3][2] * M->getVal(2,3) + m[3][3] * M->getVal(3,3); 
        Matrix44* retM = new Matrix44(&matrix);
        return retM;
    }
    void Matrix44::setVal(int i, int j, double val){
        m[i][j] = val;
    }
    double Matrix44::getVal(int i, int j){
        return m[i][j];
    }
    void Matrix44::setM(double (*M)[4][4]){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                m[i][j] = *M[i][j];
            }
        }
    }
    Matrix44* Matrix44::copyMatrix(){
        Matrix44* retM = new Matrix44(&m);
        return retM;
    }
