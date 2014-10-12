/* 
 * File:   DrawableRectangle.h
 * Author: jonas
 *
 * Created on 26 juillet 2009, 12:09
 */

/**
 * \class DrawableRectangle
 *
 * \ingroup ke
 *
 * \brief Simple drawable rectangle of kimiya engine.
 *
 * \author Jonas BRU
 *
 */

#ifndef _DRAWABLERECTANGLE_H
#define	_DRAWABLERECTANGLE_H

#include "DrawableGeometricObject.h"

namespace ke {

    class DrawableRectangle : public DrawableGeometricObject {

    public:

        /**
         * Constructor
         *
         * \param posX : position x of the bottom left point.
         * \param posY : position y of the bottom left point.
         * \param width : width of the rectangle.
         * \param height : height of the rectangle
         */
        DrawableRectangle(float posX, float posY, float width, float height);

        /**
         * Constructor : create a rectangle with another one.
         */
        DrawableRectangle(const DrawableRectangle& orig);

        /**
         * Destructor
         */
        virtual ~DrawableRectangle();

        /**
         * Shouldn't be called directly.
         */
        void draw();

        /**
         * Sets the position of the rectangle.
         *
         * \param posX : new position x.
         * \param posY : new position y.
         */
        void setPosition(float posX, float posY);

        /**
         * Moves the position of the line.
         *
         * \param posX : move x.
         * \param posY : move y.
         */
        void move(float posX, float posY);

        /**
         * \return position x.
         */
        float getPosX() const;

        /**
         * \return position y.
         */
        float getPosY() const;

        /**
         * Select filled rectangle or not.
         *
         * \param bo : true if you want it to be filled.
         */
        void setFill(bool bo);

    private:

        float posX;
        float posY;

        float width;
        float height;

        bool filled;

    };

}

#endif	/* _DRAWABLERECTANGLE_H */

