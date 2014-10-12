/* 
 * File:   Director.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 19, 2009, 8:31 PM
 */

#include "Director.h"

#ifdef MAC
#include <OpenGL/GLU.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

#include <iostream>
#include <stdlib.h>

ke::Director *ke::Director::dir = NULL;

ke::Director::Director() {
    this->scene = new ke::Scene();
    this->clock = new ke::Clock();

    for(int i=0; i<ke::NB_OF_CAMERAS; i++){
        ke::Camera *c = new ke::Camera(0, 0, 0, 0);
        c->setStartZ(ke::ZIMA*i);
        std::pair<ke::Camera*, bool> p(c, false);
        this->cameras[i] = p;
    }

    this->cameras[ke::DEFAULT_CAM].second = true;
    this->cameras[ke::DEFAULT_CAM].first->setDimension(640, 480);
    this->cameras[ke::DEFAULT_CAM].first->setField(640, 480);

    this->scene->setCurrentCamera(this->cameras[ke::DEFAULT_CAM].first);

    srand((unsigned int)time(0));
}

ke::Director::Director(const ke::Director& orig) {
}

ke::Director::~Director() {
    delete this->scene;
    delete this->clock;

    std::map<int, std::pair<ke::Camera*, bool> >::iterator it = this->cameras.begin();
    
    while(it != this->cameras.end()){
        delete it->second.first;
        it++;
    }
}

ke::Director* ke::Director::getDirector(){
    if(!ke::Director::dir)
        ke::Director::dir = new ke::Director();
    return ke::Director::dir;
}

void ke::Director::destroy(){
    if(ke::Director::dir)
        delete ke::Director::dir;
}

void ke::Director::drawScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //SCENE:
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::map<int, std::pair<ke::Camera*, bool> >::iterator it = this->cameras.begin();

    while(it != this->cameras.end()){
        if(it->second.second){
            this->scene->setCurrentCamera(it->second.first);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(-it->second.first->getX(), -it->second.first->getY(), -it->second.first->getStartZ());
            this->scene->explore();
        }
        it++;
    }

    //MENUS:
    glViewport(0, 0, 3000, 3000);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 3000, 0, 3000, ke::ZIMA*(ke::NB_OF_CAMERAS+1), ke::ZIMI);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -ke::NB_OF_CAMERAS*ke::ZIMA);

    for(int i=0; i<this->menus.size(); i++)
        this->menus[i]->explore();
}

ke::Scene* ke::Director::getScene(){
    return this->scene;
}

ke::Clock* ke::Director::getSharedClock(){
    return this->clock;
}

ke::Camera* ke::Director::getCamera(ke::cam_type cam){
    std::map<int, std::pair<ke::Camera*, bool> >::iterator it = this->cameras.begin();
    for(int i=0; i<this->cameras.size() && i<cam; i++)
        it++;

    return it->second.first;
}

ke::Camera* ke::Director::enableCamera(ke::cam_type cam){
    std::map<int, std::pair<ke::Camera*, bool> >::iterator it = this->cameras.begin();
    for(int i=0; i<this->cameras.size() && i<cam; i++)
        it++;

    it->second.second = true;
    
    return it->second.first;
}

void ke::Director::disableCamera(ke::cam_type cam){
    std::map<int, std::pair<ke::Camera*, bool> >::iterator it = this->cameras.begin();
    for(int i=0; i<this->cameras.size() && i<cam; i++)
        it++;

    it->second.second = false;
}

void ke::Director::init(){
    this->initGL();
}

void ke::Director::initGL(){
    glClearColor(1.f, 1.f, 1.f, 0.f);
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
}

void ke::Director::addMenu(ke::Menu *m){
    this->menus.push_back(m);
}

ke::Menu* ke::Director::removeMenu(int index){
    ke::Menu *res = NULL;
    std::vector<ke::Menu*>::iterator it;

    it = this->menus.begin();
    for(int i=0; it != this->menus.end() && i < index; i++)
        it++;

    res = *it;

    this->menus.erase(it);

    return res;
}

ke::Menu* ke::Director::removeMenu(ke::Menu *m){
    ke::Menu *res = NULL;
    std::vector<ke::Menu*>::iterator it;

    it = this->menus.begin();
    while(it != this->menus.end() && *it != m)
        it++;

    res = *it;

    if(*it == m)
        this->menus.erase(it);

    return res;
}

ke::Menu* ke::Director::getMenu(int index){
    return this->menus[index];
}
