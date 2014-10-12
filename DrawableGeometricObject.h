/* 
 * File:   DrawableGeometricObject.h
 * Author: jonas
 *
 * Created on 25 juillet 2009, 22:42
 */

/**
 * \class DrawableGeometricObject
 *
 * \ingroup ke
 *
 * \author Jonas BRU
 *
 */

#ifndef _DRAWABLEGEOMETRICOBJECT_H
#define	_DRAWABLEGEOMETRICOBJECT_H

#include "DrawableObject.h"
#include "DrawableNode.h"

#include <string>

//TODO: modifier la gestion des couleurs pour les DrawableGeometricObjects.

namespace ke {

    class DrawableGeometricObject : public ke::DrawableNode {

    public:

        DrawableGeometricObject();
        DrawableGeometricObject(const ke::DrawableGeometricObject& orig);
        virtual ~DrawableGeometricObject() = 0;

    //    void move(float x, float y) = 0;
    //
    //    void setPosition(float x, float y) = 0;
    //
    //    float getPosX() const = 0;
    //    float getPosY() const = 0;
    //
    //    void setScale(float x, float y);
    //    float getScaleX() const;
    //    float getScaleY() const;
    //
    //    void setRotation(float r);
    //    float getRotation() const;
    //
    //    float getOpacity();
    //    void setOpacity(float opacity);
    //
    //    void setAnchor(float x, float y);

    //    float getAnchorX();
    //    float getAnchorY();

        void setColor(float red, float green, float blue);

    //    float getZIndex();
    //    void setZIndex(float z);

    protected:

    //    float scaleX;
    //    float scaleY;
    //    float rotation;
    //    float zIndex;
    //
    //    float anchorX;
    //    float anchorY;
    //
    //    float opacity;

        float red;
        float green;
        float blue;

    private:

    };

}

#endif	/* _DRAWABLEGEOMETRICOBJECT_H */

