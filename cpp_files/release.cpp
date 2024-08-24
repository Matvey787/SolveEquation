#include <TXLib.h>
#include <stdio.h>

#include "..\headers\release.h"

#include "..\headers\constants.h"
#include "..\headers\structures.h"
#include "..\headers\SolveEquation.h"

static void getInput(equ* equation);
static void printSolutions(const int* numberOfSol, progAnsw* progAnswer);
static void clearInput();
static void getCoeff(const char* message, double* k);

/**
    \brief func which is designed to work with user
    \param doesn't get any parameters
    \return nothing

    \code
    int numberOfSol = 0;
	equ equation;
	getInput(&equation);

    progAnsw progAnswer = {0, 0, 0};
	numberOfSol = SolveEquation(&equation, &progAnswer);
	printSolutions(&numberOfSol, &progAnswer);
    \endcode
*/
/*! numberOfSol [type int] - get number of solutions from SolveEquation */
/*! equation [type equ <b>--watch structures.h--</b>] - new structure with coefficients */
/*! progAnswer [type progAnsw <b>--watch structures.h--</b>] - new structure with roots from programm */
void releaseFunc() {
	int numberOfSol = 0;
	equ equation;
	getInput(&equation);

    progAnsw progAnswer = {0, 0, 0};
	numberOfSol = SolveEquation(&equation, &progAnswer);
	printSolutions(&numberOfSol, &progAnswer);
}

/**
    \brief func which gets data from user
    \param [in] equation - struct to store equation data
    \return nothing

    \code
    getCoeff("Enter the coefficient at x^2: ",   &equation->a);
    getCoeff("Enter the coefficient at x: ",     &equation->b);
    getCoeff("Enter free coefficient: ", &equation->c);
    \endcode
*/

static void getInput(equ* equation) {
    getCoeff("Enter the coefficient at x^2: ",   &equation->a);
    getCoeff("Enter the coefficient at x: ",     &equation->b);
    getCoeff("Enter free coefficient: ", &equation->c);
}

/**
    \brief func which gets data from user (just continue of getInput...)
    \param [in] message - special message for user
	\param [in] k - current coef (befor x^2, x or just free)
    \return nothing

    \code
        int c=0;
    int maxAttempts = 2;
	while (printf("%s", message) && ((c = fscanf(stdin, "%lg", k)) != 1) && (c != EOF) && maxAttempts >= 1){
		clearInput();
		--maxAttempts;
		}
    if (maxAttempts == 0)
        {
        printf("Sorry, you have already used all attempts!");
        exit(1);
        }
	clearInput();
    \endcode
*/

/*! maxAttempts [type int] - max number of attempts (<b> ! counter goes to zero, so 2 attampts is 3 attempts ! </b>) */

static void getCoeff(const char* message, double* k){
    int c=0;
    int maxAttempts = 2;
	while (printf("%s", message) && ((c = fscanf(stdin, "%lg", k)) != 1) && (c != EOF) && maxAttempts >= 1){
		clearInput();
		--maxAttempts;
		}
    if (maxAttempts == 0)
        {
        printf("Sorry, you have already used all attempts!");
        exit(1);
        }
	clearInput();
}

/**
    \brief if scanf() failed to read information, then this function is executed
    \param doesn't get any parameters
    \return nothing

    \code
    while (getchar() != '\n');
    \endcode
*/

static void clearInput() {
	while (getchar() != '\n');
}

/**
    \brief print answers in special format
    \param [in] numberOfSol - amount of solutions
	\param [in] progAnswer - struct to store program answers datas
    \return nothing

    \code
    double*x1 = &progAnswer->x1;
    double*x2 = &progAnswer->x2;
	switch (*numberOfSol) {
	case 0:
		printf("There are no roots!");
		break;
	case 1:
		printf("One root %lg\n", *x1);
		break;
	case 2:
		printf("Solution #1:%lg\nSolution #2:%lg\n", *x1, *x2);
		break;
	case SS_INF_ROOTS:
		printf("Infinite number of solutions!");
		break;
    default:
        break;
	}
    \endcode
*/

static void printSolutions(const int* numberOfSol, progAnsw* progAnswer) {
    double*x1 = &progAnswer->x1;
    double*x2 = &progAnswer->x2;
	switch (*numberOfSol) {
	case 0:
		printf("There are no roots!");
		break;
	case 1:
		printf("One root %lg\n", *x1);
		break;
	case 2:
		printf("Solution #1:%lg\nSolution #2:%lg\n", *x1, *x2);
		break;
	case SS_INF_ROOTS:
		printf("Infinite number of solutions!");
		break;
    default:
        break;
	}
}

