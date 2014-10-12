/* 
 * File:   Layer.cpp
 * Author: jonas
 * 
 * Created on 25 juillet 2009, 22:12
 */

#include "Layer.h"
#include "Director.h"

#include <iostream>

ke::Layer::Layer() : ke::DrawableNode() {

}

ke::Layer::Layer(const ke::Layer& orig) {
}

ke::Layer::~Layer() {
}

//void Layer::add(std::string s, DrawableGeometricObject *dgo){
//    this->objects[s] = dgo;
//}

//void Layer::remove(std::string s){
//    this->objects.erase(s);
//}
//
//void Layer::removeAt(int index){
//    std::map<std::string, DrawableGeometricObject*>::iterator it = this->objects.begin();
//
//    for(int i=0; i<index; i++)
//        it++;
//
//    this->objects.erase(it);
//}
//
//void Layer::remove(DrawableGeometricObject *dgo){
//    std::map<std::string, DrawableGeometricObject*>::iterator it = this->objects.begin();
//
//    for(int i=0; i<this->objects.size() || it->second == dgo; i++)
//        it++;
//
//    if(it->second == dgo)
//        this->objects.erase(it);
//}
//
//DrawableGeometricObject* Layer::get(std::string title){
//    return this->objects[title];
//}
//
//DrawableGeometricObject* Layer::get(int index){
//    DrawableGeometricObject *res = NULL;
//
//    std::map<std::string, DrawableGeometricObject*>::iterator it = this->objects.begin();
//
//    for(int i=0; i<index; i++)
//        it++;
//
//    res = it->second;
//
//    return res;
//}

void ke::Layer::draw(){
//    std::map<std::string, DrawableGeometricObject*>::iterator it = this->objects.begin();
//
//    bool finished = false;
//    for(float min=ZIMI, next=ZIMA*NB_OF_CAMERAS; !finished;){
//        it = this->objects.begin();
//        while(it != this->objects.end()){
//            if(it->second->getZIndex() == min)
//                it->second->draw();
//
//            if(it->second->getZIndex() > min && it->second->getZIndex() < next)
//                next = it->second->getZIndex();
//            it++;
//        }
//        if(min == next)
//            finished = true;
//        else
//            min = next, next = ZIMA*NB_OF_CAMERAS;
//    }
}
