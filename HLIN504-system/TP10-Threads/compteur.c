#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int compteur = 0; // var statique
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // rajout

void* travail(void* arg) {
  for (int i=0; i<10000; i++) {
    pthread_mutex_lock(&mutex); // rajout
    compteur++;
    pthread_mutex_unlock(&mutex); // rajout
  }
  return NULL;
}

int main(int argc, char*argv[]) {
  pthread_t tid1, tid2; /*ids des threads*/
  if (0 != pthread_create (&tid1, NULL, travail, NULL) ||
      0 != pthread_create (&tid2, NULL, travail, NULL)) { 
    printf("création du thread impossible !\n");
    exit(1);
  }
  travail(NULL);  // appel par thread main

  void* res;
  pthread_join (tid1, &res);
  pthread_join (tid2, &res);
  printf("Valeur finale du compteur incrémenté 30000 fois : %d \n", compteur);

  return 0;
}