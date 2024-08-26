#ifndef RELEASE_H_INCLUDED
#define RELEASE_H_INCLUDED

/**
    \brief func which is designed to work with user
    \param doesn't get any parameters
    \return nothing

    numberOfSol [type size_t] - amount of solutions<br>
    equation [type equ] - struct keeps equation coefficients<br>
    progAnswer [type progAnsw] - struct keeps programm answers

    \code
    int numberOfSol = 0;
	equ equation;
	getInput(&equation);

    progAnsw progAnswer = {0, 0, 0};
	numberOfSol = SolveEquation(&equation, &progAnswer);
	printSolutions(&numberOfSol, &progAnswer);
    \endcode
*/

void releaseFunc();

/**
    \brief func which gets data from user
    \param [out] equation - struct to store equation data
    \return nothing
*/

static void getInput(equ* equation);

/**
    \brief print answers in special format
    \param [in] numberOfSol - amount of solutions
	\param [in] progAnswer - struct to store program answers datas
    \return nothing
*/

static void printSolutions(const int* numberOfSol,const progAnsw* progAnswer);

/**
    \brief if scanf() failed to read information, then this function is executed
    \param doesn't get any parameters
    \return nothing

*/

static void clearInput();

/**
    \brief func which gets data from user (just continue of getInput...)
    \param [in] message - special message for user
	\param [out] k - current coef (befor x^2, x or just free)
    \return nothing

    c [type int] - get return from scanf<br>
    maxAttempts [type int] - max attempts for user to input info

    \warning !!! Example: if maxAttempts = 2 it means that user have <b>3</b> attempts !!!
*/

static void getCoeff(const char* message, double* k);

#endif // RELEASE_H_INCLUDED
