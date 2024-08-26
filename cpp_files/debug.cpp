#include <TXLib.h>
#include <stdio.h>

#include "..\headers\debug.h"
#include "..\headers\colors.h"
#include "..\headers\constants.h"
#include "..\headers\structures.h"
#include "..\headers\SolveEquation.h"
#include "..\headers\tests.h"
#define myMIN(a, b) (a) < (b) ? (1) : (0)

/**
    \brief function which swaps two numbers
    \param [out] x1 - first number
    \param [out] x2 - second number
    \return nothing

    \warning use macro myMIN(a, b)
*/

static void needToSwap(double* x1, double* x2);

/**
    \brief function which swap two numbers (vectorized)
    The function operates on variables using pointer arithmetic.
    \param [out] a - first number
    \param [out] b - second number
    \param [in] elemMemory - how many memory need for *a or *b (in bytes)
    \return nothing

    \warning size of a must be equal to size b
*/

static void mySwap(void* a, void* b, size_t elemMemory);

/**
    \brief <b>Function which tests programm.</b>

    \details Function firstly check if programm number of roots is equal to correct number of
    roots. Then it checks if roots correct of both sides.

    \param [in] progAnswer - struct in which data of prog answers stored
    \param [in] testedEquation - struct of corect answers
    \param [in] numberOfTest - number of test

    \return 1 - if test is corrected 0 - otherwise

*/

static int isCorrectAns(progAnsw* progAnswer, test* testedEquation, int numberOfTest);

void debugFunc(){
    for (unsigned int i = 0; i < EQUATIONS_SIZE; i++)
    {
        progAnsw progAnswer = {0, 0, 0};

        test testedEquation = EQUATIONS[i]; // get struct test from array of test structs

        progAnswer.numberOfRoots = SolveEquation(&(testedEquation.equation), &progAnswer);

        isCorrectAns(&progAnswer, &testedEquation, i+1);

    }
}



static int isCorrectAns(progAnsw* progAnswer, test* testedEquation, int numberOfTest){
    printf("Test %s#%d\033[0m ", RED, numberOfTest);

    double* x1 = &(progAnswer->x1);
    double* x2 = &(progAnswer->x2);
    const int numberOfRoots = progAnswer->numberOfRoots;

    corrAnsw correctAnswers = testedEquation->corrAns;
    double x1Corr = correctAnswers.x1Corr;
    double x2Corr = correctAnswers.x2Corr;

    if (numberOfRoots != correctAnswers.numberOfRootsCorr)
    {
        printf("%sIncorrect number of roots!%s\n", RED, WHITE);
        return 0;
    } else if (numberOfRoots == SS_INF_ROOTS){
        printf("%sCompletely correct roots!%s\n", GREEN, WHITE);
        return 1;
    }

    needToSwap(x1, x2);
    needToSwap(&x1Corr, &x2Corr);

    if (fabs(fabs(*x1) - fabs(x1Corr)) < compareZero && fabs(fabs(*x2) - fabs(x2Corr)) < compareZero)
    {
        printf("%sCompletely correct roots!%s\n", GREEN, WHITE);
        return 1;
    }

    printf("%sIncorrect roots!%s Program sol1: %lg Program sol2: %lg Your sol1: %lg Your sol2: %lg\n",
           RED, WHITE, *x1, *x2, correctAnswers.x1Corr, correctAnswers.x2Corr);
    printf("\n");
    return 0;
}

static void needToSwap(double* x1, double* x2){
    if (myMIN(*x1, *x2))
    {
    //printf("ok\n");
       mySwap(x1, x2, 8);
    }
    return;
}

static void mySwap(void* a, void* b, size_t elemMemory){
    size_t summ = 0;

    uint64_t* a_long = (uint64_t*)a;
    uint64_t* b_long = (uint64_t*)b;


    while (summ + sizeof(uint64_t) <= elemMemory){

        uint64_t buf = *a_long;
        *a_long = *b_long;
        *b_long = buf;

        a_long += 1;
        b_long += 1;
        summ += sizeof(uint64_t);

    }

    uint32_t* a_int = (uint32_t*)a_long;
    uint32_t* b_int = (uint32_t*)b_long;

    if (summ + sizeof(uint32_t) <= elemMemory){

        uint32_t buf = *a_int;
        *a_int = *b_int;
        *b_int = buf;

        a_int += 1;
        b_int += 1;
        summ += sizeof(uint32_t);

    }

    uint16_t* a_short = (uint16_t*)a_int;
    uint16_t* b_short = (uint16_t*)b_int;

    if (summ + sizeof(uint16_t) <= elemMemory){

        uint16_t buf = *a_short;
        *a_short = *b_short;
        *b_short = buf;

        a_short += 1;
        b_short += 1;
        summ += sizeof(uint16_t);

    }

    uint8_t* a_char = (uint8_t*)a_short;
    uint8_t* b_char = (uint8_t*)b_short;

    if (summ + sizeof(uint8_t) <= elemMemory){

        uint8_t buf = *a_char;
        *a_char = *b_char;
        *b_char = buf;

        a_char += 1;
        b_char += 1;
        summ += sizeof(uint8_t);

    }
}
