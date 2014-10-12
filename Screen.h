/* 
 * File:   Screen.h
 * Author: arnaudboeglin
 *
 * Created on November 13, 2009, 8:03 PM
 */

#ifndef _SCREEN_H
#define	_SCREEN_H

#include "Menu.h"
#include "Scene.h"


namespace ke{

    class Screen {

    public:

        Screen(int width, int height);
        Screen(const Screen& orig);
        virtual ~Screen();

        void addMenu(ke::Menu menu);

        ke::Menu* getMenu(int i);

        Menu* removeMenu(int i);

        void removeMenu(ke::Menu* menu);

        void render();

    private:

        std::vector<ke::Menu*> menus;

        ke::Scene *scene;

        int width;

        int height;

    };

}

#endif	/* _SCREEN_H */

