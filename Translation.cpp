/* 
 * File:   Translation.cpp
 * Author: jonas
 * 
 * Created on 22 juillet 2009, 22:02
 */

#include "Translation.h"
#include "Director.h"

#include <iostream>

ke::Translation::Translation(std::string title, float x, float y) : ke::IntervalActionTransformation(title) {
    this->dX = x;
    this->dY = y;
}

ke::Translation::Translation(std::string title, float duration, float x, float y) : ke::IntervalActionTransformation(title, duration) {
    this->dX = x;
    this->dY = y;
}

ke::Translation::~Translation() {
}

void ke::Translation::doNextStep() {
    float t = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();
    float elapsedMillis = t - this->getBeginningTime();

    if ((elapsedMillis / 1000) >= this->getDuration()){
        this->stop();
        this->target->setPosition(this->startX + this->dX, this->startY + this->dY);
        if(this->isAutoRepeat()){
            this->play();
        }
    }
    else {
        float X =  (elapsedMillis * (this->dX)) / (this->getDuration()*1000) + this->startX;
        float Y =  (elapsedMillis * (this->dY)) / (this->getDuration()*1000) + this->startY;
        
        this->target->setPosition(X, Y);
    }
    
}

void ke::Translation::setDistance(float x, float y) {
    this->dX = x;
    this->dY = y;
}

void ke::Translation::play() {
    this->startX = this->target->getPosX();
    this->startY = this->target->getPosY();
    ke::IntervalActionTransformation::play();
}
