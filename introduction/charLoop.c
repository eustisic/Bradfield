#include <stdio.h>

int main() 
{
  char c = 'a';

  for (int i = c; i < 'z'; i++) {
    printf("%c\n", i);
  } 

  return 0;
}