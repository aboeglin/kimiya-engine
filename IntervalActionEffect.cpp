/* 
 * File:   IntervalActionEffect.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 23, 2009, 11:03 PM
 */

#include "IntervalActionEffect.h"

ke::IntervalActionEffect::IntervalActionEffect(std::string title) : ke::SimpleIntervalAction(title){

}

ke::IntervalActionEffect::IntervalActionEffect(std::string title, float duration) : ke::SimpleIntervalAction(title, duration){

}

ke::IntervalActionEffect::IntervalActionEffect(const ke::IntervalActionEffect& orig) : ke::SimpleIntervalAction(orig) {

}

ke::IntervalActionEffect::~IntervalActionEffect() {
    
}

