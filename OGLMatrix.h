/* 
 * File:   OGLMatrix.h
 * Author: arnaudboeglin
 *
 * Created on October 1, 2009, 12:51 PM
 */

/**
 * \class OGLMatrix
 *
 * \ingroup ke
 *
 * \brief Matrix to use with OpenGL.
 *
 * \author Arnaud BOEGLIN
 *
 */

#ifndef _OGLMATRIX_H
#define	_OGLMATRIX_H

#include "Object.h"

namespace ke {
    
    class OGLMatrix : public ke::Object {

    public:

        /**
         * Constructor
         */
        OGLMatrix();

        /**
         * Constructor : creates an OGLMatrix with another one.
         *
         * \param orig : object you want to copy.
         */
        OGLMatrix(const OGLMatrix& orig);

        /**
         * Destructor
         */
        virtual ~OGLMatrix();

        /**
         * Operator () : returns access matrix specific values.
         *
         * \param i : line.
         * \param j : column.
         * \return value at line i and column j.
         */
        float operator()(int i, int j);

        /**
         * Operator * : multiplicates the matrix with another one
         * and returns the result.
         *
         * \param mat : matrix to multiplicate ( right side ).
         * \return resulting matrix.
         */
        ke::OGLMatrix operator*(ke::OGLMatrix& mat);

        /**
         * Operator * : multiplicates the matrix with another one
         * and returns the result.
         *
         * \param mat : matrix to multiplicate ( right side ).
         * \return resulting matrix.
         */
        ke::OGLMatrix* operator*(ke::OGLMatrix* mat);

        /**
         * Sets a rotation to the OGL transformation matrix.
         *
         * \param rot : rotation to set.
         */
        void setRotation(float rot);

        /**
         * Sets a translation to the OGL transformation matrix.
         *
         * \param tx : translation x to set.
         * \param ty : translation y to set.
         * \param tz : translation z to set.
         */
        void setTranslation(float tx, float ty, float tz);

        /**
         * Sets a scale to the OGL transformation matrix.
         *
         * \param sx : scale x to set.
         * \param sy : scale y to set.
         */
        void setScale(float sx, float sy);

        /**
         * Initialise the matrix to identity matrix.
         */
        void identity();

        /**
         * Sets the matrix to the current OGL context.
         */
        void use();

        /**
         * Returns datas of the matrix.
         *
         * \return basic datas which can be used directly with OGL.
         */
        float *getDatas();

    private:

        float datas[16];

        float oldScaleX;
        float oldScaleY;

    };

}

#endif	/* _OGLMATRIX_H */

