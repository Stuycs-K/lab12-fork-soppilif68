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
  pid_t parent = getpid();
  printf("%d about to create 2 child processes.\n",parent);


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
  pid_t curr = getpid();

  int * rp = get_random(1);
  int r = *rp;
  r = abs(r);
  r = (r % 5) + 1;
  // printf("\nr:%d",r);

//  printf("\n1");
  if (curr != parent){
    sleep(r);
    printf("%d finished after %d seconds\n",getpid(),r);
    exit(r);
  }
  else{
    int * status = &curr;
    pid_t child = wait(status);
    printf("status:%d\n",*status);
    int sec = WEXITSTATUS(*status);
    printf("\nMain Process %d is done. Child %d slept for %d sec\n",parent,child,sec);
    return 0;
  }
}

int main(){
  func();

  printf("\n\n");
  return 0;
}
