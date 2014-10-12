/* 
 * File:   IntervalActionTransformation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:00
 */

/**
 * \class IntervalActionTransformation
 *
 * \ingroup ke
 *
 * \brief Main class of interval action transformations.
 *
 * \author Jonas BRU
 *
 */

#ifndef _INTERVALACTIONTRANSFORMATION_H
#define	_INTERVALACTIONTRANSFORMATION_H

#include "SimpleIntervalAction.h"

namespace ke {

    class IntervalActionTransformation : public ke::SimpleIntervalAction {

    public:

        /**
         * Constructor
         *
         * \param title : title of IntervalActionTransformation.
         */
        IntervalActionTransformation(std::string title);

        /**
         * Constructor
         *
         * \param title : title of the IntervalActionTransformation.
         * \param duration : duration of the IntervalActionTransformation.
         */
        IntervalActionTransformation(std::string title, float duration);

        /**
         * Constructor : create an IntervalActionTransformation with another one.
         *
         * \param orig : object you want to copy.
         */
        IntervalActionTransformation(const ke::IntervalActionTransformation& orig);

        /**
         * Destructor
         */
        virtual ~IntervalActionTransformation() = 0;

    private:

    };

}

#endif	/* _INTERVALACTIONTRANSFORMATION_H */

