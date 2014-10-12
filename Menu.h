/* 
 * File:   Menu.h
 * Author: arnaudboeglin
 *
 * Created on August 28, 2009, 3:11 PM
 */

#ifndef _MENU_H
#define	_MENU_H

#include "Layer.h"


namespace ke {

    class Menu : public ke::Layer {

    public:

        Menu();
        Menu(const ke::Menu& orig);
        virtual ~Menu();
        
    private:

    };

}

#endif	/* _MENU_H */

