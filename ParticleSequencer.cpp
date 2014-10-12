/* 
 * File:   ParticleSequencer.cpp
 * Author: jonas
 * 
 * Created on 28 août 2009, 15:09
 */

#include "ParticleSequencer.h"
#include "Director.h"
#include "DrawableCircle.h"
#include "RessourceMgr.h"

#include <cmath>
#include <iostream>
#include <stdlib.h>

float ke::ParticleSequencer::rand(){
    float f = (float)((float) rand() / RAND_MAX);
    return f;
}

ke::ParticleSequencer::ParticleSequencer() {
    this->totalParticles = 20;
    this->active = true;
    this->blendAdditive = false;

    this->beginningTime = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();

    this->texture = ke::RessourceMgr::getMgr()->getTexture("/home/jonas/kimiya/fire.png");

    this->particles.reserve(this->totalParticles);

    this->vertices = new ke::OGL3Rect[this->totalParticles];
    this->colors = new ke::Color[this->totalParticles*4];
    this->textCoords = new ke::OGL2Rect[this->totalParticles];

    for(int i=0; i<this->totalParticles; i++){
        this->textCoords[i].x1 = 0;
        this->textCoords[i].y1 = 0;
        this->textCoords[i].x2 = 1;
        this->textCoords[i].y2 = 0;
        this->textCoords[i].x3 = 1;
        this->textCoords[i].y3 = 1;
        this->textCoords[i].x4 = 0;
        this->textCoords[i].y4 = 1;
    }

//    for(int i=0; i<this->totalParticles*8; i++){
//        if(i%8 == 0)
//            this->textCoords[i] = 0;
//        else if(i%8 == 1)
//            this->textCoords[i] = 0;
//        else if(i%8 == 2)
//            this->textCoords[i] = 1;
//        else if(i%8 == 3)
//            this->textCoords[i] = 0;
//        else if(i%8 == 4)
//            this->textCoords[i] = 1;
//        else if(i%8 == 5)
//            this->textCoords[i] = 1;
//        else if(i%8 == 6)
//            this->textCoords[i] = 0;
//        else if(i%8 == 7)
//            this->textCoords[i] = 1;
//    }
//
//    glGenBuffers(1, &this->verticesID);
//    glGenBuffers(1, &this->colorsID);
//    glGenBuffers(1, &this->textCoordsID);
}

ke::ParticleSequencer::ParticleSequencer(const ke::ParticleSequencer& orig) : DrawableNode(orig) {
}

ke::ParticleSequencer::~ParticleSequencer() {
    delete[] this->vertices;
    delete[] this->colors;
    delete[] this->textCoords;
}

