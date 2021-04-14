#include <sched.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

static char child_stack[1048576];//static variable only visible in the current file or function
static int  child_fn(void *__arg) {
    printf("PID: %ld\n", (long)getpid());
}

int main(int, char**) {
    //the third parameter is stack. The direction is downward
  pid_t child_pid = clone(child_fn, child_stack+1048576, CLONE_NEWPID | SIGCHLD, NULL);
  printf("clone() = %ld\n", (long)child_pid);

  pid_t status = waitpid(child_pid, NULL, 0);
  printf("status is %s", status);
  return 0;}
