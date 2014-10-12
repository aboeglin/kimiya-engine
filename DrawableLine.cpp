/* 
 * File:   DrawableLine.cpp
 * Author: jonas
 * 
 * Created on 25 juillet 2009, 23:39
 */

#include "DrawableLine.h"
#include "Camera.h"
#include "Director.h"

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

ke::DrawableLine::DrawableLine(float beginX, float beginY, float endX, float endY) : ke::DrawableGeometricObject() {
    this->beginX = beginX;
    this->beginY = beginY;
    this->endX = endX;
    this->endY = endY;
    this->anchorX = (this->endX - this->beginX) / 2;
    this->anchorY = (this->endY - this->beginY) / 2;
}

ke::DrawableLine::DrawableLine(const ke::DrawableLine& orig) {
}

ke::DrawableLine::~DrawableLine() {
}

void ke::DrawableLine::draw(){
    float vertices[6];

    vertices[0] = 0;
    vertices[1] = 0;
    vertices[2] = 0;
    vertices[3] = this->endX - this->beginX;
    vertices[4] = this->endY - this->beginY;
    vertices[5] = 0;

    //this->transform();
        glEnableClientState(GL_VERTEX_ARRAY);

            glColor4f(this->red, this->green, this->blue, this->opacity);

            glVertexPointer(3, GL_FLOAT, 0, vertices);
            glDrawArrays(GL_LINES, 0, 2);

        glDisableClientState(GL_VERTEX_ARRAY);
    //this->restore();
}

void ke::DrawableLine::setPosition(float x, float y){
    float dx = this->endX - this->beginX;
    float dy = this->endY - this->beginY;

    this->beginX = x;
    this->beginY = y;
    this->endX = x + dx;
    this->endY = y + dy;
}

void ke::DrawableLine::move(float x, float y){
    this->beginX += x;
    this->beginY += y;
    this->endX += x;
    this->endY += y;
}

float ke::DrawableLine::getPosX() const{
    return this->beginX;
}

float ke::DrawableLine::getPosY() const{
    return this->beginY;
}