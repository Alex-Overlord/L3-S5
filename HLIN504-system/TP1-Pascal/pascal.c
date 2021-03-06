#include <stdio.h>
#include <stdlib.h>

int** pascal(int n, int p) {
  int **triangle = (int**) malloc(++n * sizeof(int*));  
  for(int i = 0; i < n; i++) {
    triangle[i] = (int*) malloc(n * sizeof(int));
    for(int j = 0; j < n; j++) {
      if (j == 0) {
	triangle[i][j] = 1;
      }
      else {
	triangle[i][j] = 0;
      }
    }
  }
  
  for (int i=1; i<n; i++) {
    for (int j=1; j<n; j++) {
      triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
    }
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (triangle[i][j] != 0) {
	printf("%i ", triangle[i][j]);      
      }
    }
    printf("\n");
  }
  
  printf("Combinaisons possibles de C(%i,%i) : %i\n", n-1, p, triangle[n-1][p]);
  
  return triangle;
}

int main(int argc, char* argv[], char* env[]) {
  pascal(17,2);
  
  return 0;
}
