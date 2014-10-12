/* 
 * File:   types.h
 * Author: jonas
 *
 * Created on 28 août 2009, 16:40
 */

/**
 * TODO: Passer Color à 3 attributs, réintégrer opacity.
 *
 */

#ifndef _TYPES_H
#define	_TYPES_H

#include <float.h>

#ifdef	__cplusplus
extern "C" {
#endif

namespace ke{

    enum cam_type{
        DEFAULT_CAM = 0,
        CAM_1       = 1,
        CAM_2       = 2,
        CAM_3       = 3,
        CAM_4       = 4,
    };

    static const int NB_OF_CAMERAS = 5;

    static const float ZIMA = 15000/(ke::NB_OF_CAMERAS + 1);
//    static const float ZIMA = 2000;

    static const float Z_MAX = ZIMA;

    static const float ZIMI = -1;

    struct Rect {
        float x;
        float y;
        float width;
        float height;
    };

    struct OGL2Rect {
        float x1;
        float y1;
        float x2;
        float y2;
        float x3;
        float y3;
        float x4;
        float y4;
    };

    struct OGL3Rect {
        float x1;
        float y1;
        float z1;
        float x2;
        float y2;
        float z2;
        float x3;
        float y3;
        float z3;
        float x4;
        float y4;
        float z4;
    };

    struct PointSprite {
        float x;
        float y;
        float size;
    };

    struct Color{
        float red;
        float green;
        float blue;
    };
}



#ifdef	__cplusplus
}
#endif

#endif	/* _TYPES_H */

