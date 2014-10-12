/* 
 * File:   TransformationIntervalAction.cpp
 * Author: jonas
 * 
 * Created on 22 juillet 2009, 22:00
 */

#include "IntervalActionTransformation.h"

ke::IntervalActionTransformation::IntervalActionTransformation(std::string title) : ke::SimpleIntervalAction(title) {
}

ke::IntervalActionTransformation::IntervalActionTransformation(std::string title, float duration) : ke::SimpleIntervalAction(title, duration) {
}

ke::IntervalActionTransformation::IntervalActionTransformation(const ke::IntervalActionTransformation& orig) : ke::SimpleIntervalAction(orig){
}

ke::IntervalActionTransformation::~IntervalActionTransformation() {
}

