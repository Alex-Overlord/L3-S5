#include <stdio.h>
#include <unistd.h>

void crible(int in[2]) {
  char buf[1024];
  int out[2];
  close(in[1]);
  int P;
  pid_t f;

  if (0 != (P = read(in[0], buf, sizeof(int)))) {
    // P est premier
    printf("%d ", P);
    pipe(out);
    f = fork();
    if (f == 0) {
      // fils
      crible(out);
      _exit(0);
    } else if (f > 0) {
      // père
      close(out[0]);
      int i;
      while (i = read(in[0], buf, sizeof(int))) {
        if (i % P != 0) {
          write(out[1], buf, sizeof(int));
        }
      }
      close(in[0]);
      close(out[1]);
    } else {
      printf("Erreur du fork()\n");
    }
  }
}

int main(int argc, char const *argv[]) {
  int in[2];
  int n = 10;
  char tab[n];
  //char buf2[1024];
  for (int i=0; i<n; i++) {
    tab[i] = i;
    //buf2[] = tab[i];
    write(in[1], tab[i], sizeof(char)); 
  }

  crible(in);

  return 0;
}
