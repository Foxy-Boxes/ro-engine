#include <iostream>
#include "Log.h"


    Log::Log(/* args */){}
    bool Log::print(const char* str){
        std::cout << str << std::endl;
        return 1;
    }
    bool Log::print(SingleUseString* str){
        int length = (str->getSize())/sizeof(char) ;
        for(int i = 0; i < length; i++){
            std::cout << str->getchar(i);
        }
        std::cout << '\n';
        delete str;
        return 1;
    }