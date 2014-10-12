/* 
 * File:   Director.h
 * Author: arnaudboeglin
 *
 * Created on July 19, 2009, 8:31 PM
 */

/**
 * \class Director
 *
 * \ingroup ke
 *
 * \brief Main manager of kimiya engine, it manages
 * Scene, cameras, initialise OpenGL and more.
 *
 * \author Arnaud BOEGLIN
 *
 */

/**
 * TODO: 2DEngine
    -Revoir la gestion de l'attachement des caméra [done].
    -Revérifier les delete [done: should be].
    -Camera::setNodeToFollow(DrawableNode) : Suit l'objet que lors de son premier déplacement [done]
    -Revoir les paramètres des mipmaps lors de la création d'une texture OGL.
    -Intégrer les effets au moteur ( brouillard, flamme, explosions, ... ).
    -Revoir la gestion des Animations ( les étendre à drawablenode // Voir une séparation entre SequenceAnimation et le reste ). [1/2 done]
    -Intégrer show/hide pour les DrawableNode [ done, a voir si on le fait recursivement pour les enfants ou pas ]
    -Intégrer les namespaces [done].
    -Intégrer les constantes de ke::Camera [done] .
    -Gérer le repeat sur une Animation/IntervalAction [done].
    -Voir pour le format d'animations et l'organisation des dossiers.
    -Intégrer les couleurs à Sprite.[1/2 done]
    -removeAnimation & co à implémenter [done, à tester].
    -GROS problemes au niveau du RessourceMgr, getTexture() plante dans tous les sens O_o [done]
    -Revoir les Z, et les arrays pour les particules[pas urgent].
    -Compléter les différentes particules[pas urgent].
    -BUG : Le nombre d'items que l'on met dans un layer influe sur les autres éléments affichés .. [may be done, compiling problems ..]
    -Revoir les classes d'Image ( code à nettoyer, débuguer ( bmp ), et gérer les cas d'erreur ( image non trouvable ).
    -Revoir les classes de texture ( éliminer si possible la génération de mipmaps qui bouffe énormément de ram ).
    -Revoir les noms des classes d'animation, ainsi que les noms des fonctions d'ajout d'animation.
    -Revoir les constructeurs de recopie et les mettre à jour.
    -Penser à gérer l'affichage de texte, de menus, etc ..
    -Penser à trouver un moyen de gérer le destructeur de DrawableNode ( deletes .. ).
    -Gérer les menus ( 6è caméra specifique, MenuNode, hérite de DrawableObject, et attache automatiquement la caméra 6 ).
    -Penser à gérer la sauvegarde d'images.
    -Tester les caméras multiples [ done ]
    -Ne pas dessiner ce qui n'est pas dans le champs de la caméra.
    -Revoir les intervalles de caméra, réussir à intégrer FLT_MAX.
    -Integrer width & height pour DrawableObject
 */

#ifndef _DIRECTOR_H
#define	_DIRECTOR_H

#include "Scene.h"
#include "Clock.h"
#include "Camera.h"
#include "Menu.h"

#include <map>

namespace ke {

    class Director : public ke::Object {

    public:

        /**
         * Destructor
         */
        virtual ~Director();

        /**
         * Returns the only instance of Director.
         *
         * \return the shared Director.
         */
        static ke::Director* getDirector();

        /**
         * Kills the only instance of Director.
         */
        static void destroy();

        /**
         * Returns the only instance of Scene.
         *
         * \return the shared Scene.
         */
        ke::Scene* getScene();

        /**
         * Returns the only instance of Clock.
         *
         * \return the shared Clock.
         */
        ke::Clock* getSharedClock();

        /**
         * Returns one of the 5 available cameras.
         *
         * \param cam : the cam you want to get.
         * \return the wanted camera.
         */
        ke::Camera* getCamera(ke::cam_type cam);

        /**
         * Enables a camera.
         *
         * \param cam : camera to enabled.
         * \return the enabled camera.
         */
        ke::Camera* enableCamera(ke::cam_type cam);

        /**
         * Disables a camera.
         *
         * \param cam : the camera to disable.
         */
        void disableCamera(ke::cam_type cam);

        /**
         * Initialises the engine.
         */
        void init();

        /**
         * Draws the scene in his current state.
         */
        void drawScene();

        void addMenu(ke::Menu *m);

        ke::Menu* removeMenu(int index);

        ke::Menu* removeMenu(ke::Menu *m);

        ke::Menu* getMenu(int index);

    private:

        Director();
        Director(const ke::Director& orig);

        void initGL();

        static ke::Director *dir;

        ke::Scene *scene;

        ke::Clock *clock;

        std::map<int, std::pair<ke::Camera*, bool> > cameras;

        std::vector<ke::Menu*> menus;

    };

}

#endif	/* _DIRECTOR_H */

