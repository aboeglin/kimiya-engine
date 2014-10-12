/* 
 * File:   Rotation.cpp
 * Author: jonas
 * 
 * Created on 22 juillet 2009, 22:01
 */

#include "Rotation.h"
#include "Director.h"

ke::Rotation::Rotation(std::string title) : ke::IntervalActionTransformation(title) {

}

ke::Rotation::Rotation(std::string title, float duration) : ke::IntervalActionTransformation(title, duration) {

}

ke::Rotation::Rotation(std::string title, float duration, float angle) : ke::IntervalActionTransformation(title, duration) {
    this->angle = angle;
}

ke::Rotation::Rotation(const ke::Rotation& orig) : ke::IntervalActionTransformation(orig) {

}

ke::Rotation::~Rotation() {

}

void ke::Rotation::play(){
    this->startAngle = this->target->getRotation();
    ke::IntervalActionTransformation::play();
}

void ke::Rotation::doNextStep(){
    float t = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();
    float elapsedMillis = t - this->getBeginningTime();

    if((elapsedMillis/1000) >= this->getDuration()){
        this->stop();
        this->target->setRotation(this->startAngle + this->angle);
        if(this->isAutoRepeat()){
            this->target->setRotation(this->startAngle);
            this->play();
        }
    }
    else{
        float actualAngle = (elapsedMillis / (getDuration()*1000)) * this->angle + this->startAngle;
        this->target->setRotation(actualAngle);
    }
}

void ke::Rotation::setAngle(float angle){
    this->angle = angle;
}