#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
/// @brief array which keep in itself all tests
const test EQUATIONS[] = {
//{{    a,     b,      c  }, {  x1Corr,   x2Corr,   numberOfRoots     }}
  {{    2,     1,     -3  }, {     1,      -1.5,          2           }},
  {{    1,     2,      1  }, {    -1,       -1,           1           }},
  {{    1,    -2,      1  }, {     1,        1,           1           }},
  {{    0,     0,      0  }, {     0,        0,      SS_INF_ROOTS     }},
  {{    1,     2,      3  }, {     0,        0,           0           }},
  {{    1,   -5.87,   -9  }, {   -1.26,     7.13,         2           }},
};

const size_t EQUATIONS_SIZE = sizeof(EQUATIONS) / sizeof(*EQUATIONS);

#endif // TESTS_H_INCLUDED
