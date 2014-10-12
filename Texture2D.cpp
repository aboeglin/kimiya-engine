/* 
 * File:   Texture2D.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 18, 2009, 9:07 PM
 */

#include "Texture2D.h"
#include "RessourceMgr.h"

#ifdef MAC
#include <OpenGL/GLU.h>
#endif
#ifdef WINDOWS
#include <GL/glu.h>
#endif
#ifdef LINUX
#include <GL/glu.h>
#endif

#include <iostream>

ke::Texture2D::Texture2D(unsigned char *pixels, int width, int height, GLenum format, GLint internalFormat){
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &this->texID);
    glBindTexture(GL_TEXTURE_2D, this->texID);

    /* setup some parameters for texture filters and mipmapping */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //glTexImage2D (GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
    gluBuild2DMipmaps(GL_TEXTURE_2D, internalFormat, width, height, format, GL_UNSIGNED_BYTE, pixels);
    glDisable(GL_TEXTURE_2D);

    this->width = width;
    this->height = height;
}

ke::Texture2D::Texture2D(std::string path){
    ke::Image *img = new ke::Image(path);

    glEnable(GL_TEXTURE_2D);
    glGenTextures (1, &this->texID);
    glBindTexture (GL_TEXTURE_2D, this->texID);

//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, img->getWidth(), img->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    /* setup some parameters for texture filters and mipmapping */
//    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//    glTexImage2D (GL_TEXTURE_2D, 0, img->getInternalFormat(), img->getWidth(), img->getHeight(), 0, img->getFormat(), GL_UNSIGNED_BYTE, img->getPixels());
    gluBuild2DMipmaps (GL_TEXTURE_2D, img->getInternalFormat(),	img->getWidth(), img->getHeight(), img->getFormat(), GL_UNSIGNED_BYTE, img->getPixels());
    glDisable(GL_TEXTURE_2D);
    
    this->width = img->getWidth();
    this->height = img->getHeight();

    delete img;
}

ke::Texture2D::Texture2D(ke::Image *img) {
    glEnable(GL_TEXTURE_2D);
    glGenTextures (1, &this->texID);
    glBindTexture (GL_TEXTURE_2D, this->texID);

    /* setup some parameters for texture filters and mipmapping */
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //glTexImage2D (GL_TEXTURE_2D, 0, img->getInternalFormat(), img->getWidth(), img->getHeight(), 0, img->getFormat(), GL_UNSIGNED_BYTE, img->getPixels());
    gluBuild2DMipmaps (GL_TEXTURE_2D, img->getInternalFormat(), img->getWidth(), img->getHeight(), img->getFormat(), GL_UNSIGNED_BYTE, img->getPixels());
    glDisable(GL_TEXTURE_2D);
    
    this->width = img->getWidth();
    this->height = img->getHeight();
}

ke::Texture2D::Texture2D(const ke::Texture2D& orig) {
}

ke::Texture2D::~Texture2D() {
    glDeleteTextures(1, &this->texID);
}

void ke::Texture2D::bind(){
    glBindTexture(GL_TEXTURE_2D, this->texID);
}

int ke::Texture2D::getWidth(){
    return this->width;
}

int ke::Texture2D::getHeight(){
    return this->height;
}