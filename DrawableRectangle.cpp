/* 
 * File:   DrawableRectangle.cpp
 * Author: jonas
 * 
 * Created on 26 juillet 2009, 12:09
 */

#include "DrawableRectangle.h"
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

ke::DrawableRectangle::DrawableRectangle(float posX, float posY, float width, float height) {
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    this->anchorX = this->width / 2;
    this->anchorY = this->height / 2;
    this->filled = true;
}

ke::DrawableRectangle::DrawableRectangle(const ke::DrawableRectangle& orig) {
}

ke::DrawableRectangle::~DrawableRectangle() {
}

void ke::DrawableRectangle::draw(){
    float vertices[12];

    vertices[0] = 0.f;
    vertices[1] = 0.f;
    vertices[2] = 0.f;
    vertices[3] = this->width;
    vertices[4] = 0.f;
    vertices[5] = 0.f;
    vertices[6] = this->width;
    vertices[7] = this->height;
    vertices[8] = 0.f;
    vertices[9] = 0.f;
    vertices[10] = this->height;
    vertices[11] = 0.f;

    //this->transform();

        glEnableClientState(GL_VERTEX_ARRAY);

            glColor4f(this->red, this->green, this->blue, this->opacity);

            glVertexPointer(3, GL_FLOAT, 0, vertices);
            if(this->filled)
                glDrawArrays(GL_QUADS, 0, 4);
            else
                glDrawArrays(GL_LINE_LOOP, 0, 4);

        glDisableClientState(GL_VERTEX_ARRAY);

    //this->restore();
}

void ke::DrawableRectangle::setPosition(float posX, float posY){
    this->posX = posX;
    this->posY = posY;
}

void ke::DrawableRectangle::move(float posX, float posY){
    this->posX += posX;
    this->posY += posY;
}

float ke::DrawableRectangle::getPosX() const{
    return this->posX;
}

float ke::DrawableRectangle::getPosY() const{
    return this->posY;
}

void ke::DrawableRectangle::setFill(bool bo){
    this->filled = bo;
}