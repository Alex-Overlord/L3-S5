#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void gst(int s) {
  static int cpt = 1;
  switch (cpt) {
    case 1: 
      printf("Depèchez-vous SVP!\n");
      cpt++;
      alarm(3);
      break;
    case 2:
      printf("Trop tard");
      exit(1);
      break;
  }
  return;
}

int main (int argc, char* argv[]) {
  struct sigaction action;
  action.sa_handler = gst;
  action.sa_flags = SA_RESTART; // pour ne pas retourner au scanf
  sigaction(SIGALRM, &action, NULL);
  alarm(3);
  int i;
  scanf("%i", &i);
  alarm(0);
  printf("Bravo ! %d\n", i);
  return 0;
}