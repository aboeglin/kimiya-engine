/* 
 * File:   DrawableCircle.h
 * Author: jonas
 *
 * Created on 28 juillet 2009, 15:56
 */

/**
 * \class DrawableCircle
 *
 * \ingroup ke
 *
 * \author Jonas BRU
 *
 */

#ifndef _DrawableCircle_H
#define	_DrawableCircle_H

#include "DrawableGeometricObject.h"

namespace ke {

    static const float PI = 3.1415926535898;

    class DrawableCircle : public ke::DrawableGeometricObject {

    public:

        /**
         * Constructor
         *
         * \param posX : position x of the center.
         * \param posY : position y of the center.
         * \param ray : ray of the circle.
         */
        DrawableCircle(float posX, float posY, float ray);

        /**
         * Constructor : create a Circle with another one.
         */
        DrawableCircle(const ke::DrawableCircle& orig);

        /**
         * Destructor
         */
        virtual ~DrawableCircle();

        /**
         * Shouldn't directly called.
         */
        void draw();

        /**
         * Sets the position of the Circle.
         *
         * \param x : new position x.
         * \param y : new position y.
         */
        void setPosition(float x, float y);

        /**
         * Moves the circle.
         *
         * \param x : vertical move.
         * \param y : horizontal move.
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

        float posX;
        float posY;

        float ray;

        float angle_start;
        float angle_end;
    };

}

#endif	/* _DrawableCircle_H */

