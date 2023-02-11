#include <stdio.h>

int main ()
{
   printf("Exercicio 3 \n");
    int Celsius;
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%d", &Celsius);
    float GF = (Celsius * 9/5) +32;
    printf("Uma temperatura de %d graus Celsius equivale a %f graus Fahrenheit \n", Celsius, GF);

}