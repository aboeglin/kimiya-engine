/* 
 * File:   Scale.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:01
 */

/**
 * \class Scale
 *
 * \ingroup ke
 *
 * \brief Handle scale effects.
 *
 * \author Jonas BRU
 *
 */

#ifndef _SCALE_H
#define	_SCALE_H

#include "IntervalActionTransformation.h"

namespace ke {

    class Scale : public ke::IntervalActionTransformation{

    public:

        /**
         * Constructor
         *
         * \param title : title of Scale.
         * \param x : scale x.
         * \param y : scale y.
         */
        Scale(std::string title, float x, float y);

        /**
         * Constructor
         *
         * \param title : title of Scale.
         * \param duration : duration of the scale.
         * \param x : scale x.
         * \param y : scale y.
         */
        Scale(std::string title, float duration, float x, float y);

        /**
         * Destructor
         */
        virtual ~Scale();

        /**
         * Sets the scale at the end of the action.
         * 
         * \param x : scale x.
         * \param y : scale y.
         */
        void setFinalScale(float x, float y);

        /**
         * Shouldn't be called by yourself.
         */
        void play();

    private:

        float scaleX;
        float scaleY;
        float startX;
        float startY;

        virtual void doNextStep();
    };

}

#endif	/* _SCALE_H */

