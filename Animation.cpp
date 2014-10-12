/* 
 * File:   Animation.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 20, 2009, 1:01 AM
 */

#include "Animation.h"
#include "Director.h"

#include <iostream>

ke::Animation::Animation(std::string title) : ke::IntervalAction(title) {

}

ke::Animation::Animation(std::string title, float duration) : ke::IntervalAction(title, duration) {

}

ke::Animation::Animation(const ke::Animation& orig) : ke::IntervalAction(orig) {
    
}

ke::Animation::~Animation() {
}

void ke::Animation::addTexture(ke::Texture2D *tex){
    this->textures.push_back(tex);
}

void ke::Animation::insertTexture(ke::Texture2D *tex, int pos){
    std::vector<ke::Texture2D*>::iterator it;
    it = this->textures.begin();

    for(int i=0; i<pos; i++)
        it++;

    this->textures.insert(it, tex);
}

void ke::Animation::removeTexture(ke::Texture2D *tex){
    std::vector<ke::Texture2D*>::iterator it;
    it = this->textures.begin();

    for(int i=0; i<this->textures.size() && *it != tex; i++)
        it++;

    this->textures.erase(it);
}

void ke::Animation::removeTexture(int pos){
    std::vector<ke::Texture2D*>::iterator it;
    it = this->textures.begin();

    for(int i=0; i<pos; i++)
        it++;

    this->textures.erase(it);
}

void ke::Animation::doNextStep(){
    ke::Sprite *tmp;
    
    if(tmp = dynamic_cast<ke::Sprite*>(this->target)){

        float t = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();
        float elapsedMillis = t - this->getBeginningTime();

        if((elapsedMillis/1000) >= this->getDuration()){
            this->stop();
            if(this->isAutoRepeat()){
                this->play();
            }
        }
        else{
            int nbFrames = this->textures.size();

            float timePerFrame = (this->getDuration()*1000) / nbFrames;

            int index = elapsedMillis / timePerFrame;

            tmp->setTexture(this->textures[index]);
        }
    }
}