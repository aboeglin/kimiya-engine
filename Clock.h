/* 
 * File:   Clock.h
 * Author: arnaudboeglin
 *
 * Created on July 20, 2009, 12:21 AM
 */

/**
 * \class Clock
 *
 * \ingroup ke
 *
 * \brief Manages the time for the engine.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _CLOCK_H
#define	_CLOCK_H

#include <ctime>

#include "Object.h"

namespace ke {

    class Clock : public Object {

    public:

        /**
         * Constructor
         */
        Clock();

        /**
         * Constructor : create a Clock with another one.
         */
        Clock(const ke::Clock& orig);

        /**
         * Destructor
         */
        virtual ~Clock();

        /**
         * Clock gives you the time ellapsed since
         * the application lauching.
         *
         * \return time in millisecondes.
         */
        int millisSinceBeginning();

        /**
         * Should not be called !
         */
        void setTimeForCurrentRound(int t);

    private:

        float startTime;
        float previousRoundTime;

    };

}

#endif	/* _CLOCK_H */

