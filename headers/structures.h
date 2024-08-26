#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/// @brief keeps coefficients of quad equation
struct equ {

    /// @brief coeff before x^2
    double a;

    /// @brief coeff before x
    double b;

    /// @brief free coeff
    double c;
};

/// @brief keeps programm answers
struct progAnsw {
    /// @brief first prog answer
    double x1;

    /// @brief second prog answer
    double x2;

    /// @brief programm number of roots
    int numberOfRoots;

};

/// @brief structure which keeps correct answers for tests
struct corrAnsw {
    /// @brief first correct answer
    double x1Corr;

    /// @brief second correct answer
    double x2Corr;

    /// @brief number of correct answers
    int numberOfRootsCorr;

};

/// @brief structure which keeps different tests
struct test {

    /// @brief struct of coefficients in equation
    equ equation;

    /// @brief struct of correct answers
    corrAnsw corrAns;

};
#endif // CONSTANTS_H_INCLUDED
