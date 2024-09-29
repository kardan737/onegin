#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "bufferpass.h"
#include "mysort.h"
#include "output.h"


int main()
    {
    FILE* fp = fopen("onegin.txt", "rb");
    FILE* sorted = fopen("onegin_sorted.txt", "w+");

    if (!fp)
        {
        printf("OPENING_ERROR");
        return -1;
        }

    size_t sizeFile = SizeFile(fp);

    char* buffer = Buffering(sizeFile, fp);
    if (!buffer) return -1;

    fclose(fp);

    int countLine = CountLine(buffer, sizeFile);

    lineStartLen* featureLine = AddrLine(buffer, sizeFile, countLine);
    if (!featureLine) return -1;

    lineStartLen* originalAddr = RememberAddr(featureLine, countLine);
    if (!originalAddr) return -1;

    BubbleSort(featureLine, countLine, &Compare);
    Record(sorted, countLine, featureLine);

    BubbleSort(featureLine, countLine, &RevCompare);
    Record(sorted, countLine, featureLine);

    Record(sorted, countLine, originalAddr);

    free(buffer);
    free(featureLine);
    free(originalAddr);
    }
