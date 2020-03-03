#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[], char* env[]) {
  /*
  int j = 0;
  while (env[j] != NULL) {
    printf("%i : %s\n", j, env[j]);
    j++;
  }
  */
  printf("%s\n", env[8]);

  return 0;
}
