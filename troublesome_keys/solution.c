#define DEBUG 0
#include <stdio.h>
#include <string.h>

#define N 500000

int main() {
  char out1[N] = "";
  char out2[N] = "";

  fgets(out1, N, stdin);
  fgets(out2, N, stdin);

  int out1_len = strlen(out1) - 1;
  int out2_len = strlen(out2) - 1;

  char quietKey = '-';
  char sillyKey = '-';
  char correspondingKey = '-';

  char assumedQuietKey = 0;
  int assumedQuietKeyCount = 0;

  int i = 0, j = 0;
  while(i < out1_len && j < out2_len) {
    if (DEBUG) {
      printf("i: %d, j: %d\n", i, j);
    }
    if (out1[i] == sillyKey) {
      i++;
      j++;
    } else if (out1[i] == quietKey) {
      i++;
    } else if (out1[i] != out2[j]) {
      assumedQuietKey = out1[i];
      assumedQuietKeyCount = 1;
      while (i + assumedQuietKeyCount < out1_len &&
             out1[i + assumedQuietKeyCount] == quietKey) {
        assumedQuietKeyCount++;
      }
      if (out1[i + assumedQuietKeyCount] == out2[j + assumedQuietKeyCount] ||
          i + assumedQuietKeyCount == out1_len) {
        sillyKey = assumedQuietKey;
        correspondingKey = out2[j];
        i += assumedQuietKeyCount + 1;
        j += assumedQuietKeyCount + 1;
      } else if (out1[i + assumedQuietKeyCount] == out2[j]) {
        quietKey = assumedQuietKey;
        i += assumedQuietKeyCount + 1;
        j++;
      }
    } else {
      i++;
      j++;
    }
  }
  if (i < out1_len) {
    quietKey = out1[out1_len - 1];
  }
  printf("%c %c\n", sillyKey, correspondingKey);
  printf("%c\n", quietKey);
}
