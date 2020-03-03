#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid;
  switch(pid = fork()) {
  case -1 : {
    printf("Probleme : echec du fork");
    break;
  }
  case 0 : {
    printf("du descendant : valeur de retour de fork() : %d\n", pid);
    printf("du descendant : je suis %d de parent %d \n", getpid(), getppid());
    break;
  }
  default : {
    printf("du parent : valeur de retour de fork(à : %d\n", pid);
