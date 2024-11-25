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
    if (p != 0){ //if process is the parent, fork again
      p = fork();
      if (p == -1){
        err();
      }
    }
  }


}

int main(){
  func();
}
