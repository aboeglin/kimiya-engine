/* 
 * File:   DrawableLine.h
 * Author: jonas
 *
 * Created on 25 juillet 2009, 23:39
 */

/**
 * \class DrawableLine
 *
 * \ingroup ke
 *
 * \author Jonas BRU
 *
 */

#ifndef _DRAWABLELINE_H
#define	_DRAWABLELINE_H

#include "DrawableGeometricObject.h"

namespace ke {

    class DrawableLine : public ke::DrawableGeometricObject {

    public:

        /**
         * Constructor
         *
         * \param beginX : position x of the first point.
         * \param beginY : position y of the first point.
         * \param endX : position x of the second point.
         * \param endY : position y of the second point.
         */
        DrawableLine(float beginX, float beginY, float endX, float endY);

        /**
         * Constructor : create a line with another one.
         */
        DrawableLine(const ke::DrawableLine& orig);

        /**
         * Destructor
         */
        virtual ~DrawableLine();

        /**
         * Shouldn't be called directly.
         */
        void draw();

        /**
         * Sets the position of the line. It keeps orientation and lenght.
         *
         * \param x : new position x.
         * \param y : new position y.
         */
        void setPosition(float x, float y);

        /**
         * Moves the position of the line. It keeps orientation and lenght.
         *
         * \param x : move x.
         * \param y : move y.
         */
        void move(float x, float y);

        /**
         * \return position x.
         */
        float getPosX() const;

        /**
         * \return position y.
         */
        float getPosY() const;

    private:

        float beginX;
        float beginY;

        float endX;
        float endY;

    };

}

#endif	/* _DRAWABLELINE_H */

