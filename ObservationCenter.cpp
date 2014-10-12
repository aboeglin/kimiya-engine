/* 
 * File:   ObservationCenter.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 21, 2009, 12:14 PM
 */

#include "ObservationCenter.h"

#include <iostream>

ke::ObservationCenter *ke::ObservationCenter::center;

ke::ObservationCenter* ke::ObservationCenter::getCenter(){
    if(!ke::ObservationCenter::center)
        ke::ObservationCenter::center = new ke::ObservationCenter();
    return ke::ObservationCenter::center;
}

void ke::ObservationCenter::destroyCenter(){
    if(ke::ObservationCenter::center){
        delete ke::ObservationCenter::center;
        ke::ObservationCenter::center = NULL;
    }
}

ke::ObservationCenter::ObservationCenter() {
}

ke::ObservationCenter::ObservationCenter(const ke::ObservationCenter& orig) {
}

ke::ObservationCenter::~ObservationCenter() {
}

void ke::ObservationCenter::addObserver(std::string title, ke::Observer *o){
    std::vector<ke::Observer*> &vec = this->observers[title];
    bool exists = false;

    for(int i=0; i<vec.size(); i++){
        if(vec[i] == o)
            exists = true;
    }

    if(!exists)
        vec.push_back(o);
}

void ke::ObservationCenter::removeObserver(std::string title, ke::Observer *o){
    std::vector<ke::Observer*> &vec = this->observers[title];
    std::vector<ke::Observer*>::iterator it;

    it = vec.begin();

    while(it != vec.end() && *it != o)
        it++;

    vec.erase(it);
}

void ke::ObservationCenter::postObservation(std::string title, std::map<std::string, std::string> &infos, ke::Object* sender){
    std::vector<ke::Observer*> &vec = this->observers[title];
    std::vector<ke::Observer*>::iterator it;

    ke::Observation o(title, sender, infos);
    
    it = vec.begin();

    while(it != vec.end()){
        (*it)->observe(o);
        it++;
    }
}