#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
typedef struct {
    double a;
    double b;
    double c;
} equ;

typedef struct {
    double x1;
    double x2;
    int numberOfRoots;
} progAnsw;

typedef struct {
    double x1Corr;
    double x2Corr;
    int numberOfRootsCorr;
} corrAnsw;

typedef struct {
    equ equation;
    corrAnsw corrAns;
} test;
#endif // CONSTANTS_H_INCLUDED
