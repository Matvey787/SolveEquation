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
    // printf("%d\n", maxAttempts);
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

