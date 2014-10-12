/* 
 * File:   ParticleSequencer.h
 * Author: jonas
 *
 * Created on 28 août 2009, 15:09
 */

#ifndef _PARTICLESEQUENCER_H
#define	_PARTICLESEQUENCER_H

#include "DrawableNode.h"
#include "Particle.h"
#include <vector>

namespace ke {

    class ParticleSequencer : public ke::DrawableNode {

    public:

        ParticleSequencer();
        ParticleSequencer(const ke::ParticleSequencer& orig);
        virtual ~ParticleSequencer();

        void draw();

        void updateParticles();

        void stop();

        bool isFull();

    protected:

        std::vector<ke::Particle*> particles;

        bool active;

        float beginningTime;
        float lastUpdateTime;

        float duration;
        float elapsed;

        float gravityX;
        float gravityY;

        float posVarX;
        float posVarY;

        float angle;
        float angleVar;

        float speed;
        float speedVar;

        float tangentialAccel;
        float tangentialAccelVar;

        float radialAccel;
        float radialAccelVar;

        float size;
        float sizeVar;

        float life;
        float lifeVar;

        ke::Color startColor;
        ke::Color startColorVar;

        ke::Color endColor;
        ke::Color endColorVar;

        int totalParticles;

        bool blendAdditive;

        bool colorModulate;

        float emissionRate;
        float emitCounter;

        ke::Texture2D *texture;

        ke::OGL3Rect *vertices;
	
	ke::Color *colors;

        ke::OGL2Rect *textCoords;

        //	// vertices buffer id
//	GLuint verticesID;
//	// colors buffer id
//	GLuint colorsID;
//
//        GLuint textCoordsID;

        float particleCount;

        void addParticle();

        static float rand();

    };

    class FireSequencer : public ke::ParticleSequencer {

    public:
        
        FireSequencer();
        FireSequencer(const ke::FireSequencer& orig);
        ~FireSequencer();

    };
}

#endif	/* _PARTICLESEQUENCER_H */

