#include <TXLib.h>
#include <stdio.h>

#include "release.h"

#include "constants.h"
#include "structures.h"
#include "SolveEquation.h"

static void getInput(equ* equation);
static void printSolutions(const int* numberOfSol, progAnsw* progAnswer);
static void clearInput();
static void getCoeff(const char* message, double* k);

// Решение квадратных уравнений
void releaseFunc() {
	int numberOfSol = 0;
	equ equation;
	getInput(&equation);

    progAnsw progAnswer = {0, 0, 0};
	numberOfSol = SolveEquation(&equation, &progAnswer);
	printSolutions(&numberOfSol, &progAnswer);
}

static void getInput(equ* equation) {
    getCoeff("Введите коэффициент при x^2: ",   &equation->a);
    getCoeff("Введите коэффициент при x: ",     &equation->b);
    getCoeff("Введите свободный коэффициент: ", &equation->c);
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
		printf("Решений нет!");
		break;
	case 1:
		printf("Одно решение %lg\n", *x1);
		break;
	case 2:
		printf("Solution #1:%lg\nSolution #2:%lg\n", *x1, *x2);
		break;
	case SS_INF_ROOTS:
		printf("Бесконечное кол-во решений!");
		break;
    default:
        break;
	}
}

