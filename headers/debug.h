#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

/**
    \brief function which tests programm

    \param nothing get

    \return nothing

    equations [type test] - <b>array of different test structures</b><br>
    progAnswer [type progAnsw] - <b>struct to save prog answers</b><br>
    testedEquation [type test] - <b>current struct of test</b>
*/

void debugFunc();

/**
    \brief function which swap two numbers
    \param [out] x1 - first number
    \param [out] x2 - second number
    \return nothing

    \warning use macro myMIN(a, b)
*/

static void needToSwap(double* x1, double* x2);

/**
    \brief <b>Function which tests programm.</b>

    \details Function firstly check if programm number of roots is equal to correct number of
    roots. Then it checks if roots correct of both sides.

    \param [out] x1 - first prog root
    \param [out] x2 - second prog root
    \param [in] numberOfRoots -  amount of roots
    \param [in] testedEquation - struct of corect answers
    \param [out] numberOfTest - number of test

    \return 1 - if test is corrected 0 - otherwise

    x1Corr [type double] - <b>first correct answer</b><br>
    x2Corr [type double] - <b>second correct answer</b>

*/

static int isCorrectAns(double* x1, double* x2, const int numberOfRoots, const test* testedEquation, int numberOfTest);

/**
    \brief function which swap two numbers
    The function operates on variables using pointer arithmetic.
    \param [out] a - first number
    \param [out] b - second number
    \param [in] elemMemory - how many memory need for *a or *b (in bytes)
    \return nothing

    \warning
        size of a must be equal to size b

    summ [type size_t] - sum of bytes changed
*/

void mySwap(void* a, void* b, const size_t elemMemory);

#endif // DEBUG_H_INCLUDED
