#include <stdio.h>
#include <stdlib.h>

int* f1() {
  int* tab = (int*) malloc(3 * sizeof(int));
  return tab;
}

void f2() {
  int tab[3];
  for (int i=0; i<3; i++) {
    printf("%p ", &tab[i]);
  }
}

int main() {
  int* tab = f1();
  for (int i=0; i<3; i++) {
    printf("%p ", &tab[i]);
  }

  f2();

  return 0;
}
