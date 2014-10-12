/* 
 * File:   IntervalAction.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 20, 2009, 12:55 AM
 */

#include "IntervalAction.h"
#include "Director.h"
#include <iostream>

ke::IntervalAction::IntervalAction(std::string title) {
    this->title = title;
    this->duration = 0;
    this->playing = false;
    this->autoRepeat = false;
}

ke::IntervalAction::IntervalAction(std::string title, float duration){
    this->title = title;
    this->duration = duration;
    this->playing = false;
    this->autoRepeat = false;
}

ke::IntervalAction::IntervalAction(const ke::IntervalAction& orig) {

}

ke::IntervalAction::~IntervalAction() {
    
}

void ke::IntervalAction::play(){
    this->beginnningTime = Director::getDirector()->getSharedClock()->millisSinceBeginning();
    this->playing = true;
}

void ke::IntervalAction::pause(){
    this->playing = false;
}

void ke::IntervalAction::stop(){
    this->playing = false;
}

std::string ke::IntervalAction::getTitle() const{
    return this->title;
}

int ke::IntervalAction::getBeginningTime() const{
    return this->beginnningTime;
}

void ke::IntervalAction::setDuration(float duration){
    this->duration = duration;
}

float ke::IntervalAction::getDuration() const{
    return this->duration;
}

bool ke::IntervalAction::isPlaying(){
    return this->playing;
}

void ke::IntervalAction::setTarget(ke::DrawableNode *t){
    this->target = t;
}

void ke::IntervalAction::setAutoRepeat(bool b){
    this->autoRepeat = b;
}

bool ke::IntervalAction::isAutoRepeat(){
    return this->autoRepeat;
}