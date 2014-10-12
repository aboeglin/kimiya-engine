/* 
 * File:   Scene.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 18, 2009, 3:02 PM
 */

#include "Scene.h"

#include <iostream>

#ifdef MAC
#include <OpenGL/GL.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

ke::Scene::Scene() {
}

ke::Scene::Scene(const ke::Scene& orig){
}

ke::Scene::~Scene(){
}

void ke::Scene::setCurrentCamera(ke::Camera *cam){
    this->currentCamera = cam;
    this->currentCamera->set();
}

ke::Camera *ke::Scene::getCurrentCamera(){
    return this->currentCamera;
}

void ke::Scene::draw(){

}

void ke::Scene::move(float x, float y){

}

void ke::Scene::setPosition(float x, float y){

}