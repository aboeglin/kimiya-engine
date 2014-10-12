/* 
 * File:   Scale.cpp
 * Author: jonas
 * 
 * Created on 22 juillet 2009, 22:01
 */

#include "Scale.h"
#include "Director.h"

#include <iostream>

ke::Scale::Scale(std::string title, float x, float y) : ke::IntervalActionTransformation(title) {
    this->scaleX = x;
    this->scaleY = y;
}

ke::Scale::Scale(std::string title, float duration, float x, float y) : ke::IntervalActionTransformation(title, duration) {
    this->scaleX = x;
    this->scaleY = y;
}

ke::Scale::~Scale() {
}

void ke::Scale::doNextStep() {
    float t = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();
    float elapsedMillis = t - this->getBeginningTime();

    if ((elapsedMillis / 1000) >= this->getDuration()){
        this->stop();
        this->target->setScale(this->scaleX, this->scaleY);
        if(this->isAutoRepeat()){
            this->target->setScale(this->startX, this->startY);
            this->play();
        }
    }
    else {
        float X =  (elapsedMillis * (this->scaleX - this->startX)) / (this->getDuration()*1000) + this->startX;
        float Y =  (elapsedMillis * (this->scaleY - this->startY)) / (this->getDuration()*1000) + this->startY;

        this->target->setScale(X, Y);
    }

}

void ke::Scale::setFinalScale(float x, float y) {
    this->scaleX = x;
    this->scaleY = y;
}

void ke::Scale::play() {
    this->startX = this->target->getScaleX();
    this->startY = this->target->getScaleY();
    ke::IntervalActionTransformation::play();
}

