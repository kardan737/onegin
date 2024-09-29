#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "output.h"


lineStartLen* RememberAddr(lineStartLen* featureLine, int countLine)
    {
    assert(featureLine != nullptr);

    lineStartLen* originalAddr = (lineStartLen*)calloc(countLine, sizeof(lineStartLen));

    if (originalAddr == nullptr)
        {
        printf("ADDRESSES_DECLARATION_ERROR\n");
        return NULL;
        }

    for (int i = 0; i < countLine; i++)
        {
        originalAddr[i].startStr = featureLine[i].startStr;
        }

    return originalAddr;
    }


void Record(FILE* sorted, int countLine, lineStartLen* featureLine)
    {
    assert(sorted != nullptr);

    fprintf(sorted, "//////////////////////////////////////////\n");

    for (int i = 0; i < countLine; i++)
        fprintf(sorted, "%s\n", featureLine[i].startStr);

    fprintf(sorted, "//////////////////////////////////////////\n");
    }
