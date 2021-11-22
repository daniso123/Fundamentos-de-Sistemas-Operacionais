//INSONOS

#include <stdio.h>
#include <stdlib.h>

int inverter(int numero)
{
    if (numero == 0)
        return numero;

    else
    {
        printf("%d", numero % 10);
        numero = numero / 10;
        return inverter(numero);
    }
    return 0;
}

void insano(int num)
{
    int re;

    int result = inverter(num);
    printf("%d\n", inverter(num));
    re = result + num;
    // se a divisão de result for igual a 1 é impar
    if (re % 2 == 1)
    {
    
    printf("%d é insano\n", re);
}

else
{
    printf("%d não é insano\n", re);
}
}

int main()
{

    int num;
    int n;
    
    //for (int i = 0; i < n; i++)
    // {
    scanf("%d\n", &num);
    insano(num);
    //}

    return 0;
}
