/* 
 * File:   OpacityEffect.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 23, 2009, 11:03 PM
 */

#include <iostream>

#include "OpacityEffect.h"
#include "Director.h"

ke::OpacityEffect::OpacityEffect(std::string title) : ke::IntervalActionEffect(title){

}

ke::OpacityEffect::OpacityEffect(std::string title, float duration) : ke::IntervalActionEffect(title, duration){

}

ke::OpacityEffect::OpacityEffect(std::string title, float duration, float finalOpacity) : ke::IntervalActionEffect(title, duration){
    this->finalOpacity = finalOpacity;
}

ke::OpacityEffect::OpacityEffect(const ke::OpacityEffect& orig) : ke::IntervalActionEffect(orig) {

}

ke::OpacityEffect::~OpacityEffect() {
    
}

void ke::OpacityEffect::play(){
    this->startOpacity = this->target->getOpacity();
    ke::IntervalActionEffect::play();
}

void ke::OpacityEffect::doNextStep(){
    float t = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();
    float elapsedMillis = t - this->getBeginningTime();

    if((elapsedMillis/1000) >= this->getDuration()){
        this->stop();
        this->target->setOpacity(this->finalOpacity);
        if(this->isAutoRepeat()){
            this->target->setOpacity(this->startOpacity);
            this->play();
        }
    }
    else{
        float actualOpacity = (elapsedMillis / (getDuration()*1000)) * (this->finalOpacity - this->startOpacity) + this->startOpacity;
        this->target->setOpacity(actualOpacity);
    }
}

void ke::OpacityEffect::setFinalOpacity(float finalOpacity){
    this->finalOpacity = finalOpacity;
}

