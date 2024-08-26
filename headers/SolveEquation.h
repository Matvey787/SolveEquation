#ifndef SOLVEEQUATION_H_INCLUDED
#define SOLVEEQUATION_H_INCLUDED

/**
    \brief main call function
    \param [in] equation - struct in which the coefficients of equation are stored
    \param [out] progAnswer - struct in which answers are stored
    \return return amount of solutions
*/

int SolveEquation(const equ* equation, progAnsw* progAnswer);

#endif // SOLVEEQUATION_H_INCLUDED