void ke::ParticleSequencer::updateParticles(){
    /*
    if(this->active){
        float rate = 1.0 / this->emissionRate;
        this->emitCounter = (ke::Director::getDirector()->getSharedClock()->millisSinceBeginning() - this->beginningTime) / 1000;
        while(this->particles.size() < this->totalParticles && this->emitCounter > rate){
            this->addParticle();
            this->emitCounter -= rate;
        }

        if(this->duration =! -1 && this->duration < (ke::Director::getDirector()->getSharedClock()->millisSinceBeginning() - this->beginningTime) / 1000 )
            this->stop();
    }

    std::cout << "2 ###########" << std::endl;
    float dt = (ke::Director::getDirector()->getSharedClock()->millisSinceBeginning() - this->lastUpdateTime) / 1000;

    for(int i = 0; i<this->particles.size(); i++){
        ke::Particle *p = this->particles[i];

        if(p->getLife() > 0) {

            float tmpX = 0;
            float tmpY = 0;

            float radialX = 0;
            float radialY = 0;

            float tangentialX = 0;
            float tangentialY = 0;

            if(p->getPosX() || p->getPosY()){
                float n = sqrt(pow(posX, 2) + pow(posY, 2));
                radialX = p->getPosX() / n;
                radialY = p->getPosY() / n;
            }

    std::cout << "3 ###########" << std::endl;
            tangentialX = radialX;
            tangentialY = radialY;

            radialX *= p->getRadialAccel();
            radialY *= p->getRadialAccel();

            float newy = tangentialX;
            tangentialX = -tangentialY;
            tangentialY = newy;

            tangentialX *= p->getTangentialAccel();
            tangentialY *= p->getTangentialAccel();

            tmpX = (radialX + tangentialX + this->gravityX) * dt;
            tmpY = (radialY + tangentialY + this->gravityY) * dt;
        
            p->setDirX(p->getDirX() + tmpX);
            p->setDirY(p->getDirY() + tmpY);
            
            tmpX = p->getDirX() * dt;
            tmpY = p->getDirY() * dt;
        
            p->move(tmpX, tmpY);

            ke::Color nc;

            nc.red = p->getColor().red + p->getDeltaColor().red * dt;
            nc.green = p->getColor().green + p->getDeltaColor().green * dt;
            nc.blue = p->getColor().blue + p->getDeltaColor().blue * dt;
            nc.alpha = p->getColor().alpha + p->getDeltaColor().alpha * dt;


    std::cout << "4 ###########" << std::endl;
            p->setColor(nc);

            p->setLife(p->getLife() - dt);

            vertices[i].x1 = p->getPosX();
            vertices[i].y1 = p->getPosY();
            vertices[i].z1 = -i;
            vertices[i].x2 = p->getPosX()+this->texture->getWidth()/2;
            vertices[i].y2 = p->getPosY();
            vertices[i].z2 = -i;
            vertices[i].x3 = p->getPosX()+this->texture->getWidth()/2;
            vertices[i].y3 = p->getPosY()+this->texture->getHeight()/2;
            vertices[i].z3 = -i;
            vertices[i].x4 = p->getPosX();
            vertices[i].y4 = p->getPosY()+this->texture->getHeight()/2;
            vertices[i].z4 = -i;

            colors[4*i] = p->getColor();
            colors[4*i+1] = p->getColor();
            colors[4*i+2] = p->getColor();
            colors[4*i+3] = p->getColor();
            
        } else {
            std::vector<ke::Particle*>::iterator it;
            it = this->particles.begin();

            for(int j = 0; j < this->particles.size() && j < i; j++)
                it++;

            ke::Particle *tmp = *it;

            this->particles.erase(it);
            this->particleCount--;
            delete tmp;
        }
    }

    std::cout << "5 ###########" << std::endl;
    this->lastUpdateTime = ke::Director::getDirector()->getSharedClock()->millisSinceBeginning();
}

bool ke::ParticleSequencer::isFull(){
    return this->particles.size() >= this->totalParticles;
}

void ke::ParticleSequencer::addParticle(){
    if(!this->isFull()){

    std::cout << "6 ###########" << std::endl;
        ke::Particle *p = new ke::Particle("/home/jonas/amsn_received/fire.png");

        float vx;
        float vy;

        p->setPosition(this->posVarX * ke::ParticleSequencer::rand(), this->posVarY * ke::ParticleSequencer::rand());

        float a = (this->angle + this->angleVar * ke::ParticleSequencer::rand()) / 180 * ke::PI;

        vx = cosf(a);
        vy = sinf(a);

        float s = this->speed + this->speedVar * ke::ParticleSequencer::rand();

        p->setDirX(vx * s);
        p->setDirY(vx * s);

        p->setRadialAccel(this->radialAccel + this->radialAccelVar * ke::ParticleSequencer::rand());

        p->setTangentialAccel(this->tangentialAccel + this->tangentialAccel * ke::ParticleSequencer::rand());

        p->setLife(this->life + this->lifeVar * ke::ParticleSequencer::rand());

        ke::Color start;
        ke::Color end;
        ke::Color deltaColor;

        start.red = this->startColor.red + this->startColorVar.red * ke::ParticleSequencer::rand();
        start.green = this->startColor.green + this->startColorVar.green * ke::ParticleSequencer::rand();
        start.blue = this->startColor.blue + this->startColorVar.blue * ke::ParticleSequencer::rand();
        start.alpha = this->startColor.alpha + this->startColorVar.alpha * ke::ParticleSequencer::rand();

        end.red = this->endColor.red + this->endColor.red * ke::ParticleSequencer::rand();
        end.green = this->endColor.green + this->endColor.green * ke::ParticleSequencer::rand();
        end.blue = this->endColor.blue + this->endColor.blue * ke::ParticleSequencer::rand();
        end.alpha = this->endColor.alpha + this->endColor.alpha * ke::ParticleSequencer::rand();

        p->setColor(start);
        
        deltaColor.red = (end.red - start.red) / p->getLife();
        deltaColor.green = (end.green - start.green) / p->getLife();
        deltaColor.blue = (end.blue - start.blue) / p->getLife();
        deltaColor.alpha = (end.alpha - start.alpha) / p->getLife();

        p->setDeltaColor(deltaColor);

        p->setSize(this->size + this->sizeVar * ke::ParticleSequencer::rand());

        this->particles.push_back(p);
        this->particleCount++;
        p->setZIndex(this->particleCount*0.1);

    std::cout << "7 ###########" << std::endl;
    }
     */
}

