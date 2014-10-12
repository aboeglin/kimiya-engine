/* 
 * File:   Texture2D.h
 * Author: arnaudboeglin
 *
 * Created on July 18, 2009, 9:07 PM
 */

/**
 * \class Texture2D
 *
 * \ingroup ke
 *
 * \brief Main ressource of the engine.
 *
 * \author Jonas BRU
 *
 */

#ifndef _TEXTURE2D_H
#define	_TEXTURE2D_H

#include "Image.h"

#ifdef MAC
#include <OpenGL/GL.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#endif

#include <string>

namespace ke {

    class Texture2D : public ke::Object {

    public:

        Texture2D(unsigned char *pixels, int width, int height, GLenum format, GLint internalFormat);
        Texture2D(std::string path);
        Texture2D(Image *img);
        Texture2D(const ke::Texture2D& orig);
        virtual ~Texture2D();

        void bind();
        int getWidth();
        int getHeight();

    private:

        GLuint texID;
        int width;
        int height;

    };

}

#endif	/* _TEXTURE2D_H */

