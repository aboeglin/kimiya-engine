/* 
 * File:   Particle.cpp
 * Author: jonas
 * 
 * Created on 28 août 2009, 15:10
 */

#include "TextureNode.h"


#include "Particle.h"

ke::Particle::Particle() : ke::TextureNode(){

}

ke::Particle::Particle(ke::Texture2D *tex) : ke::TextureNode(tex) {

}

ke::Particle::Particle(ke::Texture2D *tex, float x, float y, ke::DrawableNode *parent) : ke::TextureNode(tex, x, y, parent) {

}

ke::Particle::Particle(std::string path) : ke::TextureNode(path) {

}

ke::Particle::Particle(const ke::Particle& orig) : ke::TextureNode(orig) {

}

ke::Particle::~Particle() {

}

float ke::Particle::getDirX(){
    return this->dirX;
}

float ke::Particle::getDirY(){
    return this->dirY;
}

float ke::Particle::getTangentialAccel(){
    return this->tangentialAccel;
}

ke::Color ke::Particle::getDeltaColor(){
    return this->deltaColor;
}

float ke::Particle::getRadialAccel(){
    return this->radialAccel;
}

float ke::Particle::getSize(){
    return this->size;
}

float ke::Particle::getLife(){
    return this->life;
}

void ke::Particle::setDirX(float dirX){
    this->dirX = dirX;
}

void ke::Particle::setDirY(float dirY){
    this->dirY = dirY;
}

void ke::Particle::setRadialAccel(float radialAccel) {
    this->radialAccel = radialAccel;
}

void ke::Particle::setTangentialAccel(float tangentialAccel){
    this->tangentialAccel = tangentialAccel;
}

void ke::Particle::setDeltaColor(ke::Color deltaColor){
    this->deltaColor = deltaColor;
}

void ke::Particle::setSize(float size){
    this->size = size;
}

void ke::Particle::setLife(float life){
    this->life = life;
}
