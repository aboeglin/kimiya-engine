/* 
 * File:   Animation.h
 * Author: arnaudboeglin
 *
 * Created on July 20, 2009, 1:01 AM
 */

/**
 * \class Animation
 *
 * \ingroup ke
 *
 * \brief Animation to add to a Sprite.
 *
 * \author Jonas BRU
 *
 */

#ifndef _ANIMATION_H
#define	_ANIMATION_H

#include "Sprite.h"
#include "IntervalAction.h"

#include <vector>

namespace ke {

    class Animation : public ke::IntervalAction {

    public:

        /**
         * Constructor
         *
         * \param title : title of Animation
         */
        Animation(std::string title);

        /**
         * Constructor
         *
         * \param title : title of the Animation.
         * \param duration : duration of the Animation.
         */
        Animation(std::string title, float duration);

        /**
         * Constructor : create an Animation with another one.
         *
         * \param orig
         */
        Animation(const ke::Animation& orig);

        /**
         * Destructor
         */
        virtual ~Animation();

        /**
         * Add a texture to the Animation at the end of
         * actual textures present in the Animation.
         *
         * \param tex : texture to add.
         */
        void addTexture(ke::Texture2D *tex);

        /**
         * Add a texture to the Animation at the given
         * position.
         *
         * \param tex : texture to add.
         * \param pos : position to add the Texture.
         */
        void insertTexture(ke::Texture2D *tex, int pos);

        /**
         * Remove the given texture.
         *
         * \param tex : texture to remove.
         */
        void removeTexture(ke::Texture2D *tex);

        /**
         * Remove the texture at the given position
         *
         * \param pos : position of texture to remove.
         */
        void removeTexture(int pos);

    private:

        std::vector<ke::Texture2D*> textures;

        virtual void doNextStep();

    };

}

#endif	/* _ANIMATION_H */

