#ifndef MYSORT_H_
#define MYSORT_H_

#include "strct.h"

enum CompareAction
    {
    SWAP       = 0,
    GOOD_ORDER = 1,
    EQUAL      = 2,
    };

int BubbleSort(lineStartLen* featureLine, int countLine, int (*comparator)(lineStartLen line_1, lineStartLen line_2));
int Compare(lineStartLen line_1, lineStartLen line_2);
int RevCompare(lineStartLen line_1, lineStartLen line_2);

#endif
