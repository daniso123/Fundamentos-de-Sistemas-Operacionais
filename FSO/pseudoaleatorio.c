#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sem1[100000];
int sem2[100000];
int mi, bi;

struct str
{
    int *vet;
    int size;
    pthread_t tid;
};

void *calcula_perguntas(void *p)
{
    struct str *a = (struct str *)p;
    for (int i = 0; i < 100000; i++)
        if (a->vet[i] % mi == bi) a->size++;
}

int main()
{
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    for (int i = 0; i < 100000; i++)
    {
        sem1[i] = rand_r(&s1);
    }
    for(int i =0; i< 100000; i++){
         sem2[i] = rand_r(&s2);
    }
    while (scanf("%d %d", &mi, &bi) != EOF)
    {
        struct str d1, d2;
        d1.size = 0;
        d2.size = 0;
        d1.vet = sem1;
        d2.vet = sem2;
        pthread_create(&d1.tid, NULL, calcula_perguntas, (void *)&d1);
        pthread_create(&d2.tid, NULL, calcula_perguntas, (void *)&d2);
        pthread_join(d1.tid, NULL);
        pthread_join(d2.tid, NULL);

        printf("%d\n", d1.size + d2.size);
    }
   
}