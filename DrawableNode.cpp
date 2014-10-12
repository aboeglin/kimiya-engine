/* 
 * File:   Drawable.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 18, 2009, 3:02 PM
 */

#include "DrawableNode.h"
#include "ObservationCenter.h"
#include "Camera.h"
#include "Director.h"
#include "MenuItem.h"

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

ke::DrawableNode::DrawableNode() {

    this->color.red = 1;
    this->color.green = 1;
    this->color.blue = 1;
    
    this->posX = 0.f;
    this->posY = 0.f;
    this->width = 0.f;
    this->height = 0.f;
    this->scaleX = 1.f;
    this->scaleY = 1.f;
    this->rot = 0.f;

    this->zIndex = 0.f;

    this->opacity = 1.f;

    this->parent = NULL;
    this->camera = NULL;

    this->color.red = 1.f;
    this->color.green = 1.f;
    this->color.blue = 1.f;

    this->visible = true;
//    this->color.alpha = 1.f;
}

ke::DrawableNode::DrawableNode(const ke::DrawableNode& orig) {
}

ke::DrawableNode::~DrawableNode() {
    for(int i=0; i<this->children.size(); i++)
        if(this->children[i])
            delete this->children[i];
}

void ke::DrawableNode::add(ke::DrawableNode *node){
    if(node != this){
        this->children.push_back(node);
        node->parent = this;

        if(this->camera)
            node->attachCamera(this->camera);
    }
}

ke::DrawableNode* ke::DrawableNode::remove(ke::DrawableNode *node){
    ke::DrawableNode *res = NULL;
    std::vector<ke::DrawableNode*>::iterator it;

    it = this->children.begin();
    while(it != this->children.end() && *it != node)
        it++;

    res = *it;

    if(*it == node)
        this->children.erase(it);

    return res;
}

ke::DrawableNode* ke::DrawableNode::removeAt(int index){
    ke::DrawableNode *res = NULL;
    std::vector<ke::DrawableNode*>::iterator it;

    it = this->children.begin();
    for(int i=0; it != this->children.end() && i < index; i++)
        it++;

    res = *it;

    this->children.erase(it);

    return res;
}

ke::DrawableNode** ke::DrawableNode::removeAll(){
    int i=0;
    ke::DrawableNode **res = new DrawableNode*[this->children.size() + 1];
    typedef std::vector<ke::DrawableNode*>::iterator myIT;
    myIT it;
    
    it = this->children.begin();
    while(it != this->children.end()){
        res[i] = *it;
        this->children.erase(it);

        i++;
        it++;
    }

    res[i] = NULL;

    return res;
}

ke::DrawableNode* ke::DrawableNode::getChild(int index){
    return this->children[index];
}

ke::DrawableNode* ke::DrawableNode::getParent(){
    return this->parent;
}

float ke::DrawableNode::getFullZIndex(){
    float res = this->getZIndex();

    for(ke::DrawableNode *p = this->parent; p; p = p->parent)
        res += p->getZIndex();

    return res;
}

float ke::DrawableNode::getFullRot(){
    float res = 0;

    for(ke::DrawableNode *p = this->parent; p; p = p->parent)
        res += p->getRotation();

    res += this->getRotation();

    return res;
}

