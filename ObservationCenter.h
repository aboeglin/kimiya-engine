/* 
 * File:   ObservationCenter.h
 * Author: arnaudboeglin
 *
 * Created on July 21, 2009, 12:14 PM
 */

/**
 * \class ObservationCenter
 *
 * \ingroup ke
 *
 * \brief Center which handle Observations. Any Object can post
 * an Observation to the ObservationCenter. When it's posted,
 * it's sent to all Observers which observe this Observation
 * ( identified by the title ).
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _OBSERVATIONCENTER_H
#define	_OBSERVATIONCENTER_H

#include <map>
#include <string>
#include <vector>

#include "Observer.h"

namespace ke {

    class ObservationCenter : public ke::Object {

    public:

        /**
         * Returns the shared ObservationCenter.
         *
         * \return the shared center.
         */
        static ke::ObservationCenter* getCenter();

        /**
         * Destroy the shared ObservationCenter.
         */
        static void destroyCenter();

        /**
         * Destructor
         */
        virtual ~ObservationCenter();

        /**
         * Adds an observer for an Observation.
         *
         * \param title : title of the observation.
         * \param o : Observer which observe.
         */
        void addObserver(std::string title, ke::Observer *o);

        /**
         * Removes an observer for an Observation.
         *
         * \param title : title of the observation.
         * \param o : Observer which don't observe anymore.
         */
        void removeObserver(std::string title, ke::Observer *o);

        /**
         * Posts an observation.
         *
         * \param title : title of the observation.
         * \param infos : informations you might want to add.
         * \param sender : sender which sends observation.
         */
        void postObservation(std::string title, std::map<std::string, std::string> &infos, ke::Object* sender);

    private:

        std::map<std::string, std::vector<ke::Observer*> > observers;

        static ke::ObservationCenter *center;

        ObservationCenter();
        ObservationCenter(const ke::ObservationCenter& orig);

    };

}

#endif	/* _OBSERVATIONCENTER_H */

