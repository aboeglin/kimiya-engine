/* 
 * File:   DrawableObject.h
 * Author: jonas
 *
 * Created on 25 juillet 2009, 22:09
 */

/**
 * \class DrawableObject
 *
 * \ingroup ke
 *
 * \brief Simple drawable object of kimiya engine.
 *
 * \author Jonas BRU
 * 
 */

#ifndef _DRAWABLEOBJECT_H
#define	_DRAWABLEOBJECT_H

#include "Object.h"
//#include "Director.h"

namespace ke {

    class DrawableObject : public ke::Object {

    public:

        DrawableObject();
        DrawableObject(const ke::DrawableObject& orig);
        virtual ~DrawableObject();

        /**
         * Draws the object, shouldn't be directly called.
         * Overrided by subclasses.
         */
        virtual void draw() = 0;

        /**
         * Moves the object.
         *
         * \param x : move x.
         * \param y : move y.
         */
        virtual void move(float x, float y) = 0;

        /**
         * Sets the position of the object.
         *
         * \param x : new x position.
         * \param y : new y position.
         */
        virtual void setPosition(float x, float y) = 0;

        /**
         * \return position x of the object.
         */
        virtual float getPosX() const = 0;

        /**
         * \return position y of the object.
         */
        virtual float getPosY() const = 0;

        /**
         * Sets the scale x and y of the object.
         *
         * \param x : scale x.
         * \param y : scale y.
         */
        virtual void setScale(float x, float y) = 0;

        /**
         * \return scale x of the object.
         */
        virtual float getScaleX() const = 0;

        /**
         * \return scale y of the object.
         */
        virtual float getScaleY() const = 0;

        /**
         * Sets the rotation of the object.
         *
         * \param r : rotation in degrees.
         */
        virtual void setRotation(float r) = 0;

        /**
         * \return rotation of the object in degrees.
         */
        virtual float getRotation() const = 0;

        /**
         * \return opacity of the object ( between 0 et 1 ).
         */
        virtual float getOpacity() const = 0;

        /**
         * Sets the opacity of the node.
         *
         * \param opacity : new opacity of the object.
         */
        virtual void setOpacity(float opacity) = 0;

        /**
         * Sets the anchor point. It's used
         * to define transformations. Scale
         * and rotation centers.
         * By default it's set at the middle of
         * the object for the most of DrawableObject subclasses.
         *
         * \param x : anchor x.
         * \param y : anchor y.
         */
        virtual void setAnchor(float x, float y) = 0;

        /**
         * \return anchor x.
         */
        virtual float getAnchorX() const = 0;

        /**
         * \return anchor y.
         */
        virtual float getAnchorY() const = 0;

        /**
         * \return z-index of the object.
         */
        virtual float getZIndex() const = 0;

        /**
         * Sets the z-index of the node.
         *
         * \param z : new z-index.
         */
        virtual void setZIndex(float z) = 0;

        virtual float getWidth() const = 0;

        virtual void setWidth(float w) = 0;

        virtual float getHeight() const = 0;

        virtual void setHeight(float h) = 0;

//        virtual void transform();
//        virtual void restore();

    private:

    };

}

#endif	/* _DRAWABLEOBJECT_H */

