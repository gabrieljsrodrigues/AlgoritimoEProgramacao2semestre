#include <stdio.h>

int main()
{
    printf("Exercicio 2\n");
    float peso;
    float altura;
    printf("Digite seu peso: ");
    scanf("%f", &peso);
    scanf("%f", &altura);
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    float IMC = peso /  (altura*altura);
    printf("O IMC de uma pessoa com peso %f kg e altura %f m é igual a %f ", peso, altura, IMC);
}