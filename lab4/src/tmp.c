#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int kill(pid_t pid, int sig);

unsigned int alarm(unsigned int seconds);

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

unsigned int sleep (unsigned int sec);

void callback()
{
  printf("called\n");
  kill(0, SIGKILL);
}

int main(int argc, char **argv) {
  if(argc != 1)
  {
    signal(SIGALRM, callback);
    alarm(2);
  }

  while(1)
  {
    printf("proccess...\n");
    sleep (1);
  }
  
  return 0;
}