/* 
 * File:   SimpleIntervalAction.h
 * Author: arnaudboeglin
 *
 * Created on August 28, 2009, 10:42 AM
 */

/**
 * \class SimpleIntervalAction
 *
 * \ingroup ke
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _SIMPLEINTERVALACTION_H
#define	_SIMPLEINTERVALACTION_H

#include "IntervalAction.h"

namespace ke {

    class SimpleIntervalAction : public ke::IntervalAction {

    public:

        /**
         * Constructor
         *
         * \param title : title of SimpleIntervalAction.
         */
        SimpleIntervalAction(std::string title);

        /**
         * Constructor
         *
         * \param title : title of the SimpleIntervalAction.
         * \param duration : duration of the SimpleIntervalAction.
         */
        SimpleIntervalAction(std::string title, float duration);

        /**
         * Constructor : create an SimpleIntervalAction with another one.
         *
         * \param orig : object you want to copy.
         */
        SimpleIntervalAction(const ke::SimpleIntervalAction& orig);

        /**
         * Destructor
         */
        virtual ~SimpleIntervalAction();

    private:

    };

}

#endif	/* _SIMPLEINTERVALACTION_H */

