#include "isogram.h"
#include <string.h>
#include <stdio.h>

char toLowerCase(char c){
  if (c >= 'A' && c <= 'Z'){
    return c + ('a' - 'A');
  }
  return c;
}

bool isChar(char c){
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z');
}


bool is_isogram(const char phrase[]){
  bool occurence[256];

  for (size_t i = 0; i < 256; i++) {
    occurence[i] = false;
  }

  for (size_t i = 0; i < strlen(phrase); i++) {
    int charIndex =(int) toLowerCase(phrase[i]);
    if(isChar(phrase[i]) && occurence[charIndex] == true){
      return false;
    }
    occurence[charIndex] = true;
  }

  return true;
}
