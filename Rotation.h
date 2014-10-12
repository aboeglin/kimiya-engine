/* 
 * File:   Rotation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:01
 */

/**
 * \class Rotation
 *
 * \ingroup ke
 *
 * \brief Handle rotation effects.
 *
 * \author Jonas BRU
 *
 */

#ifndef _ROTATION_H
#define	_ROTATION_H

#include "IntervalActionTransformation.h"

namespace ke {

    class Rotation : public ke::IntervalActionTransformation {

    public:

        /**
         * Constructor
         *
         * \param title : title of Rotation.
         */
        Rotation(std::string title);

        /**
         * Constructor
         *
         * \param title : title of Rotation.
         * \param duration : duration of the Rotation.
         */
        Rotation(std::string title, float duration);

        /**
         * Constructor
         *
         * \param title : title of Rotation.
         * \param duration : duration of the Rotation.
         * \param angle : angle of the rotation.
         */
        Rotation(std::string title, float duration, float angle);

        /**
         * Constructor : creates an Rotation with another one.
         *
         * \param orig : object you want to copy.
         */
        Rotation(const ke::Rotation& orig);

        /**
         * Destructor
         */
        virtual ~Rotation();

        /**
         * Sets the angle.
         *
         * \param angle : angle to set.
         */
        void setAngle(float angle);

        /**
         * Shouldn't be called by yourself.
         */
        void play();

    private:

        float angle;
        float startAngle;

        void doNextStep();

    };

}

#endif	/* _ROTATION_H */

