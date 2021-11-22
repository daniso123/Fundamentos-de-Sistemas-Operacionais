#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>


int senha=0;
void trata(int s)
{
     printf("Recebi %d\n", s);
     if(senha==0 && s==SIGINT)
	senha++;
     else if(senha==1 && s==SIGUSR2)
	senha++;
     else if(senha==2 && s==SIGTERM)
	{
	senha++;
	printf("Senha acionada\n");
	}
     else if(s==SIGINT)
	senha=1; 
     else if(senha==3 && s==SIGUSR1)
	{
	printf("Tchau\n");
	exit(0);
	}
	else
	  senha=0;

} 

int main(void)
{
  signal(SIGINT, trata);
  signal(SIGTERM, trata);
  signal(SIGUSR1, trata);
  signal(SIGUSR2, trata);

  while(1)
  pause();

  return 0;
}
