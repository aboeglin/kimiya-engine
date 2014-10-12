/* 
 * File:   Particle.h
 * Author: jonas
 *
 * Created on 28 août 2009, 15:10
 */

#ifndef _PARTICLE_H
#define	_PARTICLE_H

#include "TextureNode.h"
#include "types.h"

namespace ke {

    class Particle : public ke::TextureNode {
    
    public:

        Particle();
        Particle(ke::Texture2D *tex);
        Particle(ke::Texture2D *tex, float x, float y, ke::DrawableNode *parent);
        Particle(std::string path);

        Particle(const ke::Particle& orig);
        virtual ~Particle();
        
        float getDirX();
        float getDirY();
        float getTangentialAccel();
        ke::Color getDeltaColor();
        float getRadialAccel();
        float getSize();
        float getLife();

        void setDirX(float dirX);
        void setDirY(float dirY);
        void setRadialAccel(float radialAccel);
        void setTangentialAccel(float tangentialAccel);
        void setDeltaColor(ke::Color deltaColor);
        void setSize(float size);
        void setLife(float life);

    private:

        float dirX;
        float dirY;
        float radialAccel;
        float tangentialAccel;
        ke::Color deltaColor;
        float size;
        float life;

    };
}

#endif	/* _PARTICLE_H */

