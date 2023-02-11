#include <stdio.h>
#include <math.h>

int main()
{
    printf("Exercicio 4 \n");
    int cateto1;
    int cateto2;
    printf("Digite o valor de um cateto: \n");
    scanf("%d", &cateto1);
    printf("Digite o valor do outro cateto: \n");
    scanf("%d", &cateto2);
    float hipo = sqrt(cateto1*cateto1 + cateto2*cateto2);
    printf("Um triângulo retângulo com lados %d e %d tem uma hipotenusa igual a %f.", cateto1, cateto2, hipo);
}