//Vetores Idênticos//
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int vet1[10000000];
int vet2[10000000];

struct str
{
    int *vet;
    int size;
    pthread_t tid;
};

struct compara
{
    int inicio;
    int fim;
    int result;
    pthread_t tid;
};

int compara(const void *x, const void *y)
{
    if (*(int *)x > *(int *)y)
        return 1;
    if (*(int *)x < *(int *)y)
        return -1;
    return 0;
}

void *th_func(void *p)
{
    struct str *x = (struct str *)p;
    qsort(x->vet, x->size, sizeof(int), compara);
}

void *tr_compara(void *p)
{
    struct compara *x = (struct compara *)p;
    for (int i = x->inicio; i < x->fim; i++)
    {
        if (vet1[i] != vet2[i])
        {
            x->result = 0;
            return NULL;
        }
    }
    x->result = 1;
}
int main(void)
{
    int thvet1, thvet2;
    scanf("%d", &thvet1);
    thvet2 = thvet1;

    for (int i = 0; i < thvet1; i++)
        scanf("%d", &vet1[i]);

    for (int i = 0; i < thvet2; i++)
        scanf("%d", &vet2[i]);

    struct str t1, t2;
    t1.vet = vet1;
    t1.size = thvet1;
    t2.vet = vet2;
    t2.size = thvet2;
    pthread_create(&t1.tid, NULL, th_func, (void *)&t1);
    pthread_create(&t2.tid, NULL, th_func, (void *)&t2);
    pthread_join(t1.tid, NULL);
    pthread_join(t2.tid, NULL);

    struct compara ct1, ct2;
    ct1.inicio = 0;
    ct1.fim = thvet1 / 2;
    ct2.inicio = thvet1 / 2;
    ct2.fim = thvet1;
    pthread_create(&ct1.tid, NULL, tr_compara, (void *)&ct1);
    pthread_create(&ct2.tid, NULL, tr_compara, (void *)&ct2);
    pthread_join(ct1.tid, NULL);
    pthread_join(ct2.tid, NULL);

    if (ct1.result == 1 && ct2.result == 1)
        printf("Mesmos elementos\n");
    else
        printf("Diferentes\n");
}
