//Nome: Gabriel de Jesus Silva Rodrigues - TIA: 42208440 - Turma:02N


#include <stdio.h> // Biblioteca usada para entrada e saida
#include <stdlib.h> // Biblioteca usada para alocação de memória
#include <string.h> // Biblioteca usada para manipulação de Strings
#include <ctype.h> // Biblioteca usada para funções de manipulação de caracteres

//Define uma constante com o valor máximo de uma palavra no programa
#define TAM_MAX 100 

// Função para comparar duas palavras ignorando o "CaSe InSeNsItIvE"
int comparaPalavra(const void *a, const void *b) { //Função de compração que recebe dois ponteiros que apontam para os elementos a serem comparados.
    const char *palavra1 = *(const char **)a; //
    const char *palavra2 = *(const char **)b;
    return strcasecmp(palavra1, palavra2); //Função usada para compara as palavras, mas ignorando o "CaSe InSeNsItIvE"
}

// Função para realizar a busca binária em um vetor ordenado de palavras
int buscaBin(const char *palavra, const char **dic, int tam) { //Função que implementa a busca binária em um vetor ordenado de palavras.
    int esq = 0; // Representa o índice do primeiro elemento do vetor, incializado com o valor "0".
    int dir = tam - 1; //Representa o índice do último elemento do vetor, inicializado com o valor "tam - 1".
    
    while (esq <= dir) {
        int mid = esq + (dir - esq) / 2; // Calcula o índice do elemento do meio do intervalo de busca.
        int cmp = strcasecmp(palavra, dic[mid]);//Compara a palavra buscada com o elemento do meio do intervalo.
        
        if (cmp == 0)
            return mid; // Verifica se a palavra já existe no dicionário.
        
        if (cmp < 0)
            dir = mid - 1;//Verifica se a palavra buscada é menor que o elemento do meio do intervalo.
        else
            esq = mid + 1; // Verifica se a palavra buscada é maior que o elemento do meio do intervalo.
    } //
    
    return -1; // A palavra não foi encontrada no dicionário
}
// Função para inserir uma palavra no dicionário ordenado
void inserirPalavra(const char *palavra, char **dic, int *tam) { // Declaração da função que "InserirPalavra", que recebe três parâmentros: "Palavra"(um ponteiro constante para uma string), "dic"(Um ponteiro para o ponteiro char), e "tam"(Um ponteiro para int).
    int i;// Declaração da varíavel inteira "i", que será utilizada para iterar pelo dicionário.
    
    // Procura a posição de inserção usando busca binária
    for (i = *tam - 1; i >= 0 && strcasecmp(palavra, dic[i]) < 0; i--)//Inicialização do loop "for" que busca a posição correta para inserir a a palavra no dicionário, utilizando a técnica de busca binária.
        dic[i + 1] = dic[i]; // Essa operação coloca todos os elementos maiores do que a palavra a ser inserida em uma posição adiante no dicionário.
    
    dic[i + 1] = strdup(palavra); // Insere a palavra no dicionário //função ulitilizada para alocar memória e copiar a string "palavra", para a nova posição do dicionário.
    (*tam)++; // Incrementação para refletir a adição do novo elemento.
}

// Função para liberar a memória alocada pelo dicionário
void freeDictionary(char **dic, int tam) { // Declaração da função que recebe dois parâmetros: "dic"um ponteiro para o ponteiro char) e "tam"(um inteiro).
    for (int i = 0; i < tam; i++)
        free(dic[i]);//Loop que itera sobre os elementos do dicionário até o tamanho "tam". a função "free" tem o papel de liberar memória alocada para cada elemento do dicionário.
    free(dic);// A função é chamada novamente para fazer a liberação de memória alocada para o próprio dicionário.
}

int main() {// Declaração da função "main".
    char **dic = NULL; //"dic é um ponteiro para o ponteiro de char, que será utilizado para armazenar o dicionário de palavras".
    int dicTam = 0;//É o tamanho atual do dicionário(o número de palavras presentes nele).
    int dictCap = 0;//É a capacidade atual do dicionário, ou seja, o número máximo de palavras que pode acomodar sem necessidade de realocação de memória.
    
    FILE *arquivo = fopen("texto.txt", "r");//Declaração e abertura do arquivo a ser lido.
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;//// Verifica se ocorreu algum erro durante a abertura do arquivo. Caso isso aconteça, uma mensagem de erro é exibida e o programa retorna "1", indicando falha na execução.
    }
    char palavra[TAM_MAX]; //Declaração de uma matriz de caracteres com tamanho máximo definido pela constante. A matriz será usada para armazenar cada palavra lida do arquivo.
    
    while (fscanf(arquivo, "%s", palavra) == 1) { //Inicia o loop que lê a palavra do arquivo utilizando 'fscanf'. O formato "%s" especifica que será lido um sequência de caracteres até encontrar um espaço em branco ou uma quebra de linha.
        // Converte a palavra para minúsculas
        for (int i = 0; palavra[i] != '\0'; i++)
            palavra[i] = tolower(palavra[i]);//Loop que percorre cada caractere da palavra lida e converte para minúsculo usando a função "tolower". Isso garante que todas as palavras sejam tratadas de forma "CaSe InSeNsItIve".

        // Verifica se a palavra já existe no dicionário
        if (buscaBin(palavra, dic, dicTam) == -1) { //Verifica se a palavra já existe no dicionário usando a função "buscaBin", a função retorna - 1 se a palavra não for encontrada no dicionário.
            // Insere a palavra no dicionário
            if (dicTam == dictCap) {// Verifica se o tamanho atual do dicionário é igual a capacidade atual.
                dictCap = (dictCap == 0) ? 1 : dictCap * 2; //Atualiza a capacidade do dicionário. Se a capacidade atual for igual a zero, significa que o dicionário ainda não foi alocado e, portanto, atribui-se o valor 1 à capacidade. Caso contrário, a capacidade é dobrada mutiplicando-a por 2.
                dic = realloc(dic, dictCap * sizeof(char *));// Utiliza a função para redimensionar o vetor apra nova capacidade.
            }
            inserirPalavra(palavra, dic, &dicTam);// Usada para inserir a palavra no dicionário, passando a palavra, o dicionário e um ponteiro para o tamanho atual do dicionário.
        }
    }
    fclose(arquivo); //Fecha o arquivo de texto que foi aberto anteriormente.
    
    // Imprime as palavras ordenadas
    for (int i = 0; i < dicTam; i++) //Incia um loop que percorre o dicionário, onde a variável "i" é inicializada com 0 E o loop continua enquanto "i" for menor que "dicTam", que representa o número de palavras diferentes armazenadas no dicionário.
        printf("%s\n", dic[i]);//Usado para imprimir a a palavra no índice "i" do dicionário.
    
    printf("Total de palavras diferentes: %d\n", dicTam);//Essa linha é responsável por mostrar o valor de "dicTam" que representa o número de palavras diferentes no dicionário.
    
    // Libera a memória alocada pelo dicionário
    freeDictionary(dic, dicTam);//Chama uma função para liberar memória alocada para o dicionário. A função vai percorrer o dicionário e liberar a memória de cada palavra armazenada, além de liberar a memória do próprio dicionário.
    
    return 0; // Encerra a função "main" e retorna 0 para indicar que o programa foi executado com sucerro.
}