void ke::DrawableNode::initMatrices(std::vector<ke::DrawableNode*> &vec){
    ke::Camera *cam = ke::Director::getDirector()->getScene()->getCurrentCamera();
    ke::Menu *m = NULL;
    ke::MenuItem *mi = NULL;

//    if(tn = dynamic_cast<ke::TextureNode*>(this)){
//
//    }
//Integrer la largeur, hauteur ..
//    std::cout << this->getAbsoluteX() << std::endl;
    

//        std::cout << m << " : " << mi << std::endl;

    if(this->parent){
        this->tMat.identity();

        float fullRot = 0;
        for(ke::DrawableNode *p = this->parent; p; p = p->parent)
            fullRot += p->rot;

        OGLMatrix tmp;
        tmp.setRotation(-fullRot);
        this->tMat = this->parent->tMat;
        this->tMat = this->tMat * tmp;

        tmp.identity();
        if(!this->camera)
            tmp.setTranslation(this->getPosX(), this->getPosY(), -this->getZIndex());
        else
            tmp.setTranslation(this->getPosX()+cam->getX(), this->getPosY()+cam->getY(), -this->getZIndex());
        this->tMat = this->tMat * tmp;

        tmp.identity();
        tmp.setRotation(fullRot);
        this->tMat = this->tMat * tmp;

        tmp.identity();
        tmp.setTranslation(this->getAnchorX(), this->getAnchorY(), 0.f);
        this->tMat = this->tMat * tmp;

        tmp.identity();
        tmp.setRotation(this->getRotation());
        this->tMat = this->tMat * tmp;

        tmp.identity();
        tmp.setScale(this->getScaleX(), this->getScaleY());
        this->tMat = this->tMat * tmp;

        tmp.identity();
        tmp.setTranslation(-(this->getAnchorX()), -(this->getAnchorY()), 0.f);
        this->tMat = this->tMat * tmp;
    }

    //If the node is in the camera's field, or if it's a menu item.
    if((this->getAbsoluteX()+this->getWidth() > cam->getX()
        && this->getAbsoluteX() < cam->getX()+cam->getWidth()
        && this->getAbsoluteY()+this->getHeight() > cam->getY()
        && this->getAbsoluteY() < cam->getY()+cam->getHeight())
        || (m = dynamic_cast<ke::Menu*>(this))
        || (mi = dynamic_cast<ke::MenuItem*>(this))){

        std::vector<DrawableNode*>::iterator it;
        it = vec.begin();

        while(it != vec.end()){
            //OGLMatrix(2,3) is translation z value
            OGLMatrix &m = (*it)->tMat;

            if(-(m(2,3)) > -(this->tMat(2,3))){
                break;
            }
            it++;
        }

        vec.insert(it, this);
    }
    

    for(int i=0; i<this->children.size(); i++){
        this->children[i]->initMatrices(vec);
    }
}

void ke::DrawableNode::explore(){

    //init matrices :
    ke::Camera *cam = ke::Director::getDirector()->getScene()->getCurrentCamera();

    std::vector<DrawableNode*> vec;
    
    this->initMatrices(vec);

    std::vector<DrawableNode*>::iterator it;
    it = vec.begin();

    while(it != vec.end()){
        for(int i=0; i<(*it)->animations.size(); i++){
            if((*it)->animations[i]->isPlaying())
                (*it)->animations[i]->doNextStep();
        }

        if((*it)->isVisible()){

        glPushMatrix();
        glMultMatrixf((*it)->tMat.getDatas());

        glBegin(GL_QUADS);
            glColor4f((*it)->getColor().red, (*it)->getColor().green, (*it)->getColor().blue, (*it)->getOpacity());
        glEnd();

        (*it)->draw();

        glPopMatrix();
        
        glBegin(GL_QUADS);
            glColor4f(1.f,1.f,1.f,1.f);
        glEnd();

        }
        
        it++;
    }
}

void ke::DrawableNode::attachCamera(ke::Camera *camera){
    if(!this->parent || this->parent->camera == camera || !this->parent->camera){
        this->camera = camera;

        for(int i=0; i<this->children.size(); i++)
            this->children[i]->attachCamera(camera);
    }
}

void ke::DrawableNode::releaseCamera(){
    if(this->parent)
        if(this->parent->camera == this->camera)
            this->parent->releaseCamera();

    this->camera = NULL;

    for(int i=0; i<this->children.size(); i++)
        this->children[i]->releaseCamera(); 
}

void ke::DrawableNode::addAnimation(ke::SimpleIntervalAction *animation){
    this->animations.push_back(animation);
    animation->target = this;
}

