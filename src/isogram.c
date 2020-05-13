#include "isogram.h"
#include "string.h"

int inspectChar(char* c){
        //to lower case
        if (*c >= 'A' && *c <= 'Z'){
            *c = *c + ('a'-'A');
        }
        //inspect if char is allowed
        if (!((*c >= 'a' && *c <= 'z') || (*c >= '0' && *c <= '9'))){
            return -1;
        }
        return *c;
}

bool is_isogram(const char phrase[]){
    int len = strlen(phrase);
    for (int i=0; i<len; ++i){
        char currentChar = phrase[i];
        if(inspectChar(&currentChar) == -1){
            continue;
        }
        int occurences = 0;
        for(int j=0; j<len; ++j){
            char checkChar = phrase[j];
            if(inspectChar(&checkChar) == -1){
                continue;
            }
            if (checkChar == currentChar){
                ++occurences;
            }
        }
        if(occurences > 1){
            return false;
        }
    }
    return true;
}
