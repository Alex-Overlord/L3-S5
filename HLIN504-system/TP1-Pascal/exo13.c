#include <stdio.h>
#include <stdlib.h>

int main() {
  // --- 1
  int t1[] = {1, 2, 3};
  for (int i=0; i<3; i++) {
    printf("%p ", &t1[i]);
  }
  printf("\n");
  // --- 1
  // --- 2
  int t2[3];
  for (int i=0; i<3; i++) {
    printf("%p ", &t2[i]);
  }  
  printf("\n");
  // --- 2

  return 0;
}
