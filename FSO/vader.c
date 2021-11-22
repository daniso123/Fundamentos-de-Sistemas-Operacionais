//sith vs jedi
#include<stdio.h>
#include<stdlib.h>

void  sithVSjedi(int v){
    if(v %2==0){
        printf("Jedi\n");
    }
    else{
        printf("Sith\n");
    }
}
int main(){
    int n =0;
    int vader =0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
       scanf("%d", &vader);
       sithVSjedi(vader);
    }
    
    
}
