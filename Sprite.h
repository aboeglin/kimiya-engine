/* 
 * File:   Sprite.h
 * Author: arnaudboeglin
 *
 * Created on July 18, 2009, 8:47 PM
 */

/**
 * \class Sprite
 *
 * \ingroup ke
 *
 * \brief Advanced DrawableNode with more specifics possibilities
 * like playing animations.
 *
 * \author Arnaud BOEGLIN.
 *
 */

#ifndef _SPRITE_H
#define	_SPRITE_H

#include "TextureNode.h"
#include "Animation.h"
//#include "IntervalAction.h"

#include <vector>
#include <string>

namespace ke {

    class Animation;

    class Sprite : public ke::TextureNode {

    public:

        /**
         * Constructor
         *
         * \param path : file path of the sprite.
         */
        Sprite(std::string path);

        /**
         * Constructor
         *
         * \param img : 
         */
        Sprite(ke::Texture2D *tex);

        /**
         * Constructor : creates a Sprite with another one.
         *
         * \param orig : object you want to copy.
         */
        Sprite(const ke::Sprite& orig);

        /**
         * Destructor
         */
        virtual ~Sprite();

        /**
         * Adds an IntervalAction to the sprite.
         *
         * \param animation : animation to add.
         */
        void addAnimation(ke::IntervalAction *animation);

        /**
         * Removes an IntervalAction to the sprite.
         *
         * \param animation : animation to add.
         */
        void removeAnimation(ke::IntervalAction *animation);

        /**
         * Shouldn't be directly called.
         */
        void draw();

    private:

    };

}

#endif	/* _SPRITE_H */

