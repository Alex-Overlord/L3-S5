#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct sigaction action;

void gst(int s) {
  printf("gestion du signal %d !\n", s);
  action.sa_handler = SIG_DFL;
  sigaction(SIGINT, &action, NULL);
}

int main(int argc, char* argv[]) {
  action.sa_handler = gst;
  sigaction(SIGINT, &action, NULL);
  while(1);
  return 0;
}