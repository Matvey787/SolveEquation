#include <TXLib.h>
#include <stdio.h>

#include "structures.h"
#include "constants.h"
#include "SolveEquation.h"
#include "funcTypesEquation.h"

int SolveEquation(equ* equation, progAnsw* progAnswer) {
	assert(equation != nullptr && "equation is point to null");
	assert(isfinite(equation->a) && "Incorrect a");
	assert(isfinite(equation->b) && "Incorrect b");
	assert(isfinite(equation->c) && "Incorrect c");

	double D = equation->b * equation->b - 4 * equation->a * equation->c; // Дискриминант
    //printf("%lg\n", D);
	if (fabs(equation->a) > compareZero) // is zero func
        return notLinearEquation(&D, equation, progAnswer);
	else
	{
		return isLinearEquation(equation, progAnswer);
	}
}
