/* 
 * File:   OGLMatrix.cpp
 * Author: arnaudboeglin
 * 
 * Created on October 1, 2009, 12:51 PM
 */

#include <cmath>

#ifdef MAC
#include <OpenGL/GL.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

#include "OGLMatrix.h"
#include "DrawableCircle.h"

ke::OGLMatrix::OGLMatrix() {
    this->identity();

    this->oldScaleX = 1.f;
    this->oldScaleY = 1.f;
}

ke::OGLMatrix::OGLMatrix(const ke::OGLMatrix& orig) {
}

ke::OGLMatrix::~OGLMatrix() {
}

float ke::OGLMatrix::operator()(int i, int j){
    return this->datas[i+j*4];
}

ke::OGLMatrix ke::OGLMatrix::operator*(ke::OGLMatrix& mat){
    ke::OGLMatrix res;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            float v = 0;

            for(int k=0; k<4; k++){
                v += this->datas[i+k*4] * mat.datas[k+j*4];
            }
            res.datas[i+j*4] = v;
        }
    }

    return res;
}

ke::OGLMatrix* ke::OGLMatrix::operator*(ke::OGLMatrix* mat){
    ke::OGLMatrix *res = new ke::OGLMatrix();

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            float v = 0;

            for(int k=0; k<4; k++){
                v += this->datas[i+k*4] * mat->datas[k+j*4];
            }
            res->datas[i+j*4] = v;
        }
    }

    return res;
}

void ke::OGLMatrix::setRotation(float rot){
    float rad = (rot * ke::PI) / 180;

    float c = cosf(rad);
    float s = sinf(rad);

    this->datas[0] *= c;
    this->datas[4] = -s;
    this->datas[1] = s;
    this->datas[5] *= c;
}

void ke::OGLMatrix::setTranslation(float tx, float ty, float tz){
    this->datas[12] = tx;
    this->datas[13] = ty;
    this->datas[14] = tz;
}

void ke::OGLMatrix::setScale(float sx, float sy){
    this->datas[0] /= this->oldScaleX;
    this->datas[5] /= this->oldScaleX;

    this->datas[0] *= sx;
    this->datas[5] *= sy;

    this->oldScaleX = sx;
    this->oldScaleY = sy;
}

void ke::OGLMatrix::identity(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(j == i)
                this->datas[i+j*4] = 1.f;
            else
                this->datas[i+j*4] = 0.f;
        }
    }
}

void ke::OGLMatrix::use(){
    glMatrixMode(GL_MODELVIEW);
   
    glLoadMatrixf(this->datas);
}

float *ke::OGLMatrix::getDatas(){
    return this->datas;
}