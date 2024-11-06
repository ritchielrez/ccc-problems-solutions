#include <stdio.h>

#define N 500000

int main() {
  char out1[N] = "";
  char out2[N] = "";
  gets_s(out1, N);
  gets_s(out2, N);
  puts(out1);
  puts(out2);
}
