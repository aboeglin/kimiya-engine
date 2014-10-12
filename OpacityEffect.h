/* 
 * File:   OpacityEffect.h
 * Author: arnaudboeglin
 *
 * Created on July 23, 2009, 11:03 PM
 */

/**
 * \class OpacityEffect
 *
 * \ingroup ke
 *
 * \brief Handle opacity effects.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _OPACITYEFFECT_H
#define	_OPACITYEFFECT_H

#include "IntervalActionEffect.h"

namespace ke {

    class OpacityEffect : public ke::IntervalActionEffect {

    public:

        /**
         * Constructor
         *
         * \param title : title of OpacityEffect.
         */
        OpacityEffect(std::string title);
        
        /**
         * Constructor
         *
         * \param title : title of OpacityEffect.
         * \param duration : duration of the OpacityEffect.
         */
        OpacityEffect(std::string title, float duration);

        /**
         * Constructor
         *
         * \param title : title of OpacityEffect.
         * \param duration : duration of the OpacityEffect.
         * \param finalOpacity : opacity at the end of the effect.
         */
        OpacityEffect(std::string title, float duration, float finalOpacity);

        /**
         * Constructor : creates an OpacityEffect with another one.
         *
         * \param orig : object you want to copy.
         */
        OpacityEffect(const ke::OpacityEffect& orig);

        /**
         * Destructor
         */
        virtual ~OpacityEffect();

        /**
         * Sets the final opacity of the effect.
         *
         * \param finalOpacity : opacity to set.
         */
        void setFinalOpacity(float finalOpacity);

        /**
         * Shouldn't be called by yourself.
         */
        void play();

    private:

        float finalOpacity;
        float startOpacity;

        void doNextStep();

    };

}

#endif	/* _OPACITYEFFECT_H */

