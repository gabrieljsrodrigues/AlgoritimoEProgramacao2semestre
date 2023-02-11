#include <stdio.h>


int main()
{
    printf("Exercicio 5 \n");
    float raio;
    float PI = 3.14;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);
    float area = (PI * (raio*raio));
    printf("Um círculo com raio %f tem área igual %f \n.", raio, area);
}