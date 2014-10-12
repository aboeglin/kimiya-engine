/* 
 * File:   units.h
 * Author: jonas
 *
 * Created on 25 juillet 2009, 22:29
 */

#ifndef _UNITS_H
#define	_UNITS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
struct Pos{
    float x;
    float y;
};

struct Size{
    float w;
    float h;
};

struct Rect{
    Pos p;
    Size s;
};



#ifdef	__cplusplus
}
#endif

#endif	/* _UNITS_H */

