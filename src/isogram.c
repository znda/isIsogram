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

int countChar(const char* arr, char c, int len){
    int occurence = 0;
        for(int j=0; j<len; ++j){
            char checkChar = arr[j];
            if(inspectChar(&checkChar) == -1){
                continue;
            }
            if (checkChar == c){
                ++occurence;
            }
        }
    return occurence;
}

char firstChar(const char* arr, int len){
    char checkChar;
    for(int j=0; j<len; ++j){
        checkChar = arr[j];
        if(inspectChar(&checkChar) == -1){
            continue;
        } else {
            return checkChar;
        }
    }
    return checkChar;
}

bool is_isogram(const char phrase[]){
    int len = strlen(phrase);
    int newOccurences = countChar(phrase, firstChar(phrase, len), len);
    int oldOccurences;
    for (int i=0; i<len; ++i){
        oldOccurences = newOccurences;
        char currentChar = phrase[i];
        if(inspectChar(&currentChar) == -1){
            continue;
        }
        newOccurences = countChar(phrase, currentChar, len);
        if(oldOccurences != newOccurences){
            return false;
        }
    }
    return true;
}
