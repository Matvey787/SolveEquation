#include "..\headers\release.h"
#include "..\headers\debug.h"

#include <stdio.h>
#include <string.h>
// g++ main.cpp funcTypesEquation.cpp debug.cpp release.cpp SolveEquation.cpp -o out
/**
    \brief main call function
    \param [in] argc amount of parameters
    \param [in] argv array of arguments
    \return 0 - if compilation comlited successfuly 1 - otherwise
    \code
     if (strcmp(argv[argc-1], "debug") == 0)
        debugFunc();
    else if (strcmp(argv[argc-1], "release") == 0)
        releaseFunc();
    return 0;
     \endcode
*/
int main(int argc, char *argv[]){

    if (strcmp(argv[argc-1], "debug") == 0)
        debugFunc();
    else if (strcmp(argv[argc-1], "release") == 0)
        releaseFunc();
    return 0;
}
