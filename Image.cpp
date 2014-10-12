/*
 *  Image.cpp
 *  2DEngine
 *
 *  Created by Arnaud BOEGLIN on 12/06/09.
 *  Copyright 2009 IUT Robert schuman. All rights reserved.
 *
 */

#include "Image.h"

#include "SOIL/SOIL.h"

ke::Image::Image(std::string path){
    this->path = path;

    int w, h, c;
    this->pixels = SOIL_load_image(path.c_str(), &w, &h, &c, SOIL_LOAD_RGBA);

    this->width  = w;
    this->height = h;
    this->depth = 32;

    this->format = GL_RGBA;
    this->internalFormat = 4;
}

ke::Image::~Image(){
    SOIL_free_image_data(this->pixels);
}

unsigned char* ke::Image::getPixels() {
	return this->pixels;
}

unsigned int ke::Image::getWidth() {
	return this->width;
}

unsigned int ke::Image::getHeight() {
	return this->height;
}

unsigned short ke::Image::getDepth() {
	return this->depth;
}

GLint ke::Image::getInternalFormat(){
    return this->internalFormat;
}

GLenum ke::Image::getFormat(){
    return this->format;
}

std::string ke::Image::getPath(){
    return this->path;
}