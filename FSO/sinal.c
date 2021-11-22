#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int sinal=0;

void trata(int s){

  if(s == SIGUSR1){
	printf("SIGUSR1 eh para aproveitar mais um pouco\n");
}
  else if(s == SIGALRM && sinal < 2){
	printf("Ai que sono, quero dormir mais um pouco\n");
	sinal++;
}
  else if(s == SIGALRM && sinal == 2){
	printf("Os incomodados que se mudem, tchau\n");
	exit(0);
}
  
}

int main(){

   signal(SIGUSR1,trata);
   signal(SIGALRM,trata);
  
   while(1)
	pause();

return 0;

}
