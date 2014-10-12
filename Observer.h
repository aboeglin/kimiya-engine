/* 
 * File:   Observer.h
 * Author: arnaudboeglin
 *
 * Created on July 21, 2009, 12:12 PM
 */

/**
 * \class Observer
 *
 * \ingroup ke
 *
 * \brief Observer abstract class.
 *
 * If you want your class to can observe an Observation, you have
 * to subclass it by Observer and define observe method which is called
 * by ObservationCenter when an Observation is posted.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _OBSERVER_H
#define	_OBSERVER_H

#include "Observation.h"

namespace ke {

    class Observer {

    public:

        /**
         * You have to override it if you want to
         * manage observations with a class.
         *
         * \param o : Observation sent by ObservationCenter.
         */
        virtual void observe(ke::Observation &o) = 0;

    private:

    };

}

#endif	/* _OBSERVER_H */

