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
    SingleUseString(SingleUseString*);
    SingleUseString(SingleUseString*, int, SingleUseString*, int, SingleUseString*);
    SingleUseString(SingleUseString*, double, SingleUseString*, double, SingleUseString*);
    char getchar(int);
    size_t getSize();
    int getLen();
    SingleUseString& concat(const char*);
    SingleUseString& concat(SingleUseString*);
    SingleUseString& concat(double);
};
