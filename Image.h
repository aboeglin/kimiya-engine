/* 
 * File:   Image.h
 * Author: arnaudboeglin
 *
 * Created on July 16, 2009, 3:23 PM
 */

/**
 * \class Image
 *
 * \ingroup ke
 *
 * \brief Image of kimiya engine.
 *
 * It's the main Image class of the engine.
 * You shouldn't use anything else Image class.
 * PNGImage, JPEGImage & co are provided by RessourceMgr.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _IMAGE_H
#define	_IMAGE_H

#include <string>

#ifdef MAC
#include <OpenGL/GL.h>
#include <OpenGL/GLU.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "Object.h"

namespace ke {

    class Image : public Object {

    public:

        /**
         * Constructor
         *
         * \param path : file path of the image.
         */
        Image(std::string path);

        /**
         * Destructor
         */
        virtual ~Image();

        /**
         * \return pixels of the image.
         */
        unsigned char* getPixels();

        /**
         * \return width in pixels of the image.
         */
        unsigned int getWidth();

        /**
         * \return height in pixels of the image.
         */
        unsigned int getHeight();

        /**
         * \return depth of the image.
         */
        unsigned short getDepth();

        /**
         * \return internal format of the image.
         */
        GLint getInternalFormat();

        /**
         * \return format of the image.
         */
        GLenum getFormat();

        /**
         * \return file path of the image.
         */
        std::string getPath();

    protected:

        std::string path;

        unsigned char* pixels;
        unsigned int width;
        unsigned int height;
        unsigned short depth;
        GLenum format;
        GLint internalFormat;
        
    };

}

#endif	/* _IMAGE_H */

