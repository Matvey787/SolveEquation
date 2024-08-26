#include <TXLib.h>
#include <stdio.h>

#include "..\headers\structures.h"
#include "..\headers\constants.h"
#include "..\headers\SolveEquation.h"
#include "..\headers\funcTypesEquation.h"

/**
    \brief main call function
    \param [in] equation - struct in which the coefficients of equation are stored
    \param [in] progAnswer - struct in which answers are stored
    \return return amount of solutions

	D [type double] - discriminant of equation

    \code
    assert(equation != nullptr && "equation is point to null");
	assert(isfinite(equation->a) && "Incorrect a");
	assert(isfinite(equation->b) && "Incorrect b");
	assert(isfinite(equation->c) && "Incorrect c");

	double D = equation->b * equation->b - 4 * equation->a * equation->c;

    //printf("%lg\n", D);
	if (fabs(equation->a) > compareZero) // is zero func
        return notLinearEquation(&D, equation, progAnswer);
	else
	{
		return isLinearEquation(equation, progAnswer);
	}
     \endcode
*/

int SolveEquation(equ* equation, progAnsw* progAnswer) {
	assert(equation != nullptr && "equation is point to null");
	assert(isfinite(equation->a) && "Incorrect a");
	assert(isfinite(equation->b) && "Incorrect b");
	assert(isfinite(equation->c) && "Incorrect c");

	double D = equation->b * equation->b - 4 * equation->a * equation->c;

    //printf("%lg\n", D);
	if (fabs(equation->a) > compareZero) // is zero func
        return notLinearEquation(&D, equation, progAnswer);
	else
	{
		return isLinearEquation(equation, progAnswer);
	}
}
