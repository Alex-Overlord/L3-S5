#include "mm.h"
#include <stdlib.h>
#include <stdio.h>

mm mm_creer() {
  mm game = (mm) malloc(sizeof(struct mm));
  for (int i = 0; i < TAILLE; i++) {
    jeu->secret[i] = rand()%10;
  }
  
}

void print() {
  for(int i = 0; i < TAILLE; i++) {
    printf("%c", jeu->secret[i]);
  }
}

int main() {
  mm game;
  game->mm_creer;
  game->print;
  
  return 0;
}
