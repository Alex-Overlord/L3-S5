#include <stdio.h> // printf
#include <unistd.h> // pipe

int main(int argc, char const *argv[]) {
  char buf[1024];
  int tube[2];
  int cpt = 1;

  if (pipe(tube) != -1) {
    while(1) {
      write(tube[1], buf, 1024);
      printf("écrit %d Ko \n", cpt);
      cpt++;
    }
  }  
  return 0;
}
