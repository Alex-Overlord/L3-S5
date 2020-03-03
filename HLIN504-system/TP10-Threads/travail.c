#include <pthread.h> //thread
#include <stdio.h> // printf
#include <stdlib.h> // exit(1)

void* travail(void* arg ) {
  printf("%lu: travail(%s)\n", pthread_self(), (char*) arg);
  return (void*) "fini !";
}

int main(int argc, char* argv[]) {
  pthread_t tid; /*id du thread*/
  if (0 != pthread_create (&tid, NULL, travail, "Bonjour !")) {
    // (id, attributs, fonction à exécuter, arg de la fon)
    printf("création du thread impossible !\n");
    exit(1);
  }
  printf("\n %lu: thread %lu créé et lancé !\n", pthread_self(), tid);
  void* res;
  pthread_join(tid, &res); // wait du thread et récup  retour

  printf("%lu: thread %lu terminé en renvoyant \"%s\"\n", pthread_self(), tid, (char*) res);
  return 0;
}