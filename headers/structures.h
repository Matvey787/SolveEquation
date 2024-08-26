#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/// @brief structure which keeps coefficients of quad equation
typedef struct {

    /// @brief coeff before x^2
    double a;

    /// @brief coeff before x
    double b;

    /// @brief free coeff
    double c;
} equ;

/// @brief structure which keeps programm answers
typedef struct {
    /// @brief first prog answer
    double x1;

    /// @brief second prog answer
    double x2;

    /// @brief programm number of roots
    int numberOfRoots;

} progAnsw;

/// @brief structure which keeps correct answers for tests
typedef struct {
    /// @brief first correct answer
    double x1Corr;

    /// @brief second correct answer
    double x2Corr;

    /// @brief number of correct answers
    int numberOfRootsCorr;

} corrAnsw;

/// @brief structure which keeps different tests
typedef struct {

    /// @brief struct of coefficients in equation
    equ equation;

    /// @brief struct of correct answers
    corrAnsw corrAns;

} test;
#endif // CONSTANTS_H_INCLUDED
