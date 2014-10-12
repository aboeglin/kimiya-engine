/* 
 * File:   TextureNode.h
 * Author: arnaudboeglin
 *
 * Created on July 19, 2009, 7:06 PM
 */

/**
 * \class DrawableObject
 *
 * \ingroup ke
 *
 * \brief DrawableNode which can display a texture.
 *
 * \author Jonas BRU
 *
 */

#ifndef _TEXTURENODE_H
#define	_TEXTURENODE_H

#include "DrawableNode.h"
#include "Texture2D.h"

#include <string>

namespace ke {

    class TextureNode : public ke::DrawableNode {

    public:

        TextureNode();
        TextureNode(ke::Texture2D *tex);
        TextureNode(ke::Texture2D *tex, float x, float y, ke::DrawableNode *parent);
        TextureNode(std::string path);

        TextureNode(const ke::TextureNode& orig);
        virtual ~TextureNode() = 0;

        virtual void draw();

        void setTexture(ke::Texture2D *tex);

        void setTexture(ke::Texture2D *tex, float w, float h);

    private:

        ke::Texture2D *tex;

    };

}

#endif	/* _TEXTURENODE_H */

