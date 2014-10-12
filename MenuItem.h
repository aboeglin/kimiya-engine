/* 
 * File:   MenuItem.h
 * Author: arnaudboeglin
 *
 * Created on August 28, 2009, 3:11 PM
 */

#ifndef _MENUITEM_H
#define	_MENUITEM_H

#include "TextureNode.h"


namespace ke {

    class MenuItem : public ke::TextureNode {

    public:

        MenuItem();
        MenuItem(const ke::MenuItem& orig);
        virtual ~MenuItem();

    private:

    };

}

#endif	/* _MENUITEM_H */

