/* 
 * File:   TextNode.h
 * Author: arnaudboeglin
 *
 * Created on August 28, 2009, 3:11 PM
 */

#ifndef _TEXTNODE_H
#define	_TEXTNODE_H

#include "DrawableNode.h"


namespace ke {

    class TextNode : public ke::DrawableNode {

    public:

        TextNode();
        TextNode(const ke::TextNode& orig);
        virtual ~TextNode();
        
    private:

    };

}

#endif	/* _TEXTNODE_H */

