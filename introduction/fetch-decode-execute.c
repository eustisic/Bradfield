#include <stdio.h>
#include <time.h>
#define BILLION 100000000

int main() 
{
  clock_t start = clock();

  for (int i = 0; i < BILLION; i++) {
    int a = i * 1;
  }
  float secs = (float)(clock() - start) / CLOCKS_PER_SEC;
  float ops = BILLION / secs;
  printf("Clock speed approx %.3f GHz\n", ops / BILLION);
}