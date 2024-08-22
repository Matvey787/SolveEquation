#include "release.h"
#include "debug.h"

#include <stdio.h>
#include <string.h>
// g++ main.cpp funcTypesEquation.cpp debug.cpp release.cpp SolveEquation.cpp -o out

int main(int argc, char *argv[]){

    if (strcmp(argv[argc-1], "debug") == 0)
        debugFunc();
    else
        releaseFunc();

    return 0;
}
