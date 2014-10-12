/* 
 * File:   DrawableObject.cpp
 * Author: jonas
 * 
 * Created on 25 juillet 2009, 22:09
 */

#include "DrawableObject.h"

#ifdef MAC
#include <OpenGL/GL.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

ke::DrawableObject::DrawableObject() {
}

ke::DrawableObject::DrawableObject(const ke::DrawableObject& orig) {
}

ke::DrawableObject::~DrawableObject() {
}

//void ke::DrawableObject::transform(){
//    glPushMatrix();
//
//    glTranslatef(this->getAnchorX()+this->getPosX(), this->getAnchorY()+this->getPosY(), 0.f);
//    glRotatef(this->getRotation(), 0.f, 0.f, 1.f);
//    glScalef(this->getScaleX(), this->getScaleY(), 1.f);
//    glTranslatef(-(this->getAnchorX()+this->getPosX()), -(this->getAnchorY()+this->getPosY()), 0.f);
//
//    glTranslatef(this->getPosX(), this->getPosY(), -this->getZIndex());
//}
//
//void ke::DrawableObject::restore(){
//    glPopMatrix();
//}