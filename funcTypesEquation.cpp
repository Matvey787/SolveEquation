#include "funcTypesEquation.h"

#include <math.h>

#include "structures.h"
#include "constants.h"

int notLinearEquation(const double* D, const equ* equation, progAnsw* progAnswer){
    const double a = equation->a;
    const double b = equation->b;
    double* x1 = &(progAnswer->x1);
    double* x2 = &(progAnswer->x2);

    if (*D > compareZero)
    {
        *x1 = (-b + sqrt(*D)) / (2 * a);
        *x2 = (-b - sqrt(*D)) / (2 * a);
        return 2;

    }
    else if (fabs(*D) < compareZero)
    {
        *x1 = (-b) / (2 * a);
        *x2 = *x1;
        return 1;
    }
    else
    {
        return 0;

    }
}

int isLinearEquation(const equ* equation, progAnsw* progAnswer){
    double b = equation->b;
    double c = equation->c;
    double *x1 = &(progAnswer->x1);
    double *x2 = &(progAnswer -> x2);
    if (fabs(b) > compareZero)
    {
        *x1 = -c / b;
        *x2 = *x1;
        return 1;
    } else {
        return SS_INF_ROOTS;
    }
}
