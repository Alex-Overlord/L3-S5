#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int tube[2];

  pipe(tube);

  int f=fork();
  char buf[4];

  if(f==0){ //enfant
    buf[0]='a';
    buf[1]='b';
    buf[2]='l';
    buf[3]='a';
    printf("avant buf: %s ",buf);
 
    close(tube[0]);
    //while(
    write(tube[1],buf,4);
    close(tube[1]);
  }
  else if(f != -1){
      close(tube[1]);
      read(tube[0],buf,4);
      printf("buf: %s ",buf);
      close(tube[0]);
    }
}