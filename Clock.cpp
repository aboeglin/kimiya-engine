/* 
 * File:   Clock.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 20, 2009, 12:21 AM
 */

#include "Clock.h"
#include <ctime>
#include <iostream>

ke::Clock::Clock() {
    this->startTime = ((float)clock())/CLOCKS_PER_SEC * 1000;
}

ke::Clock::Clock(const ke::Clock& orig) {
    
}

ke::Clock::~Clock() {

}

int ke::Clock::millisSinceBeginning(){
    return ((float)clock())/CLOCKS_PER_SEC * 1000 - this->startTime;
}

void ke::Clock::setTimeForCurrentRound(int t){
    this->previousRoundTime = t;
}