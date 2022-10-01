#include <stdio.h>
#include <stdlib.h>

int square(int n) { return n * n; }

int main (int argc, char** argv) {
  if (argc != 2) {
    printf("%s is not 2\n", argv);
  }

  int n = atoi(argv[1]);

  printf("%d * %d = %d", n, n, square(n));
}