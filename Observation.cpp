/* 
 * File:   Observation.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 21, 2009, 12:14 PM
 */

#include "Observation.h"

ke::Observation::Observation(std::string title, ke::Object *sender, std::map<std::string, std::string> &infos) {
    this->title = title;
    this->sender = sender;
    this->infos = &infos;
}

ke::Observation::Observation(const ke::Observation& orig) {
}

ke::Observation::~Observation() {
}

std::string ke::Observation::getTitle() const{
    return this->title;
}

ke::Object* ke::Observation::getSender() const{
    return this->sender;
}

std::string ke::Observation::getProperty(std::string key){
    return (*this->infos)[key];
}