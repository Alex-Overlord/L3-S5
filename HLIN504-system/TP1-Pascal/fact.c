#include <stdio.h>

int fact_ite(int n) {
  int f = 1;
  for (int i=0; i<n; i++) {
    f *= n;
  }
  return f;
}

int fact(int n) {
  return (n == 0) ? 1 : n * fact(n-1);
}

int main(int argc, char* argv[], char* env[])
{
  printf("%i\n", fact(4));

  return 0;
}
