#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "constants.h"
#define SS_INF_ROOTS -1  //research
#define myMIN(a, b) (a) < (b) ? (1) : (0)

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

static void getInput(equ* equation);
static void printSolutions(const int* numberOfSol, progAnsw* progAnswer);
static int SolveEquation(equ*, progAnsw* progAnswer);
static void clearInput();

void debugFunc();
void releaseFunc();

int main(){
    //releaseFunc();
    debugFunc();
    return 0;
}

// Решение квадратных уравнений
void releaseFunc(void) {
	int numberOfSol = 0;
	equ equation;
	getInput(&equation);

    progAnsw progAnswer = {0, 0, 0};
	numberOfSol = SolveEquation(&equation, &progAnswer);
	printSolutions(&numberOfSol, &progAnswer);
}

int isCorrectAns(double* x1, double* x2, const int numberOfRoots, const test* testedEquation, int numberOfTest);

void debugFunc(){
    test equations[] = {
//    {{a, b, c}, x1Corr, x2Corr, numberOfRoots}
     {{2, 1, -3}, {1, -1.5, 2}        },
     {{1, 2, 1},  {-1, -1, 1}         },
     {{1, -2, 1}, {1, 1, 1}           },
     {{0, 0, 0},  {0, 0, SS_INF_ROOTS}},
     {{1, 2, 3},  {0, 0, 0}           }

    };

    for (unsigned int i = 0; i < sizeof(equations)/sizeof(*equations); i++)
    {
        progAnsw progAnswer = {0, 0, 0};

        test testedEquation = equations[i]; // get struct test from array of test structs

        isCorrectAns(&progAnswer.x1, &progAnswer.x2, SolveEquation(&(testedEquation.equation), &progAnswer), &testedEquation, i+1);

    }
}

void mySwap(double* x1, double* x2);

int isCorrectAns(double* x1, double* x2, const int numberOfRoots, const test* testedEquation, int numberOfTest){
    printf("Test \033[43m\033[30m#%d\033[0m ", numberOfTest);

    corrAnsw correctAnswers = testedEquation->corrAns;
    double x1Corr = correctAnswers.x1Corr;
    double x2Corr = correctAnswers.x2Corr;

    if (numberOfRoots != correctAnswers.numberOfRootsCorr)
    {
        printf("\033[31mIncorrect number of roots!\033[0m\n");
        return 0;
    } else if (numberOfRoots == SS_INF_ROOTS){
        printf("\033[32mCompletely correct roots!\033[0m\n");
        return 1;
    }

    mySwap(x1, x2);
    mySwap(&x1Corr, &x2Corr);

    if (fabs(fabs(*x1) - fabs(x1Corr)) < compareZero && fabs(fabs(*x2) - fabs(x2Corr)) < compareZero)
    {
        printf("\033[32mCompletely correct roots!\033[0m\n");
        return 1;
    }

    printf("\033[31mIncorrect roots!\033[0m Program sol1: %lg Program sol2: %lg Your sol1: %lg Your sol2: %lg\n",
           *x1, *x2, correctAnswers.x1Corr, correctAnswers.x2Corr);
    printf("\n");
    return 0;
}

void mySwap(double* x1, double* x2){
    if (myMIN(*x1, *x2))
    {
        double swapVar = *x1;
       *x1 = *x2;
       *x2 = swapVar;
    }
    return;
}


void getCoeff(const char* message, double* k);

void getInput(equ* equation) {
    getCoeff("Введите коэффициент при x^2: ",   &equation->a);
    getCoeff("Введите коэффициент при x: ",     &equation->b);
    getCoeff("Введите свободный коэффициент: ", &equation->c);
}

void getCoeff(const char* message, double* k){
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

void clearInput() {
	while (getchar() != '\n');
}

void printSolutions(const int* numberOfSol, progAnsw* progAnswer) {
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

int notLinearEquation(const double* D, equ* equation, progAnsw* progAnswer);
int isLinearEquation(equ* equation, progAnsw* progAnswer);

int SolveEquation(equ* equation, progAnsw* progAnswer) {
	assert(equation != nullptr && "equation is point to null");
	assert(isfinite(equation->a) && "Incorrect a");
	assert(isfinite(equation->b) && "Incorrect b");
	assert(isfinite(equation->c) && "Incorrect c");

	double D = equation->b * equation->b - 4 * equation->a * equation->c; // Дискриминант
    //printf("%lg\n", D);
	if (fabs(equation->a) > compareZero) // is zero func
        return notLinearEquation(&D, equation, progAnswer);
	else
	{
		return isLinearEquation(equation, progAnswer);
	}
}

int notLinearEquation(const double* D, equ* equation, progAnsw* progAnswer){
    double* a = &(equation->a);
    double* b = &(equation->b);
    double* x1 = &(progAnswer->x1);
    double* x2 = &(progAnswer->x2);

    if (*D > compareZero)
    {
        *x1 = (-*b + sqrt(*D)) / (2 * *a);
        *x2 = (-*b - sqrt(*D)) / (2 * *a);
        return 2;

    }
    else if (fabs(*D) < compareZero)
    {
        *x1 = (-*b) / (2 * *a);
        *x2 = *x1;
        return 1;
    }
    else
    {
        return 0;

    }
}

int isLinearEquation(equ* equation, progAnsw* progAnswer){
    double *b = &(equation->b);
    double *c = &(equation->c);
    double *x1 = &(progAnswer->x1);
    double *x2 = &(progAnswer -> x2);
    if (fabs(*b) > compareZero)
    {
        *x1 = -*c / *b;
        *x2 = *x1;
        return 1;
    } else {
        return SS_INF_ROOTS;
    }
}
