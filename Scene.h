/* 
 * File:   Scene.h
 * Author: arnaudboeglin
 *
 * Created on July 18, 2009, 3:02 PM
 */

/**
 * \class Scene
 *
 * \ingroup ke
 *
 * \brief Scene is an important entity.
 * 
 * It's the main node of all others. There's one Scene,
 * which is managed by Director. You may not have to
 * instanciate yourself a Scene objet. To get an instance
 * call getScene() method of Director.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _SCENE_H
#define	_SCENE_H

#include "DrawableNode.h"
#include "Camera.h"

namespace ke {

    class Scene : public ke::DrawableNode {

    public:

        /**
         * Constructor
         */
        Scene();

        /**
         * Constructor : creates a Scene with another one.
         *
         * \param orig : object to copy.
         */
        Scene(const ke::Scene& orig);

        /**
         * Destructor
         */
        virtual ~Scene();

        /**
         * Sets the current camera for rendering scene.
         * CAUTION : shouldn't be directly called.
         *
         *
         * \param cam : cam to set.
         */
        void setCurrentCamera(ke::Camera *cam);

        /**
         * \return current camera while rendering.
         */
        ke::Camera *getCurrentCamera();

        /**
         * Shouldn't be called by yourself.
         */
        void draw();

        /**
         * No effect, scene shouldn't be moved
         *
         * \param x
         * \param y
         */
        void move(float x, float y);

        /**
         * No effect, scene shouldn't be moved
         *
         * \param x
         * \param y
         */
        void setPosition(float x, float y);

    private:

        ke::Camera *currentCamera;

    };

}

#endif	/* _SCENE_H */

