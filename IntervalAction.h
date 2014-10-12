/* 
 * File:   IntervalAction.h
 * Author: arnaudboeglin
 *
 * Created on July 20, 2009, 12:55 AM
 */

/**
 * \class IntervalAction
 *
 * \ingroup ke
 *
 * \brief Gives a manner to add some interval actions to your nodes.
 *
 * It's a virtual class, look at its children to get more details.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _INTERVALACTION_H
#define	_INTERVALACTION_H

#include <string>

#include "Object.h"

/*
 * Note : penser à bloquer les setters pour animation et ses fils, si l'animation est en cours d'execution.
 * De même, pour appell
 */

namespace ke {

    class DrawableNode;

    class IntervalAction : public ke::Object {

        friend class ke::DrawableNode;

    public:

        /**
         * Constructor
         *
         * \param title : title of IntervalAction
         */
        IntervalAction(std::string title);

        /**
         * Constructor
         *
         * \param title : title of the IntervalAction.
         * \param duration : duration of the IntervalAction.
         */
        IntervalAction(std::string title, float duration);

        /**
         * Constructor : create an IntervalAction with another one.
         *
         * \param orig
         */
        IntervalAction(const ke::IntervalAction& orig);

        /**
         * Destructor
         */
        virtual ~IntervalAction() = 0;

        /**
         * \return title of the IntervalAction.
         */
        std::string getTitle() const;

        /**
         * \return time when IntervalAction started.
         */
        int getBeginningTime() const;

        /**
         * Sets the IntervalAction's duration.
         *
         * \param duration : duration in seconds.
         */
        void setDuration(float duration);

        /**
         * \return duration in seconds.
         */
        float getDuration() const;

        /**
         * \return true if IntervalAction is playing.
         */
        bool isPlaying();

        /**
         * Shouldn't be directly called.
         */
        void setTarget(ke::DrawableNode *t);

        /**
         * \param b : if true, the interval action will played until
         * a stop call. Or set it to false again.
         */
        void setAutoRepeat(bool b);

        /**
         *  \return true if interval action is set as autorepeat, false otherwise.
         */
        bool isAutoRepeat();

    protected:

        ke::DrawableNode *target;

        virtual void play();
        void pause();
        virtual void stop();

    private:

        int beginnningTime;
        float duration;
        bool playing;

        std::string title;

        bool autoRepeat;

        virtual void doNextStep() = 0;

    };

}

#endif	/* _INTERVALACTION_H */

