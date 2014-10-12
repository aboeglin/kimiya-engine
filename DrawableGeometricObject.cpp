/* 
 * File:   DrawableGeometricObject.cpp
 * Author: jonas
 * 
 * Created on 25 juillet 2009, 22:42
 */

#include "DrawableGeometricObject.h"

#include <string>

ke::DrawableGeometricObject::DrawableGeometricObject() {
    this->scaleX = 1;
    this->scaleY = 1;
    this->opacity = 1;
//    this->rotation = 0;
    this->blue = 1;
    this->green = 1;
    this->red = 1;
    this->anchorX = 0;
    this->anchorY = 0;
    this->zIndex = 0.f;
}

ke::DrawableGeometricObject::DrawableGeometricObject(const ke::DrawableGeometricObject& orig) {
}

ke::DrawableGeometricObject::~DrawableGeometricObject() {
}

//void DrawableGeometricObject::setScale(float x, float y){
//    this->scaleX = x;
//    this->scaleY = y;
//}
//
//float DrawableGeometricObject::getScaleX() const{
//    return this->scaleX;
//}
//
//float DrawableGeometricObject::getScaleY() const{
//    return this->scaleY;
//}
//
//void DrawableGeometricObject::setRotation(float r){
//    this->rotation = r;
//}
//
//
//float DrawableGeometricObject::getRotation() const{
//    return this->rotation;
//}
//
//float DrawableGeometricObject::getOpacity(){
//    return this->opacity;
//}
//
//void DrawableGeometricObject::setOpacity(float opacity){
//    this->opacity = opacity;
//}
//
//void DrawableGeometricObject::setAnchor(float x, float y){
//    this->anchorX = x;
//    this->anchorY = y;
//}
//
//float DrawableGeometricObject::getAnchorX(){
//    return this->anchorX;
//}
//
//float DrawableGeometricObject::getAnchorY(){
//    return this->anchorY;
//}

void ke::DrawableGeometricObject::setColor(float red, float green, float blue){
    this->red = red;
    this->green = green;
    this->blue = blue;
}

//float DrawableGeometricObject::getZIndex(){
//    return this->zIndex;
//}
//
//void DrawableGeometricObject::setZIndex(float z){
//    this->zIndex = z;
//}