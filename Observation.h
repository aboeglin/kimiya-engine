/* 
 * File:   Observation.h
 * Author: arnaudboeglin
 *
 * Created on July 21, 2009, 12:14 PM
 */

/**
 * \class Observation
 *
 * \ingroup ke
 *
 * \brief An Observation is created by the postObservation method of
 * ObservationCenter, and can be got in override method observe(ke::Observation)
 * of Observer subclasses.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _OBSERVATION_H
#define	_OBSERVATION_H

#include "Object.h"

#include <string>
#include <map>

namespace ke {

    class Observation : public ke::Object {

    public:

        /**
         * Constructor
         *
         * \param title : name of the Observation.
         * \param sender : object which posted the Observation.
         * \param infos : datas you might want to add to the Observation.
         */
        Observation(std::string title, ke::Object *sender, std::map<std::string, std::string> &infos);

        /**
         * Constructor : create an Observation with another one
         *
         * \param orig : Observation you want to add.
         */
        Observation(const ke::Observation& orig);

        /**
         * Destructor
         */
        virtual ~Observation();

        /**
         * \return title of the Observation.
         */
        std::string getTitle() const;

        /**
         * \return sender of the Observation.
         */
        ke::Object* getSender() const;

        /**
         * \param key : key of property you want to get.
         * \return associated value.
         */
        std::string getProperty(std::string key);

    private:

        std::string title;
        ke::Object *sender;
        std::map<std::string, std::string> *infos;

    };

}

#endif	/* _OBSERVATION_H */

