#include <stdio.h>
#include <stdlib.h>

struct No{
    int chave;
    struct No* prox;
};

typedef struct No No;

// Protótipos
void lista_adjacencias(void);
void insere(No** vetor, int chave, int indice);
No* criaNo(int chave);
void imprime(No* vetor[], int tam);

int main(void){

    lista_adjacencias();

    return 0;
}

/*
Objetivo
- Fazer uma lista de adjacências

Descrição
- Criar um vetor com 10 posições
- O índice vai ser correspondente ao número do nó
- Em cada posição vai haver um ponteiro para uma estrutura
- Cada estrutura deverá ter o valor do nó adjacente e um ponteiro para o próximo nó

Assertivas de saída
- A função deve criar um grafo com os valores passados e imprimi-lo

*/
void lista_adjacencias(void){

    // Inicializa o vetor
    No* grafo[10];
    for(int i=0; i<10; i++){
        grafo[i] = NULL;
    }

    // Insere os valores desejados no grafo

    // Nó 0
    insere(grafo, 1, 0);
    insere(grafo, 8, 0);

    // Nó 1 
    insere(grafo, 0, 1);
    insere(grafo, 3, 1);
    insere(grafo, 8, 1);

    // Nó 2

    // Nó 3 
    insere(grafo, 1, 3);
    insere(grafo, 4, 3);
    insere(grafo, 6, 3);
    insere(grafo, 9, 3);

    // Nó 4 
    insere(grafo, 3, 4);
    insere(grafo, 5, 4);
    insere(grafo, 6, 4);

    // Nó 5
    insere(grafo, 4, 5);
    insere(grafo, 6, 5);

    // Nó 6
    insere(grafo, 3, 6);
    insere(grafo, 4, 6);
    insere(grafo, 5, 6);
    insere(grafo, 7, 6);

    // Nó 7
    insere(grafo, 6, 7);
    insere(grafo, 8, 7);
    insere(grafo, 9, 7);

    // Nó 8
    insere(grafo, 0, 8);
    insere(grafo, 1, 8);
    insere(grafo, 7, 8);
    insere(grafo, 9, 8);

    // Nó 9
    insere(grafo, 3, 9);
    insere(grafo, 7, 9);
    insere(grafo, 8, 9);

    // Imprime o grafo
    imprime(grafo, 10);

}

/* 
Objetivo
- Colocar a chave no vetor pelo índice indicado

Descrição 
- Acessar o vetor no índice indicado
- Procurar um espaço NULL naquele nó
- Criar um struct No no lugar daquele NULL com a chave a ser inserida
- Fazer com que o ponteiro que apontava para NULL aponte para o novo nó

Parâmetros
- Vetor de ponteiros
- Chave a ser inserida
- Índice a inserir a chave no nó

Assertivas de entrada
- Vetor deve ser um ponteiro para struct No
- Chave deve ser int
- Índice deve ser int

Assertivas de saída
- A função deve alterar o vetor no índice indicado, adicionando um nó com a chave passada

*/
void insere(No* vetor[], int chave, int indice){

    if (vetor[indice] == NULL){
        vetor[indice] = criaNo(chave);
        return;
    }

    // Cria um ponteiro para percorre a lista no vetor pelo índice indicado
    No* aux = vetor[indice];
    No* anterior;

    // Procura o primeiro espaço nulo, salvando o nó anterior
    for(; aux != NULL; aux = aux->prox){
        anterior = aux;
    }

    aux = criaNo(chave);
    anterior->prox = aux;

    printf("** Chave %d inserida no índice %d **\n", chave, indice);
}

/*
Descrição
- Criar dinamicamente um nó
- Atribuir ao nó a chave passada como parâmetro
- Ponteiro para o próximo deve ser NULL

Parâmetros
- Chave a ser inserida

Retorno
- Um ponteiro para o nó criado

Assertivas de entrada
- A chave deve ser int

Assertivas de saída
- A função deve retornar um ponteiro para o nó criado dinamicamente
*/
No* criaNo(int chave){
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) exit(1);
    novo_no->chave = chave;
    novo_no->prox = NULL;
    return novo_no;
}

/*
Descrição
- Percorrer todo o vetor do grafo
- A cada índice, percorrer a lista encadeada imprimindo os valores até chegar em NULL

Parâmetros
- Ponteiro para vetor de ponteiros
- Tamanho do vetor

Assertivas de saída
- Índice do vetor deverá ser impresso
- Todos os valores armazenados devem ser impressos. Os índices que não possuem nada, não imprimirão nada.
*/
void imprime(No* vetor[], int tam){

    printf("\n<== LISTA DE ADJACÊNCIAS ==>\n");

    for(int i=0; i<tam; i++){

        printf("%d: ", i);
        
        for(No* aux = vetor[i]; aux != NULL; aux = aux->prox){
            printf("%d ", aux->chave);
        }

        printf("\n");

    }   

}