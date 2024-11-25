#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

int func();
int func(){
  pid_t p = 1;
  //for generalization
  for (int i = 0;i<2;i++){ //creates the children
    printf("\np: %d",p);
    if (p != 0 && p != 1){ //if process is the parent, fork again
      p = fork();
      printf("\nfork created");
      if (p == -1){
        err();
      }
    }
  }
  return 0;
}

int main(){
  func();
  return 0;
}
