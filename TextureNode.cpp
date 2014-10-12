/* 
 * File:   TextureNode.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 19, 2009, 7:06 PM
 */

#include "TextureNode.h"
#include "Camera.h"
#include "Director.h"
#include "RessourceMgr.h"

#ifdef MAC
#include <OpenGL/GL.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

#include <iostream>

ke::TextureNode::TextureNode() {
    
}

ke::TextureNode::TextureNode(ke::Texture2D *tex){
    this->tex       = tex;

    this->posX      = 0;
    this->posY      = 0;
    this->anchorX   = this->tex->getWidth() / 2;
    this->anchorY   = this->tex->getHeight() / 2;
    this->width     = this->tex->getWidth();
    this->height    = this->tex->getHeight();
}

ke::TextureNode::TextureNode(ke::Texture2D *tex, float x, float y, ke::DrawableNode *parent){
    this->tex = tex;
    
    this->posX      = x;
    this->posY      = y;
    this->anchorX   = this->tex->getWidth() / 2;
    this->anchorY   = this->tex->getHeight() / 2;
    this->width     = this->tex->getWidth();
    this->height    = this->tex->getHeight();

    parent->add(this);
}

ke::TextureNode::TextureNode(std::string path){
    ke::RessourceMgr *rm = ke::RessourceMgr::getMgr();

    this->tex = rm->getTexture(path);
    this->posX      = 0;
    this->posY      = 0;
    this->anchorX   = this->tex->getWidth() / 2;
    this->anchorY   = this->tex->getHeight() / 2;
    this->width     = this->tex->getWidth();
    this->height    = this->tex->getHeight();
}

ke::TextureNode::TextureNode(const ke::TextureNode& orig) {

}

ke::TextureNode::~TextureNode() {
    
}

void ke::TextureNode::draw(){
//    ke::Camera *c = ke::Director::getDirector()->getScene()->getCurrentCamera();

    float vertices[18];
    float tex_coords[12];

    vertices[0] = 0;
    vertices[1] = 0;
    vertices[2] = 0;
    vertices[3] = this->getWidth();
    vertices[4] = 0;
    vertices[5] = 0;
    vertices[6] = 0;
    vertices[7] = this->getHeight();
    vertices[8] = 0;
    vertices[9] = this->getWidth();
    vertices[10] = 0;
    vertices[11] = 0;
    vertices[12] = this->getWidth();
    vertices[13] = this->getHeight();
    vertices[14] = 0;
    vertices[15] = 0;
    vertices[16] = this->getHeight();
    vertices[17] = 0;

    tex_coords[0] = 0.f;
    tex_coords[1] = 1.f;
    tex_coords[2] = 1.f;
    tex_coords[3] = 1.f;
    tex_coords[4] = 0.f;
    tex_coords[5] = 0.f;
    tex_coords[6] = 1.f;
    tex_coords[7] = 1.f;
    tex_coords[8] = 1.f;
    tex_coords[9] = 0.f;
    tex_coords[10] = 0.f;
    tex_coords[11] = 0.f;

    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);  
    glEnable(GL_TEXTURE_2D);

        this->tex->bind();

        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glTexCoordPointer(2, GL_FLOAT, 0, tex_coords);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void ke::TextureNode::setTexture(ke::Texture2D *tex){
    this->tex       = tex;
    this->width     = tex->getWidth();
    this->height    = tex->getHeight();
}

void ke::TextureNode::setTexture(ke::Texture2D *tex, float w, float h){
    this->tex       = tex;
    this->width     = w;
    this->height    = h;
}