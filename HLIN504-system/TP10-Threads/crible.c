#include <stdio.h> // printf
#include <stdlib.h> 
#include <unistd.h> // pipe
#include <pthread.h>

void* crible(void* a) {
  int codeRet = 1;
  int* in = (int*) a;
  int P;

  if (read(in[0], &P, sizeof(int) != sizeof(int))) {
    close(in[0]);
    codeRet = 0; 
    return (void*) &codeRet; // return 0
  }
  printf("%d \n", P);
  fflush(stdout);
  int* out = malloc(2*sizeof(int));
  int r = pipe(out);
  if (r == -1) {
    return (void*) &codeRet;
  }
  pthread_t tid;
  if (0 != pthread_create(&tid, NULL, crible, (void*) out)) {
    fprintf(stderr, "Error\n");
    return NULL;
  }
  int i;
  while (sizeof(int) == read(in[0], &i, sizeof(int))) {
    if (i % P) {
      write (out[1], &i, sizeof(int));
    }
  }
  close(in[0]);
  close(out[1]);
  int res;
  pthread_join(tid, (void*) &res);
  return (void*) &res;
}

int main(int argc, char* argv[]) {
  int tube[2];

  crible(argv[1]);

  return 0;
}