void ke::DrawableNode::removeAnimation(ke::SimpleIntervalAction *animation){
    std::vector<ke::IntervalAction*>::iterator it;
    it = this->animations.begin();
    for(int i=0; i<this->animations.size() && this->animations[i] != animation; i++)
        it++;

    if(*it == animation){
        this->animations.erase(it);
        delete animation;
    }
}

void ke::DrawableNode::removeAnimation(std::string title){
    std::vector<ke::IntervalAction*>::iterator it;
    it = this->animations.begin();
    for(int i=0; i<this->animations.size() && this->animations[i]->getTitle() != title; i++)
        it++;

    if((*it)->getTitle() == title){
        ke::IntervalAction *tmp = *it;
        this->animations.erase(it);
        delete tmp;
    }
}

void ke::DrawableNode::playAnimation(std::string title){
    for(int i=0; i<this->animations.size(); i++){
        if(this->animations[i]->getTitle() == title){
           this->animations[i]->play();
           break;
        }
    }
}

void ke::DrawableNode::stopAnimation(std::string title){
    for(int i=0; i<this->animations.size(); i++){
        if(this->animations[i]->getTitle() == title){
           this->animations[i]->stop();
           break;
        }
    }
}

void ke::DrawableNode::move(float x, float y){
    this->posX += x;
    this->posY += y;

    std::map<std::string, std::string> m;
    ke::ObservationCenter::getCenter()->postObservation("NodeMoved", m, this);
}

void ke::DrawableNode::setPosition(float x, float y){
    this->posX = x;
    this->posY = y;

    std::map<std::string, std::string> m;
    ke::ObservationCenter::getCenter()->postObservation("NodeMoved", m, this);
}

float ke::DrawableNode::getPosX() const{
    return this->posX;
}

float ke::DrawableNode::getPosY() const{
    return this->posY;
}

float ke::DrawableNode::getAbsoluteX() const{
    float res = this->getPosX();
    for(ke::DrawableNode *p = this->parent; p; p = p->parent)
        res += p->getPosX();
    return res;
}

float ke::DrawableNode::getAbsoluteY() const{
    float res = this->getPosY();
    for(ke::DrawableNode *p = this->parent; p; p = p->parent)
        res += p->getPosY();
    return res;
}

void ke::DrawableNode::setScale(float x, float y){
    this->scaleX = x;
    this->scaleY = y;
}

float ke::DrawableNode::getScaleX() const{
    return this->scaleX;
}

float ke::DrawableNode::getScaleY() const{
    return this->scaleY;
}

void ke::DrawableNode::setRotation(float r){
    this->rot = r;
}


float ke::DrawableNode::getRotation() const{
    return this->rot;
}

float ke::DrawableNode::getOpacity() const{
    return this->opacity;
}

void ke::DrawableNode::setOpacity(float opacity){
    this->opacity = opacity;
}

void ke::DrawableNode::setAnchor(float x, float y){
    this->anchorX = x;
    this->anchorY = y;
}

float ke::DrawableNode::getAnchorX() const{
    return this->anchorX;
}

float ke::DrawableNode::getAnchorY() const{
    return this->anchorY;
}

float ke::DrawableNode::getZIndex() const{
    return this->zIndex;
}

void ke::DrawableNode::setZIndex(float z){
    this->zIndex = z;
}

float ke::DrawableNode::getWidth() const{
    return this->width;
}

void ke::DrawableNode::setWidth(float w){
    this->width = w;
}

float ke::DrawableNode::getHeight() const{
    return this->height;
}

void ke::DrawableNode::setHeight(float h){
    this->height = h;
}

ke::Color& ke::DrawableNode::getColor() {
    return this->color;
}

void ke::DrawableNode::setColor(ke::Color &color){
    this->color = color;
}

bool ke::DrawableNode::isVisible(){
    return this->visible;
}

void ke::DrawableNode::show(){
    this->visible = true;
}


void ke::DrawableNode::hide(){
    this->visible = false;
}