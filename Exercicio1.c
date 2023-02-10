#include <stdio.h>

int main()
{
    printf("Exercício 1\n");
    int num1;
    int num2;
    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite outro numero: ");
    scanf(" %d", &num2);
    int w = num1 + num2;
    int x = num1 - num2;
    int y = num1 * num2;
    int z = num1 / num2;
    printf("O resultado da soma é %d \n", w);
    printf("O resultado da subtração é %d \n", x);
    printf("O resultado da multiplicação é %d \n", y);
    printf("O resultado da divisão é %d \n", z);
}