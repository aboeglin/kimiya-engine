/* 
 * File:   Translation.h
 * Author: jonas
 *
 * Created on 22 juillet 2009, 22:02
 */

/**
 * \class Translation
 *
 * \ingroup ke
 *
 * \brief Handle translation effects.
 *
 * \author Jonas BRU
 *
 */

#ifndef _TRANSLATION_H
#define	_TRANSLATION_H

#include "IntervalActionTransformation.h"

namespace ke {

    class Translation : public ke::IntervalActionTransformation {

    public:

        Translation(std::string title, float x, float y);
        Translation(std::string title, float duration, float x, float y);
        virtual ~Translation();

        void setDistance(float x, float y);
        void play();

    private:

        float dX;
        float dY;
        float startX;
        float startY;

        virtual void doNextStep();
    };

}

#endif	/* _TRANSLATION_H */

