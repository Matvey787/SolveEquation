#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
/// @brief structure which keeps coefficients of quad equation
typedef struct {
    double a;
    double b;
    double c;
} equ;
/// @brief structure which keeps programm answers
typedef struct {
    double x1;
    double x2;
    int numberOfRoots;
} progAnsw;
/// @brief structure which keeps correct answers for tests
typedef struct {
    double x1Corr;
    double x2Corr;
    int numberOfRootsCorr;
} corrAnsw;
/// @brief structure which keeps different tests
typedef struct {
    equ equation;
    corrAnsw corrAns;
} test;
#endif // CONSTANTS_H_INCLUDED
