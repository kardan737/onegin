#ifndef BUFFERPASS_H_
#define BUFFERPASS_H_

#include "strct.h"

char* Buffering(int sizeFile, FILE* fp);
size_t SizeFile(FILE* fp);
int CountLine(char* buffer, size_t sizeFile);
lineStartLen* AddrLine(char* buffer, int sizeFile, int countLine);

#endif
