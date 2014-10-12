/* 
 * File:   Layer.h
 * Author: jonas
 *
 * Created on 25 juillet 2009, 22:12
 */

/**
 * \class Layer
 *
 * \ingroup ke
 *
 * \brief Layer could be use to manage
 * z-index by groups for example, or to draw
 * a lot of things in it.
 *
 * \author Jonas BRU
 *
 */

#ifndef _LAYER_H
#define	_LAYER_H

#include "DrawableNode.h"
#include "DrawableGeometricObject.h"
#include <map>
#include <string>

namespace ke {

    class Layer : public ke::DrawableNode {

    public:

        /**
         * Constructor
         */
        Layer();

        /**
         * Constructor : create a Layer with another one.
         *
         * \param orig : object you want to copy.
         */
        Layer(const ke::Layer& orig);

        /**
         * Destructor
         */
        virtual ~Layer();

        //void add(std::string s, DrawableGeometricObject *dgo);

    //    void remove(std::string s);
    //    void removeAt(int i);
    //    void remove(DrawableGeometricObject *dgo);
    //
    //    DrawableGeometricObject* get(std::string s);
    //    DrawableGeometricObject* get(int i);

        /**
         * Shouldn't be called by yourself.
         */
        void draw();

    private:

//        std::map<std::string, ke::DrawableGeometricObject*> objects;

    };

}

#endif	/* _LAYER_H */