void ke::ParticleSequencer::stop(){

}

void ke::ParticleSequencer::draw(){
    /*
    this->updateParticles();

    int blendSrc, blendDst;

    glEnable(GL_TEXTURE_2D);
    this->texture->bind();

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, this->vertices);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_FLOAT, 0, this->colors);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, this->textCoords);

    // save blend state
//    glDisable(GL_DEPTH_TEST);
    glGetIntegerv(GL_BLEND_DST, &blendDst);
    glGetIntegerv(GL_BLEND_SRC, &blendSrc);
//    if(this->blendAdditive)
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//    else
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDrawArrays(GL_QUADS, 0, this->particles.size()*4);

    // restore blend state
    glBlendFunc( blendSrc, blendDst );

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
//    glEnable(GL_DEPTH_TEST);
//    this->updateParticles();
//
//    std::vector<ke::Particle*>::iterator it;
//    it = this->particles.begin();
//
//    for(int i=0; i<this->particleCount; i++){
//        this->particles[i]->explore();
//    }

//    while(it != this->particles.end()){
//        (*it)->explore();
//        it++;
//    }
     */
}

ke::FireSequencer::FireSequencer() : ke::ParticleSequencer(){
//    this->duration = -1;
//
//    // gravity
//    this->gravityX = 0;
//    this->gravityY = 0;
//
//    // angle
//    this->angle = 90;
//    this->angleVar = 10;
//
//    this->rot = 225;
//
//    // radial acceleration
//    this->radialAccel = 0;
//    this->radialAccelVar = 0;
//
//    this->tangentialAccel = 0;
//    this->tangentialAccelVar = 0;
//
//    // emitter position
//    this->posX = 160;
//    this->posY = 60;
//    this->posVarX = 30;
//    this->posVarY = 30;
//
//    // life of particles
//    this->life = 0;
//    this->lifeVar = 0.5;
//
//    // speed of particles
//    this->speed = 1000;
//    this->speedVar = 20;
//
//    // size, in pixels
//    this->size = 100.0f;
//    this->sizeVar = 10.0f;
//
//    // emits per frame
//    this->emissionRate = this->totalParticles / this->life;
//
//    // color of particles
//    this->startColor.red = 0.76f;
//    this->startColor.green = 0.35f;
//    this->startColor.blue = 0.12f;
//    this->startColor.alpha = 0.2f;
//    this->startColorVar.red = 0.2;
//    this->startColorVar.green = 0.0;
//    this->startColorVar.blue = 0.0;
//    this->startColorVar.alpha = 0.0;
//    this->endColor.red = 1.0f;
//    this->endColor.green = 1.0f;
//    this->endColor.blue = 0.0f;
//    this->endColor.alpha = 0.5f;
//    this->endColorVar.red = 0.5f;
//    this->endColorVar.green = 0.5f;
//    this->endColorVar.blue = 0.0f;
//    this->endColorVar.alpha = 0.0f;
//
//    // additive
//    blendAdditive = true;
/*
    duration = -1;

	// gravity
	gravityX = 0;
	gravityY = 0;

	// angle
	angle = 90;
	angleVar = 10;

	// radial acceleration
	radialAccel = 0;
	radialAccelVar = 0;

	// emitter position
	posX = 50;
	posY = 150;
	posVarX = 5;
	posVarY = 20;

	// life of particles
	life = 0;//3;
	lifeVar = 0.25;

	// speed of particles
	speed = 300;//60;
	speedVar = 20;

	// size, in pixels
	size = 100.0f;
	sizeVar = 10.0f;

	// emits per frame
	emissionRate = totalParticles/life;

	// color of particles
	startColor.red = 0.76f;
	startColor.green = 0.25f;
	startColor.blue = 0.12f;
	startColor.alpha = 1.0f;
	startColorVar.red = 0.0;
	startColorVar.green = 0.0;
	startColorVar.blue = 0.0;
	startColorVar.alpha = 0.0;
	endColor.red = 0.0f;
	endColor.green = 0.0f;
	endColor.blue = 0.0f;
	endColor.alpha = 1.0f;
	endColorVar.red = 0.0f;
	endColorVar.green = 0.0f;
	endColorVar.blue = 0.0f;
	endColorVar.alpha = 0.0f;

	// additive
	blendAdditive = true;
     */
}

ke::FireSequencer::FireSequencer(const ke::FireSequencer& orig) : ParticleSequencer(orig){

}

ke::FireSequencer::~FireSequencer(){
    
}

