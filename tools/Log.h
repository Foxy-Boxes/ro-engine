#pragma once
#include <iostream>
#include "SingleUseString.h"
class Log
{
private:
    /* data */
public:
    Log(/* args */);
    bool print(const char *);
    bool print(SingleUseString *);
};
