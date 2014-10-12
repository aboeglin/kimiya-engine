/* 
 * File:   DrawableCircle.cpp
 * Author: jonas
 * 
 * Created on 28 juillet 2009, 15:56
 */

#include "DrawableCircle.h"
#include "Camera.h"
#include "Director.h"

#include <math.h>
#include <iostream>

#ifdef MAC
#include <OpenGL/GL.h>
#include <OpenGL/GLU.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#include <GL/glu.h>
#endif


ke::DrawableCircle::DrawableCircle(float posX, float posY, float ray)  : ke::DrawableGeometricObject() {
    this->posX = posX;
    this->posY = posY;
    this->ray = ray;
    this->anchorX = posX;
    this->anchorY = posY;
    this->angle_start = 0;
    this->angle_end = 360;
}

ke::DrawableCircle::DrawableCircle(const ke::DrawableCircle& orig) {
}

ke::DrawableCircle::~DrawableCircle() {
}

void ke::DrawableCircle::draw(){
    int points = (ke::PI * 2 * ray) / 25 + 10;
    float *vertices = new float[points*3];
        
        for(int i = 0, j = 0; i < points; i++, j+=3){
            float angle = 2 * ke::PI * i / points;
            vertices[j+0] = this->ray *cos(angle);
            vertices[j+1] = this->ray *sin(angle);
            vertices[j+2] = 0.f;
        }
        
    //this->transform();

        glEnableClientState(GL_VERTEX_ARRAY);

            glColor4f(this->red, this->green, this->blue, this->opacity);

            glVertexPointer(3, GL_FLOAT, 0, vertices);
            glDrawArrays(GL_POLYGON, 0, points);

        glDisableClientState(GL_VERTEX_ARRAY);

    //this->restore();

    delete[] vertices;
}

void ke::DrawableCircle::setPosition(float x, float y){
    this->posX = x;
    this->posY = y;
}

void ke::DrawableCircle::move(float x, float y){
    this->posX += x;
    this->posY += y;
}

float ke::DrawableCircle::getPosX() const{
    return this->posX;
}

float ke::DrawableCircle::getPosY() const{
    return this->posY;
}