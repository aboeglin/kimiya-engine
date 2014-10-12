/* 
 * File:   Camera.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 19, 2009, 7:20 PM
 */

#include "Camera.h"
#include "ObservationCenter.h"
#include "Director.h"

#ifdef MAC
#include <OpenGL/GLU.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

#include <map>
#include <iostream>


ke::Camera::Camera(float x, float y, float fieldX, float fieldY) {
    this->x = x;
    this->y = y;

    this->offX = 0.f;
    this->offY = 0.f;
    
    this->fieldX = fieldX;
    this->fieldY = fieldY;

    this->width = fieldX;
    this->height = fieldY;

    ke::ObservationCenter::getCenter()->addObserver("NodeMoved", this);
}

ke::Camera::Camera(const ke::Camera& orig) {

}

ke::Camera::~Camera() {

}

void ke::Camera::observe(ke::Observation &o){
    ke::DrawableNode *dn;
    
    if((dn = dynamic_cast<ke::DrawableNode*>(o.getSender())) && (o.getSender() == this->toFollow)){
        float x = 0;
        float y = 0;

        for(ke::DrawableNode *p = dn; p; p = p->getParent())
            x += p->getPosX(), y += p->getPosY();

        this->x = x - this->fieldX/2;
        this->y = y - this->fieldY/2;
    }
}

void ke::Camera::setNodeToFollow(ke::DrawableNode *dn){
    this->toFollow = dn;

    float x = 0;
    float y = 0;

    for(ke::DrawableNode *p = dn; p; p = p->getParent())
        x += p->getPosX(), y += p->getPosY();

    this->x = x - this->fieldX/2;
    this->y = y - this->fieldY/2;
    
}

void ke::Camera::move(float x, float y){
    this->x += x;
    this->y += y;
}

void ke::Camera::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void ke::Camera::setField(float fieldX, float fieldY){
    this->fieldX = fieldX;
    this->fieldY = fieldY;
}

void ke::Camera::set(){
    glViewport(this->offX, this->offY, this->width, this->height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, this->fieldX, 0, this->fieldY, ke::ZIMA*(ke::NB_OF_CAMERAS+1), ke::ZIMI);
}

float ke::Camera::getX() const{
    return this->x;
}

float ke::Camera::getY() const{
    return this->y;
}

float ke::Camera::getFieldX() const{
    return this->fieldX;
}

float ke::Camera::getFieldY() const{
    return this->fieldY;
}

void ke::Camera::setOffset(float x, float y){
    this->offX = x;
    this->offY = y;
}

float ke::Camera::getOffX() const{
    return this->offX;
}

float ke::Camera::getOffY() const{
    return this->offY;
}

void ke::Camera::setDimension(float w, float h){
    this->width = w;
    this->height = h;
}

float ke::Camera::getWidth() const{
    return this->width;
}

float ke::Camera::getHeight() const{
    return this->height;
}

void ke::Camera::setStartZ(float z){
    this->startZ = z;
}

float ke::Camera::getStartZ() const{
    return this->startZ;
}
