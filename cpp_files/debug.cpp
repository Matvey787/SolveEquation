#include <TXLib.h>
#include <stdio.h>

#include "..\headers\debug.h"
#include "..\headers\constants.h"
#include "..\headers\structures.h"
#include "..\headers\SolveEquation.h"
#include "..\headers\tests.h"
#define myMIN(a, b) (a) < (b) ? (1) : (0)

static void needToSwap(double* x1, double* x2);
static int isCorrectAns(double* x1, double* x2, const int numberOfRoots, const test* testedEquation, int numberOfTest);
void swap2(double* x1, double* x2);
void mySwap(void* a, void* b, size_t elemMemory);

/**
    \brief function which tests programm
    \param nothing get
    \return nothing
    \code
        for (unsigned int i = 0; i < sizeof(equations)/sizeof(*equations); i++)
        {
            progAnsw progAnswer = {0, 0, 0};

            test testedEquation = equations[i]; // get struct test from array of test structs


            isCorrectAns(&progAnswer.x1, &progAnswer.x2, SolveEquation(&(testedEquation.equation), &progAnswer), &testedEquation, i+1);

        }
     \endcode
*/

void debugFunc(){

    for (unsigned int i = 0; i < sizeof(equations)/sizeof(*equations); i++)
    {
        progAnsw progAnswer = {0, 0, 0};

        test testedEquation = equations[i]; // get struct test from array of test structs


        isCorrectAns(&progAnswer.x1, &progAnswer.x2, SolveEquation(&(testedEquation.equation), &progAnswer), &testedEquation, i+1);

    }
}

/**
    \brief function which tests programm
    \param [in] x1 - first prog root
    \param [in] x2 - second prog root
    \param [in] numberOfRoots -  amount of roots
    \param [in] testedEquation - struct of corect answers
    \param [in] numberOfTest - number of test
    \return 1 - if test is corrected 0 - otherwise
    \code
        for (unsigned int i = 0; i < sizeof(equations)/sizeof(*equations); i++)
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

        needToSwap(x1, x2);
        needToSwap(&x1Corr, &x2Corr);

        if (fabs(fabs(*x1) - fabs(x1Corr)) < compareZero && fabs(fabs(*x2) - fabs(x2Corr)) < compareZero)
        {
            printf("\033[32mCompletely correct roots!\033[0m\n");
            return 1;
        }

        printf("\033[31mIncorrect roots!\033[0m Program sol1: %lg Program sol2: %lg Your sol1: %lg Your sol2: %lg\n",
            *x1, *x2, correctAnswers.x1Corr, correctAnswers.x2Corr);
        printf("\n");
        return 0;
     \endcode
*/

static int isCorrectAns(double* x1, double* x2, const int numberOfRoots, const test* testedEquation, int numberOfTest){
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

    needToSwap(x1, x2);
    needToSwap(&x1Corr, &x2Corr);

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

/**
    \brief function which swap two numbers
    \param [in] x1 - first number
    \param [in] x2 - second number
    \return nothing

    \warning use macro myMIN(a, b)

    \code
    if (myMIN(*x1, *x2))
    {
    //printf("ok\n");
       mySwap(x1, x2, 8);
    }
    return;
    \endcode
*/

static void needToSwap(double* x1, double* x2){
    if (myMIN(*x1, *x2))
    {
    //printf("ok\n");
       mySwap(x1, x2, 8);
    }
    return;
}

/**
    \brief function which swap two numbers
    \param [in] a - first number
    \param [in] b - second number
    \param [in] elemMemory - how many memory need for *a or *b (in bytes)
    \return nothing

    \warning
        size of a must be equal to size b

    \code
        size_t summ = 0;

        long* a_long = (long*)a;
        long* b_long = (long*)b;


        while (summ + sizeof(long) <= elemMemory){

            long buf = *a_long;
            *a_long = *b_long;
            *b_long = buf;

            a_long += 1;
            b_long += 1;
            summ += sizeof(long);

        }
        int* a_int = (int*)a_long;
        int* b_int = (int*)b_long;

        if (summ + sizeof(int) <= elemMemory){

            int buf = *a_int;
            *a_int = *b_int;
            *b_int = buf;

            a_int += 1;
            b_int += 1;
            summ += sizeof(int);

        }

        short* a_short = (short*)a_int;
        short* b_short = (short*)b_int;

        if (summ + sizeof(short) <= elemMemory){

            short buf = *a_short;
            *a_short = *b_short;
            *b_short = buf;

            a_short += 1;
            b_short += 1;
            summ += sizeof(short);

        }

        char* a_char = (char*)a_short;
        char* b_char = (char*)b_short;

        if (summ + sizeof(short) <= elemMemory){

            char buf = *a_char;
            *a_char = *b_char;
            *b_char = buf;

            a_char += 1;
            b_char += 1;
            summ += sizeof(char);

        }
    \endcode
*/

void mySwap(void* a, void* b, size_t elemMemory){
    size_t summ = 0;

    long* a_long = (long*)a;
    long* b_long = (long*)b;


    while (summ + sizeof(long) <= elemMemory){

        long buf = *a_long;
        *a_long = *b_long;
        *b_long = buf;

        a_long += 1;
        b_long += 1;
        summ += sizeof(long);

    }

    int* a_int = (int*)a_long;
    int* b_int = (int*)b_long;

    if (summ + sizeof(int) <= elemMemory){

        int buf = *a_int;
        *a_int = *b_int;
        *b_int = buf;

        a_int += 1;
        b_int += 1;
        summ += sizeof(int);

    }

    short* a_short = (short*)a_int;
    short* b_short = (short*)b_int;

    if (summ + sizeof(short) <= elemMemory){

        short buf = *a_short;
        *a_short = *b_short;
        *b_short = buf;

        a_short += 1;
        b_short += 1;
        summ += sizeof(short);

    }

    char* a_char = (char*)a_short;
    char* b_char = (char*)b_short;

    if (summ + sizeof(short) <= elemMemory){

        char buf = *a_char;
        *a_char = *b_char;
        *b_char = buf;

        a_char += 1;
        b_char += 1;
        summ += sizeof(char);

    }


}

void swap2(double* x1, double* x2) {
     double swapVar = *x1;
     *x1 = *x2;
     *x2 = swapVar;
}
