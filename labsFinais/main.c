#include <stdio.h>
#include <stdlib.h>

struct No{
    int chave;
    struct No* prox;
};

struct NoBusca{
    int distancia;
    struct No* pai;
};

typedef struct No No;
typedef struct NoBusca NoBusca;

// Protótipos
No** lista_adjacencias(void);
void insere(No** vetor, int chave, int indice);
No* criaNo(int chave);
void imprime(No* vetor[], int tam);
void matriz_adjacencias(void);
void busca_amplitude(No* grafo[], int ponto_partida);
NoBusca* criaNoBusca(int distancia, NoBusca* pai);
void addPilha(int* vetor, int tam, int chave);
void imprimeBusca(NoBusca* tabela[], int tam);

int main(void){

    No** aux = lista_adjacencias();
    //matriz_adjacencias();
    busca_amplitude(aux, 0);

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
- A função deve criar um grafo com os valores passados, imprimi-lo e devolve-lo

Assertivas de saída
- A função deve retornar um ponteiro para o vetor com o grafo montado
*/
No** lista_adjacencias(void){

    // Inicializa o vetor
    No** grafo = (No**)malloc(sizeof(No*)*10);
    exit(1);
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

    return grafo;

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

/*
Objetivo
- Criar uma matriz de adjacências

Descrição
- Criar um vetor estático com as dimensões indicadas
- Preenchê-lo com 0
- Acessar o índice desejado e preencher com 1 
- O índice deve ser acessado por [i][j] sendo i o nó trabalhado e j o nó adjacente

*/
void matriz_adjacencias(void){

    int grafo[10][10];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            grafo[i][j] = 0;
        }
    }

    // Nó 0
    grafo[0][1] = 1;
    grafo[0][8] = 1;

    // Nó 1
    grafo[1][0] = 1;
    grafo[1][3] = 1;
    grafo[1][8] = 1;

    // Nó 2
    
    // Nó 3
    grafo[3][1] = 1;
    grafo[3][4] = 1;
    grafo[3][6] = 1;
    grafo[3][9] = 1;

    // Nó 4
    grafo[4][3] = 1;
    grafo[4][5] = 1;
    grafo[4][6] = 1;

    // Nó 5
    grafo[5][4] = 1;
    grafo[5][6] = 1;

    // Nó 6
    grafo[6][3] = 1;
    grafo[6][4] = 1;
    grafo[6][5] = 1;
    grafo[6][7] = 1;

    // Nó 7
    grafo[7][6] = 1;
    grafo[7][8] = 1;
    grafo[7][9] = 1;
    
    // Nó 8
    grafo[8][0] = 1;
    grafo[8][1] = 1;
    grafo[8][7] = 1;
    grafo[8][9] = 1;

    // Nó 9
    grafo[9][3] = 1;
    grafo[9][7] = 1;
    grafo[9][8] = 1;

    printf("\n<== MATRIZ DE ADJACÊNCIAS ==>\n");

    // Imprime o grafo
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }

}

/*
Objetivo
- Realizar uma busca em amplitude

Descrição
- Criar um vetor de ponteiros para estrutura NoBusca
- Cada índice do vetor corresponde ao número do nó
- Criar um vetor para armazenar os valores já vistados
- Criar um vetor para armazenar quais nós devem ser visitados
- Visitar os vizinhos do ponto de partida
- Armazenar a quantidadade de saltos
- Armazenar o "pai" desses vizinhos
- Adicionar esses vizinhos à pilha
- Adicionar esses vizinhos à lista de já visitados
- Repetir esse processo

Parâmetros
- Vetor com a lista de adjacências
- Ponto de partida
*/
void busca_amplitude(No* grafo[], int ponto_partida){

    // Int que indica qual o número do nó sendo checado
    int atual = ponto_partida;

    // Tabela para armazenar a distância das chaves e seus pais
    NoBusca* tabela[10];
    for(int i=0; i<10; i++){
        tabela[i] = (NoBusca*)malloc(sizeof(NoBusca));
        if (tabela[i] == NULL) exit(1);
    }

    // Vetor que armazena quais índices já foram visitados (1)
    int visitados[10];
    for(int i=0; i<10; i++){
        visitados[i] = 0;
    }

    // Vetor para armazenar quais os próximos nós a serem visitados (pilha)
    int pilha[10];
    for(int i=0; i<10; i++){
        pilha[i] = -1;
    }

    // Preenche os dados para o ponto de partida
    tabela[atual]->distancia = 0;
    tabela[atual]->pai = NULL;
    visitados[atual] = 1;
    pilha[0] = ponto_partida;

    // Percorre a pilha
    for(int i=0; i<0; i++){

        atual = pilha[i];

        // Percorre os nós vizinhos do atual número da pilha
        for(No* aux = grafo[atual]; aux != NULL; aux = aux->prox){

            // Se este nó não tiver sido visitado
            if (!visitados[aux->chave]){

                // Adiciona na tabela
                tabela[aux->chave] = criaNoBusca(tabela[atual]->distancia+1, tabela[atual]);

                // Marca como visitado
                visitados[aux->chave] = 1;

                // Adiciona na pilha
                addPilha(pilha, 10, aux->chave);

            }

        }
    }

    // Imprime a tabela
    imprimeBusca(tabela, 10);

}

/*
Descrição
- Criar dinamicamente um nó de busca
- Atribuir ao nó a distância passada como parâmetro
- Atribuir ao nó o pai passado como parâmetro

Parâmetros
- Distância
- Ponteiro para o pai

Retorno
- Um ponteiro para o nó criado

Assertivas de entrada
- Distância deve ser int
- Ponteiro para o pai deve ser struct NoBusca*

Assertivas de saída
- A função deve retornar um ponteiro para o nó criado dinamicamente
*/
NoBusca* criaNoBusca(int distancia, NoBusca* pai){
    NoBusca* novo_no = (NoBusca*)malloc(sizeof(NoBusca));
    if (novo_no == NULL) exit(1);
    novo_no->distancia = distancia;
    novo_no->pai = pai;
    return novo_no;
}

/*
Descrição
- Percorrer o vetor até encontrar uma posição nula
- Armazenar a chave passada

Parâmetros
- Vetor
- Tamanho do vetor
- Chave

Assertivas de entrada
- Vetor deve ser int*
- Valor deve ser int
*/
void addPilha(int* vetor, int tam, int chave){

    int i;
    for(i=0; i<tam && vetor[i]!=-1; i++);
    vetor[i] = chave;
}

/*
Descrição
- Percorrer todos os NoBusca da tabela e exibir: índice, distância e endereço do pai

Parâmetros
- Vetor de ponteiros para NoBusca*
- Tamanho do vetor
*/
void imprimeBusca(NoBusca* tabela[], int tam){

    for(int i=0; i<tam; i++){
        printf("%d\n", i);

        if (tabela[i]!=NULL){
            printf("Distância %d Pai %p\n", tabela[i]->distancia, tabela[i]->pai);
        }

    }

}