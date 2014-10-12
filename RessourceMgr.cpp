/* 
 * File:   RessourceMgr.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 17, 2009, 9:02 PM
 */

#include "RessourceMgr.h"

#include <iostream>
#include <sstream>

ke::RessourceMgr *ke::RessourceMgr::mgr = NULL;

ke::RessourceMgr::RessourceMgr() {
    
}

ke::RessourceMgr::RessourceMgr(const ke::RessourceMgr& orig) {

}

ke::RessourceMgr::~RessourceMgr() {
    std::map<std::string, ke::Texture2D*>::iterator it;

    it = this->textures.begin();

    while(it != this->textures.end()){
        ke::Texture2D *tmp = it->second;
        this->textures.erase(it);
        if(tmp)
            delete tmp;
    }
}

ke::RessourceMgr *ke::RessourceMgr::getMgr(){
    if(ke::RessourceMgr::mgr == NULL)
        ke::RessourceMgr::mgr = new ke::RessourceMgr();
    return ke::RessourceMgr::mgr;
}

void ke::RessourceMgr::destroyMgr(){
    if(ke::RessourceMgr::mgr != NULL){
        delete ke::RessourceMgr::mgr;
        ke::RessourceMgr::mgr = NULL;
    }
}

//ke::Image *ke::RessourceMgr::getImage(std::string path){
//    ke::Image *res = NULL;
//
//    if(path.substr(path.length() - 3, 3) == "bmp")
//        res = new ke::BMPImage(path);
//    else if(path.substr(path.length() - 4, 4) == "jpeg")
//        res = new ke::JPEGImage(path);
//    else if(path.substr(path.length() - 3, 3) == "jpg")
//        res = new ke::JPEGImage(path);
//    else if(path.substr(path.length() - 3, 3) == "png")
//        res = new ke::PNGImage(path);
//    else
//        res = NULL;
//
//    return res;
//}

ke::Texture2D* ke::RessourceMgr::getTexture(std::string path){
    ke::Texture2D *res = NULL;
    res = this->textures[path];

    if(res == NULL){
        res = this->textures[path] = new ke::Texture2D(path);
    }

    return res;
}

ke::Texture2D* ke::RessourceMgr::getTexture(ke::Image *image){
    ke::Texture2D *res = NULL;
    std::string path = image->getPath();
    res = this->textures[path];

    if(res == NULL){
        res = this->textures[path] = new ke::Texture2D(image);
    }

    return res;
}

ke::Texture2D** ke::RessourceMgr::getTextures(std::string path, int width, int height, int *len){
    ke::Texture2D **res = NULL;
    ke::Image *image = new ke::Image(path);

    if((image->getWidth() % width) == 0 && (image->getHeight() % height) == 0){
        int nbCols = image->getWidth() / width;
        int nbRows = image->getHeight() / height;
        int nbTextures = nbRows * nbCols;
        int internalFormat = image->getInternalFormat();

        *len = nbTextures;
        res = new Texture2D*[nbTextures];

        for(int i=0; i<nbTextures; i++){
            std::ostringstream oss;

            oss << i;
            std::string id = image->getPath() + "@" + oss.str();

            res[i] = NULL;

            res[i] = this->textures[id];

            if(!res[i]){
                unsigned char *data = new unsigned char[width * height * internalFormat];
                int index = 0;
                int deb = i*width*height*internalFormat;

                for(int h=0; h<height; h++){
                    for(int w=0; w<width*internalFormat; w++){
                        data[index] = image->getPixels()[deb+w];
                        index++;
                    }
                    deb += width*internalFormat;
                }

                res[i] = new Texture2D(data, width, height, image->getFormat(), image->getInternalFormat());
                this->textures[id] = res[i];
                delete[] data;
            }
        }
    }

    delete image;

    return res;
}

ke::Texture2D** ke::RessourceMgr::getTextures(ke::Image *image, int width, int height, int *len){
    ke::Texture2D **res = NULL;

    if((image->getWidth() % width) == 0 && (image->getHeight() % height) == 0){
        int nbCols = image->getWidth() / width;
        int nbRows = image->getHeight() / height;
        int nbTextures = nbRows * nbCols;
        int internalFormat = image->getInternalFormat();

        *len = nbTextures;
        res = new ke::Texture2D*[nbTextures];
        
        for(int i=0; i<nbTextures; i++){
            std::ostringstream oss;

            oss << i;
            std::string id = image->getPath() + "@" + oss.str();

            res[i] = NULL;

            res[i] = this->textures[id];

            if(!res[i]){
                unsigned char *data = new unsigned char[width * height * internalFormat];
                int index = 0;
                int deb = i*width*height*internalFormat;

                for(int h=0; h<height; h++){
                    for(int w=0; w<width*internalFormat; w++){
                        data[index] = image->getPixels()[deb+w];
                        index++;
                    }
                    deb += width*internalFormat;
                }

                res[i] = new Texture2D(data, width, height, image->getFormat(), image->getInternalFormat());
                this->textures[id] = res[i];
                delete[] data;
            }
        }
    }

    return res;
}

void ke::RessourceMgr::deleteTexture(std::string path){
    std::map<std::string, ke::Texture2D*>::iterator it;
    ke::Texture2D *tex;
    it = this->textures.find(path);
    tex = it->second;
    this->textures.erase(it);
    delete tex;
}

void ke::RessourceMgr::deleteTexture(ke::Texture2D *tex){
    std::map<std::string, ke::Texture2D*>::iterator it;
    it = this->textures.begin();

    for(int i=0; i<this->textures.size() && it->second != tex; i++)
        it++;

    this->textures.erase(it);
    delete tex;
}