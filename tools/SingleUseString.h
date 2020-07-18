#pragma once
#include <stdlib.h>

class SingleUseString
{
private:
    /* data */
    char* pointertostr;
    int length;
public:
    SingleUseString(const char*);
    SingleUseString(SingleUseString*, int, SingleUseString*, int, SingleUseString*);
    char getchar(int);
    size_t getSize();
    int getLen();
};
