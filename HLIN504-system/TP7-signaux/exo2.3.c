#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void gst(int s) {
  printf("gestion du signal %d !\n", s);
}

int main(int argc, char* argv[]) {
  struct sigaction action;
  action.sa_handler = SIG_IGN;
  sigaction(SIGINT, &action, NULL);
  while(1);
  return 0;
}