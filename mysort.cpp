#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "mysort.h"

int BubbleSort(lineStartLen* featureLine, int countLine, int (*comparator)(lineStartLen line_1, lineStartLen line_2))
    {
    assert(featureLine != nullptr);
    assert(comparator != nullptr);

    for (int i = 0; i < countLine - 1; i++)
        {
        for (int j = 0; j < countLine - i - 1; j++)
            {
            if (comparator(featureLine[j], featureLine[j+1]) == SWAP)
                {
                lineStartLen temp = featureLine[j];
                featureLine[j] = featureLine[j+1];
                featureLine[j+1] = temp;
                }
            }
        }

    return 0;
    }


int Compare(lineStartLen line_1, lineStartLen line_2)
    {

    int index_1 = 0;
    char* addr_1 = line_1.startStr;

    int index_2 = 0;
    char* addr_2 = line_2.startStr;

    assert(addr_1 != nullptr);
    assert(addr_2 != nullptr);

    while (addr_1[index_1] != '\0' && addr_2[index_2] != '\0')
        {
        while (isalpha(addr_1[index_1]) == 0)
            index_1++;

        while (isalpha(addr_2[index_2]) == 0)
            index_2++;

        if (tolower(addr_1[index_1]) - tolower(addr_2[index_2]) > 0)
            return SWAP;

        if (tolower(addr_1[index_1]) - tolower(addr_2[index_2]) < 0)
            return GOOD_ORDER;
        index_1++;
        index_2++;
        }

    if (addr_1[index_1] == '\0' && addr_2[index_2] != '\0')
        return GOOD_ORDER;

    if (addr_1[index_1] != '\0' && addr_2[index_2] == '\0')
        return SWAP;

    if (addr_1[index_1] == '\0' && addr_2[index_2] == '\0')
        return EQUAL;

    return 0;
    }


int RevCompare(lineStartLen line_1, lineStartLen line_2)
    {

    int index_1 = line_1.lenStr - 1;
    char* addr_1 = line_1.startStr;

    int index_2 = line_2.lenStr - 1;
    char* addr_2 = line_2.startStr;

    assert(addr_1 != nullptr);
    assert(addr_2 != nullptr);

    while (index_1 != -1 && index_2 != -1)
        {
        while ((isalpha(addr_1[index_1]) == 0) && (index_1 >= 0))
            index_1--;

        while ((isalpha(addr_2[index_2]) == 0) && (index_2 >= 0))
            index_2--;

        if ((tolower(addr_1[index_1]) - tolower(addr_2[index_2]) > 0) ||
            ((index_2 == -1) && (index_1 > -1)))

            return SWAP;

        if ((tolower(addr_1[index_1]) - tolower(addr_2[index_2]) < 0) ||
            ((index_1 == -1) && (index_2 > -1)))

            return GOOD_ORDER;

        index_1--;
        index_2--;
        }

    return 0;
    }
