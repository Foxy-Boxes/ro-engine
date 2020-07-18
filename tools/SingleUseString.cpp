#include "SingleUseString.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>


    SingleUseString::SingleUseString(const char* str){
        for(length = 0; ;length++){
            if(!str[length]){
                break;
            }
        }
        length++;
        pointertostr = (char*)malloc(length*sizeof(char));
        for(int i=0; i < length; i++){
            pointertostr[i] = str[i];
        }
    }
    SingleUseString::SingleUseString(SingleUseString * str0, int x,SingleUseString * str1, int y, SingleUseString * str2){
        int i,j;
        length = str0->getLen() + str1->getLen()  + str2->getLen() + 6;
        int xlength,ylength;
        for(ylength = 0; ; ylength++){
            if(!std::to_string(y)[ylength]){break;}
        }
        for(xlength = 0; ; xlength++){
            if(!std::to_string(x)[xlength]){break;}
        }
        pointertostr = (char*)malloc(length*sizeof(char));
        for(i = 0; i < str0->getLen() ; i++){
            pointertostr[i] = str0->getchar(i);
            if(!pointertostr[i]){
                break;
            }
        }
        for(j = 0; j < 4 - xlength; j++){
            pointertostr[i+j] = '0';
        }
        for(; j < 4; j++){
            pointertostr[i+j] = std::to_string(x)[j-4+xlength];
            if(!pointertostr[i+j]){
                break;
            }
        }
        i+=j;
        for(j = 0; j < str1->getLen() ; j++){
            pointertostr[i+j] = str1->getchar(j);
            
            if(!pointertostr[i+j]){
                break;
            }
        }
        i+=j;
        for(j = 0; j < 4 - ylength; j++){
            pointertostr[i+j] = '0';
        }
        for(; j < 4; j++){
            pointertostr[i+j] = std::to_string(y)[j-4+ylength];
            if(!pointertostr[i+j]){
                break;
            }
        }
        i+=j;
        for(j = 0; j < str2->getLen() ; j++){
            pointertostr[i+j] = str2->getchar(j);
            if(!pointertostr[i+j]){
                break;
            }
        }
    }
    size_t SingleUseString::getSize(){
        return length*sizeof(char);
    }
    char SingleUseString::getchar(int pos){
        char retchar = pointertostr[pos];
        if(pos == length - 1){
                free(pointertostr);
        }
        return retchar;
    }
    int SingleUseString::getLen(){
        return length;
    }