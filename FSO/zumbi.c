#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int matar = 0;
pid_t p;
void zumbi(int s)
{
  if (matar == 2)
    exit(0);
  if (matar == 0)
  {
    p = fork();
    if (p == 0)
    {
      exit(0);
    }
  }
  if (matar == 1)
  {
    wait(NULL);
  }
    matar++;
}

int main()
{
  // p = getpid();
  signal(SIGUSR1, zumbi);
  signal(SIGUSR2, zumbi);

  while (1)
    pause();
  
}
