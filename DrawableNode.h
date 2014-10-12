/* 
 * File:   DrawableNode.h
 * Author: arnaudboeglin
 *
 * Created on July 18, 2009, 3:02 PM
 */

/**
 * \class DrawableNode
 *
 * \ingroup ke
 *
 * \brief Basic node of kimiya engine.
 * Works only with dynamic objects.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _DRAWABLENODE_H
#define	_DRAWABLENODE_H

#include "DrawableObject.h"
#include "Camera.h"
#include "SimpleIntervalAction.h"
#include "types.h"
#include "OGLMatrix.h"

#include <vector>

namespace ke {

    class Camera;
    class SimpleIntervalAction;

    class DrawableNode : public ke::DrawableObject {

    public:

        /**
         * Constructor
         */
        DrawableNode();

        /**
         * Constructor : create a node with another one.
         */
        DrawableNode(const ke::DrawableNode& orig);

        /**
         * Destructor
         *
         * If you delete a DrawableNode, you also delete
         * his children recursivly. If you don't want to delete them,
         * remove them before.
         */
        virtual ~DrawableNode();

        /**
         * Adds a new node as child.
         *
         * \param node : the node to add.
         */
        void add(ke::DrawableNode *node);

        /**
         * Removes a node.
         *
         * \param node : the node to remove.
         * \return Node deleted, you've to handle its deleting.
         */
        DrawableNode* remove(ke::DrawableNode *node);

        /**
         * Removes a node.
         *
         * \param index : index of the node to remove.
         * \return Node deleted, you've to handle its deleting.
         */
        DrawableNode* removeAt(int index);

        /**
         * Remove all the nodes, but it doesn't destroy them.
         * If you call it, you've to get them before and call delete
         * by yourself.
         *
         * \return Nodes deleted, you've to handle its deleting.
         * the last element has a null value to know when is the
         * array's end. You've to use delete for each element and delete[] for the array.
         */
        DrawableNode** removeAll();

        /**
         * \param index : index of the child you want to get.
         * \return the selected child.
         */
        ke::DrawableNode* getChild(int index);

        /**
         * \return the parent of the node ( NULL if it has no parent ).
         */
        ke::DrawableNode* getParent();

        /**
         * Draws the node, shouldn't be directly called.
         * Overrided by subclasses.
         */
        virtual void draw() = 0;

        /**
         * Draws the node and all his children. Shouldn't be Overrided or
         * directly called.
         */
        void explore();

        /**
         * Adds an IntervalAction to the node. You can then play it
         * by calling playAnimation with the animation's title.
         *
         * \param animation : IntervalAction to add.
         */
        void addAnimation(ke::SimpleIntervalAction *animation);

        /**
         * Removes an IntervalAction from the node.
         *
         * \param animation : the IntervalAction to remove.
         */
        void removeAnimation(ke::SimpleIntervalAction *animation);

        /**
         * Removes an IntervalAction from the node.
         *
         * \param title : title of the IntervalAction to remove.
         */
        void removeAnimation(std::string title);

        /**
         * Plays an IntervalAction of the node.
         *
         * \param title : title of the IntervalAction to play.
         */
        void playAnimation(std::string title);

        /**
         *
         */
        void stopAnimation(std::string title);

        /**
         * Moves the node.
         *
         * \param x : move x.
         * \param y : move y.
         */
        void move(float x, float y);

        /**
         * Sets the position of the node.
         *
         * \param x : new x position.
         * \param y : new y position.
         */
        void setPosition(float x, float y);

        /**
         * \return position x of the node.
         */
        float getPosX() const;

        /**
         * \return position y of the node.
         */
        float getPosY() const;

        float getAbsoluteX() const;

        float getAbsoluteY() const;

        /**
         * Sets the scale x and y of the node.
         *
         * \param x : scale x.
         * \param y : scale y.
         */
        void setScale(float x, float y);

        /**
         * \return scale x of the node.
         */
        float getScaleX() const;

        /**
         * \return scale y of the node.
         */
        float getScaleY() const;

        /**
         * Sets the rotation of the node.
         *
         * \param r : rotation in degrees.
         */
        void setRotation(float r);

        /**
         * \return rotation of the node in degrees.
         */
        float getRotation() const;

        /**
         * \return opacity of the node ( between 0 et 1 ).
         */
        float getOpacity() const;

        /**
         * Sets the opacity of the node.
         *
         * \param opacity : new opacity of the node.
         */
        void setOpacity(float opacity);

        /**
         * \return color of the node.
         */
        ke::Color& getColor();

        /**
         * Sets the color of the node ( white by default ).
         *
         * \param color : new color of the node.
         */
        void setColor(ke::Color &color);

        /**
         * Sets the anchor point. It's used
         * to define transformations. Scale
         * and rotation centers.
         * By default it's set at the middle of
         * the node for the most of node types.
         *
         * \param x : anchor x.
         * \param y : anchor y.
         */
        void setAnchor(float x, float y);

        /**
         * \return anchor x.
         */
        float getAnchorX() const;

        /**
         * \return anchor y.
         */
        float getAnchorY() const;

        /**
         * \return z-index of the node.
         */
        float getZIndex() const;

        /**
         * Sets the z-index of the node.
         *
         * \param z : new z-index.
         */
        void setZIndex(float z);

        float getWidth() const;

        void setWidth(float w);

        float getHeight() const;

        void setHeight(float h);

        /**
         * Attaches a camera to the node. It means that
         * the node keep his position on the screen
         * even if the camera moves, it moves with the camera.
         *
         * You can only attach a node to one camera.
         *
         * \param camera : camera you want to attach.
         */
        void attachCamera(ke::Camera *camera);

        /**
         * Release the camera you've attached before.
         */
        void releaseCamera();

        /**
         * \return true if the node is currently visible.
         */
        bool isVisible();

        /**
         * Show the Node.
         */
        void show();

        /**
         * Hide the Node.
         */
        void hide();

    protected:

        ke::DrawableNode *parent;
        std::vector<ke::DrawableNode*> children;

        float posX;
        float posY;
        float width;
        float height;

        float scaleX;
        float scaleY;
        float rot;
        float zIndex;

        float anchorX;
        float anchorY;

        float opacity;

        ke::Color color;

        ke::Camera *camera;

        std::vector<ke::IntervalAction*> animations;

        ke::OGLMatrix tMat;

        bool visible;

    private:

        void initMatrices(std::vector<DrawableNode*> &vec);

        float getFullZIndex();
        float getFullRot();

    };

}

#endif	/* _DRAWABLE_H */

