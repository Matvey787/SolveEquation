#ifndef FUNCTYPESEQUATION_H_INCLUDED
#define FUNCTYPESEQUATION_H_INCLUDED

#include "structures.h"
/**
    \brief function which swap two numbers
    \param [in] D - discriminant
    \param [in] equation - struct in which the coefficients of equation are stored
    \param [out] progAnswer - struct in which answers are stored
    \return amount of roots
*/

int notLinearEquation(const double* D, const equ* equation, progAnsw* progAnswer);

/**
    \brief same as not linear func but work with if coefficient before x^2 = 0
    \param [in] equation - struct in which the coefficients of equation are stored
    \param [out] progAnswer - struct in which answers are stored
    \return amount of roots
*/

int isLinearEquation(const equ* equation, progAnsw* progAnswer);

#endif // FUNCTYPESEQUATION_H_INCLUDED
