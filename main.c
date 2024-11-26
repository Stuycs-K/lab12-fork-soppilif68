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

int * get_random(int length){
  int r_file = open("/dev/random", O_RDONLY , 0);

  int * buff = (int *) malloc(length*sizeof(int));
  if(r_file == -1) err();
  int n;
  n = read(r_file, buff, length*sizeof(int));
  return buff;
}

int func();
int func(){
  pid_t p = 1;
  //for generalization
//  printf("\ninit p: %d",p);


  for (int i = 0;i<2;i++){ //creates the children
    if (p != 0){ //if process is the parent, fork again
      p = fork();
//      printf("\nfork created");
      if (p == -1){
        err();
      }
    }
//    printf("\np: %d, %d",p,getpid());
  }
  int * rp = get_random(1);
  int r = *rp;
  r = abs(r);
  r = (r % 5) + 1;
  printf("\nr:%d",r);

//  printf("\n1");
  sleep(r);
  return 0;
}

int main(){
  func();

  printf("\n");
  return 0;
}
