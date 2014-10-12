/* 
 * File:   Sprite.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 18, 2009, 8:47 PM
 */

#include "Sprite.h"

#include <iostream>

ke::Sprite::Sprite(std::string path) : ke::TextureNode(path) {
}

ke::Sprite::Sprite(ke::Texture2D *tex) : ke::TextureNode(tex) {

}

ke::Sprite::Sprite(const ke::Sprite& orig) {
}

ke::Sprite::~Sprite() {
}

void ke::Sprite::addAnimation(ke::IntervalAction *animation){
    this->animations.push_back(animation);
    animation->setTarget(this);
}

void ke::Sprite::removeAnimation(ke::IntervalAction *animation){
    std::vector<ke::IntervalAction*>::iterator it;
    it = this->animations.begin();
    for(int i=0; i<this->animations.size() && this->animations[i] != animation; i++)
        it++;

    if(*it == animation){
        this->animations.erase(it);
        delete animation;
    }
}

void ke::Sprite::draw(){
    TextureNode::draw();
}