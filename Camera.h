/* 
 * File:   Camera.h
 * Author: arnaudboeglin
 *
 * Created on July 19, 2009, 7:20 PM
 */

/**
 * \class Camera
 *
 * \ingroup ke
 *
 * \brief Cameras may not be instanciated by yourself.
 * Director provides you 5 cameras, a default one and 4
 * others. Look at Director's documentation page to see how
 * to manage cameras.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _CAMERA_H
#define	_CAMERA_H

#include "Object.h"
#include "Observer.h"
#include "DrawableNode.h"

namespace ke {

    class DrawableNode;

    class Camera : public ke::Observer, public ke::Object {

    public:

        /**
         * Constructor
         *
         * \param x : position X of the camera.
         * \param y : position Y of the camera.
         * \param fieldX : virtual field of the camera ( width ).
         * \param fieldY : virtual field of the camera ( height ).
         */
        Camera(float x, float y, float fieldX, float fieldY);

        /**
         * Constructor : create a Camera with another one.
         *
         * \param orig
         */
        Camera(const ke::Camera& orig);

        /**
         * Destructor
         */
        virtual ~Camera();

        /**
         * \param o
         */
        virtual void observe(ke::Observation &o);

        /**
         * Enables the Camera. It should not be
         * directly called.
         */
        void set();

        /**
         * Sets the node you want the camera follows. If the node moves,
         * the camera moves and stay centred on the node.
         *
         * \param dn : node to follow.
         */
        void setNodeToFollow(ke::DrawableNode *dn);

        /**
         * Moves the camera.
         *
         * \param x : vertical move.
         * \param y : horizontal move.
         */
        void move(float x, float y);

        /**
         * Places the camera.
         *
         * \param x : vertical position.
         * \param y : horizontal position.
         */
        void setPosition(float x, float y);

        /**
         * Sets the camera's field.
         *
         * \param fieldX : x field.
         * \param fieldY : y field.
         */
        void setField(float fieldX, float fieldY);

        /**
         * \return X position.
         */
        float getX() const;

        /**
         * \return Y position.
         */
        float getY() const;

        /**
         * \return fieldX value.
         */
        float getFieldX() const;

        /**
         * \return fieldY value.
         */
        float getFieldY() const;

        /**
         * Sets the camera's offset.
         *
         * \param x : offset x.
         * \param y : offset y.
         */
        void setOffset(float x, float y);

        /**
         * \return offX value.
         */
        float getOffX() const;

        /**
         * \return offY value.
         */
        float getOffY() const;

        /**
         * Sets the camera's dimension.
         *
         * \param w : width.
         * \param h : height.
         */
        void setDimension(float w, float h);

        /**
         * \return width value.
         */
        float getWidth() const;

        /**
         * \return height value.
         */
        float getHeight() const;

        /**
         * Sets the camera's z-index.
         *
         * \param z : start z.
         */
        void setStartZ(float z);

        /**
         * \return startZ value.
         */
        float getStartZ() const;

    private:

        float x;
        float y;

        float offX;
        float offY;

        float fieldX;
        float fieldY;

        float width;
        float height;

        ke::DrawableNode *toFollow;

        float startZ;

    };

}

#endif	/* _CAMERA_H */

