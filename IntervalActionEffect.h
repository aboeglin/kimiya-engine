/* 
 * File:   IntervalActionEffect.h
 * Author: arnaudboeglin
 *
 * Created on July 23, 2009, 11:03 PM
 */

/**
 * \class IntervalActionEffect
 *
 * \ingroup ke
 *
 * \brief Main class of interval action effects family.
 *
 * Look at ColorEffect, or OpacityEffect.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _INTERVALACTIONEFFECT_H
#define	_INTERVALACTIONEFFECT_H

#include "SimpleIntervalAction.h"

namespace ke {

    class IntervalActionEffect : public ke::SimpleIntervalAction {

    public:

        /**
         * Constructor
         *
         * \param title : title of IntervalActionEffect.
         */
        IntervalActionEffect(std::string title);

        /**
         * Constructor
         *
         * \param title : title of IntervalActionEffect.
         * \param duration : duration of the IntervalActionEffect.
         */
        IntervalActionEffect(std::string title, float duration);

        /**
         * Constructor : create an IntervalActionEffect with another one.
         *
         * \param orig : object you want to copy.
         */
        IntervalActionEffect(const ke::IntervalActionEffect& orig);

        /**
         * Destructor
         */
        virtual ~IntervalActionEffect() = 0;

    private:

    };

}

#endif	/* _INTERVALACTIONEFFECT_H */

