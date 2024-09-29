#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "bufferpass.h"


char* Buffering(int sizeFile, FILE* fp)
    {
    assert(fp != nullptr);

    char* buffer = (char*)calloc(sizeFile + 1, sizeof(char));
    if (buffer == NULL)
        {
        printf("MEMORY_ALLOCATION_ERROR");
        return NULL;
        }

    size_t result = fread(buffer, sizeof(char), sizeFile, fp);

    if (sizeFile != result)
        {
        printf("READING_FILE_ERROR");
        return NULL;
        }

    return buffer;
    }


size_t SizeFile(FILE* fp)
    {
    assert(fp != nullptr);

    fseek(fp, 0, SEEK_END);
    size_t sizeFile = ftell(fp);
    rewind(fp);

    return sizeFile;
    }


int CountLine(char* buffer, size_t sizeFile)
    {
    assert(buffer != nullptr);

    int countLine = 0;
    bool notEmptyStr = false;
    for (size_t i = 0; i < sizeFile; i++)
        {
        if (isalpha(buffer[i]) != false)
            notEmptyStr = true;

        if (buffer[i] == '\r')
            buffer[i] = '\0';

        if (buffer[i] == '\n')
            {
            if (notEmptyStr == true)
                {
                ++countLine;
                notEmptyStr = false;
                }
            buffer[i] = '\0';
            }
        }
    buffer[sizeFile] = '\0';

    return countLine;
    }


lineStartLen* AddrLine(char* buffer, int sizeFile, int countLine)
    {
    assert(buffer != nullptr);

    lineStartLen* featureLine = (lineStartLen*)calloc(countLine, sizeof(lineStartLen));

    if (featureLine == nullptr)
        {
        printf("ADDRESSES_DECLARATION_ERROR\n");
        return NULL;
        }

    char* start_line = buffer;
    int number_line = 0;

    for (int i = 0; i < sizeFile - 1; i++)
        {
        int len = 0;

        while (buffer[i] != '\0')
            {
            len++;
            i++;
            }

        if (len > 0)
            {
            featureLine[number_line] = {start_line, len};
            number_line++;
            len = 0;
            }

        if (buffer[i] == '\0' && buffer[i+1] != '\0')
            start_line = buffer + i + 1;
        }

    return featureLine;
    }
