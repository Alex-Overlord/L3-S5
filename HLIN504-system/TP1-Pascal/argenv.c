#include <stdio.h>
#include <stdlib.h>

/*
  Donnée: int argc, char* argv[], char* env
  Résultat: void
  Début
    pour i de 0 à argc, afficher argv[i]
    tant que j != NULL, afficher env[j]
  Fin
 */

int main(int argc, char* argv[], char** env) {
  printf("%i\n", argc);
  for (int i=0; i<argc; i++) {
    printf("%s\n", argv[i]);  
  }

  // int j = 0;
  // while (env[j] != NULL) {
  //   printf("%i : %s\n", j, env[j]);
  //   j++;
  // }
  
  return 0;
}