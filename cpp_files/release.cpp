#include <TXLib.h>
#include <stdio.h>

#include "..\headers\release.h"

#include "..\headers\constants.h"
#include "..\headers\structures.h"
#include "..\headers\SolveEquation.h"


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
    \brief func which gets data from user (used in getInput())
    \param [in] message - special message for user
	\param [out] k - current coef (befor x^2, x or just free)
    \return nothing

    \warning !!! Example: if maxAttempts = 2 it means that user have <b>3</b> attempts !!!
*/

static void getCoeff(const char* message, double* k);

void releaseFunc() {
	int numberOfSol = 0;
	equ equation;
	getInput(&equation);

    progAnsw progAnswer = {0, 0, 0};
	numberOfSol = SolveEquation(&equation, &progAnswer);
	printSolutions(&numberOfSol, &progAnswer);
}

static void getInput(equ* equation) {
    getCoeff("Enter the coefficient at x^2: ",   &equation->a);
    getCoeff("Enter the coefficient at x: ",     &equation->b);
    getCoeff("Enter free coefficient: ", &equation->c);
}

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

static void clearInput() {
	while (getchar() != '\n');
}

static void printSolutions(const int* numberOfSol, const progAnsw* progAnswer) {
    const double*x1 = &progAnswer->x1;
    const double*x2 = &progAnswer->x2;
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

