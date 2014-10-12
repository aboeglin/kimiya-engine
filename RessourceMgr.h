/* 
 * File:   RessourceMgr.h
 * Author: arnaudboeglin
 *
 * Created on July 17, 2009, 9:02 PM
 */

/**
 * \class RessourceMgr
 *
 * \ingroup ke
 *
 * \brief Provides you proper ressources you can need.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _RESSOURCEMGR_H
#define	_RESSOURCEMGR_H

#include "Image.h"
#include "Texture2D.h"

#include <map>

namespace ke {

    class RessourceMgr : public ke::Object {

    public:

        /**
         * \return the shared RessourceMgr.
         */
        static ke::RessourceMgr* getMgr();

        /**
         * delete the shared RessourceMgr.
         */
        static void destroyMgr();

        /**
         * Destructor
         */
        virtual ~RessourceMgr();

//        /**
//         * Loads an image.
//         *
//         * \param path : file path of the image to load.
//         * \return loaded image.
//         */
//        Image* getImage(std::string path);

        /**
         * Loads a texture.
         *
         * \param path : file path of the texture to load.
         * \return loaded texture.
         */
        Texture2D* getTexture(std::string path);

        /**
         * Loads a texture.
         *
         * \param image : image of the texture to load.
         * \return loaded texture.
         */
        Texture2D* getTexture(ke::Image *image);

        /**
         * Loads a texture.
         *
         * \param path : file path of the textures to load.
         * \param width : width of each texture to load.
         * \param height : height of each texture to load
         * \param len : number of textures effectively loaded
         * \return loaded textures.
         */
        Texture2D** getTextures(std::string path, int width, int height, int *len);
        
        /**
         * Loads a texture.
         *
         * \param image : image of the textures to load.
         * \param width : width of each texture to load.
         * \param height : height of each texture to load
         * \param len : number of textures effectively loaded
         * \return loaded textures.
         */
        Texture2D** getTextures(ke::Image *image, int width, int height, int *len);

        /**
         * Deletes a texture.
         *
         * \param path : file path of the texture to delete.
         */
        void deleteTexture(std::string path);

        /**
         * Deletes a texture.
         *
         * \param tex : texture to delete.
         */
        void deleteTexture(ke::Texture2D *tex);

    private:

        RessourceMgr();
        RessourceMgr(const ke::RessourceMgr& orig);
        static ke::RessourceMgr *mgr;

        std::map<std::string, ke::Texture2D*> textures;

    };

}

#endif	/* _RESSOURCEMGR_H */

