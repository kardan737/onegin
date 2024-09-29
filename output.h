#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "strct.h"

void Record(FILE* sorted, int countLine, lineStartLen* featureLine);
lineStartLen* RememberAddr(lineStartLen* featureLine, int countLine);

#endif
