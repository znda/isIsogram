#include "isogram.h"
#include "string.h"

bool is_isogram(const char phrase[]){
    int len = strlen(phrase);
    for (int i=0; i<len; ++i){
        char currentChar = phrase[i];
        if(currentChar == ' '){
            continue;
        }
        if (currentChar >= 'A' && currentChar <= 'Z'){
            currentChar = currentChar + ('a'-'A');
        }
        int occurences = 0;
        for(int j=0; j<len; ++j){
            char checkChar = phrase[j];
            if(checkChar == ' '){
            continue;
            }
            if (checkChar >= 'A' && checkChar <= 'Z'){
            checkChar = checkChar + ('a'-'A');
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
