/* 
 * File:   Node.h
 * Author: arnaudboeglin
 *
 * Created on July 18, 2009, 2:14 PM
 */

/**
 * \class Node
 *
 * \brief Deprecated.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _NODE_H
#define	_NODE_H

#include <vector>

//#include "KEBMPImage.h"

template <class T> class Node {
public:
    
    Node(){
        
    }

    Node(T val){
        this->value = val;
    }
    
    Node(const Node& orig){
        
    }
    
    virtual ~Node(){
        typedef typename std::vector< Node<T>* >::iterator myIT;
        myIT it;

        it = this->children.begin();
        while(it != this->children.end()){
            this->children.erase(it);
            delete *it;
            it++;
         }
    }
	
    void add(T n){
        Node<T> *tmp = new Node<T>();

        tmp->value = n;
        tmp->parent = this;
        this->children.push_back(tmp);
    }
    
    void remove(const T n){
        typedef typename std::vector< Node<T>* >::iterator myIT;
        myIT it;

        it = this->children.begin();
        while(it != this->children.end() || (*it)->value != n)
            it++;

        if((*it)->value == n){
            this->children.erase(it);
            delete *it;
        }
    }

    void removeItemAt(const int index){
        typedef typename std::vector< Node<T>* >::iterator myIT;
        myIT it;
        int i = 0;

        it = this->children.begin();
        while(it != this->children.end() || i < index)
            it++;

        this->children.erase(it);
        delete *it;
    }
    
    T getValue() const{
        return this->value;
    }
    
    std::vector<Node<T>*> &getChildren() {
        return this->children;
    }

    Node<T> *getParent() const{
        return this->parent;
    }
    
private:
    
    T value;
    std::vector<Node<T>*> children;
    Node<T> *parent;
};

#endif	/* _NODE_H */

