/*
 * File:   SimpleIntervalAction.cpp
 * Author: arnaudboeglin
 *
 * Created on August 28, 2009, 10:42 AM
 */

#include "SimpleIntervalAction.h"

ke::SimpleIntervalAction::SimpleIntervalAction(std::string title) : ke::IntervalAction(title){

}

ke::SimpleIntervalAction::SimpleIntervalAction(std::string title, float duration) : ke::IntervalAction(title, duration){

}

ke::SimpleIntervalAction::SimpleIntervalAction(const ke::SimpleIntervalAction& orig) : ke::IntervalAction(orig) {
}

ke::SimpleIntervalAction::~SimpleIntervalAction() {
}

