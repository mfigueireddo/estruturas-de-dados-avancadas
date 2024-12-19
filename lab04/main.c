#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int nodesLeft;
    int nodesRight;
    int height;
    int fb;
};
typedef struct Node Node;

Node* criaNo(int key);
void imprime(Node* node);
void limpa(Node** vetor,int tam);
void contaNos(Node* node);
int getAmount(Node* node);
int checkBinary(Node* node);
int max(int a, int b);
int getHeight(Node* node);
void addHeight(Node* node);
void addFb(Node* node);
int checkAVL(Node* node);

int main(void){

    int posVetor = 0;
    int nums[] = {15,17,3,5,2,20,25,13,10,16};
    // int nums[] = {15,5,17,3,6};
    Node* ponteiros[TAM];
    Node* aux;

    for(int i=0; i<TAM; i++){
        
        aux = criaNo(nums[i]);
        ponteiros[i] = aux;
        if (i!=0){
            if (ponteiros[posVetor]->left == NULL)
                ponteiros[posVetor]->left = aux;
            else if(ponteiros[posVetor]->right == NULL)
                ponteiros[posVetor++]->right = aux;
        }
    }

    // Node* erro = criaNo(1);
    // ponteiros[7]->left = erro;

    addHeight(ponteiros[0]);
    addFb(ponteiros[0]);

    printf("-- Árvore sem contagem de nós --\n\n");
    imprime(ponteiros[0]);

    contaNos(ponteiros[0]);

    printf("-- Árvore com contagem de nós --\n\n");
    imprime(ponteiros[0]);

    if (!checkBinary(ponteiros[0])) printf("A árvore é ABB\n\n");
    else printf("A árvore não é ABB\n\n");

    if(!checkAVL(ponteiros[0])) printf("A árvore é AVL\n\n");
    else printf("A árvore não é AVL\n\n");

    limpa(ponteiros, TAM);

    return 0;
}

Node* criaNo(int key){
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) exit(1);
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->nodesLeft = 0;
    node->nodesRight = 0;
    node->height = 0;
    node->fb = 0;
    printf("Chave %d criada\n\n", node->key);
    return node;
}

void imprime(Node* node){
    if (node == NULL) return;
    printf("Chave: %d ", node->key);
    printf("Altura: %d\n", node->height);
    if (node->left != NULL) printf("Esquerda: %d ", node->left->key);
    if (node->right != NULL) printf("Right: %d\n", node->right->key);
    printf("Nós à esquerda: %d ", node->nodesLeft);
    printf("Nós à direita: %d\n", node->nodesRight);
    printf("FB: %d\n\n", node->fb);
    if (node->left != NULL) imprime(node->left);
    if (node->right != NULL) imprime(node->right);
}

void limpa(Node** vetor,int tam){
    for(int i=0;i<tam;i++){
        free(vetor[i]);
    }
    printf("Árvore limpa\n");
}

void contaNos(Node* node){
    if (node == NULL) return;

    if (node->left != NULL){
        node->nodesLeft = getAmount(node->left);
        contaNos(node->left);
    }

    if (node->right != NULL){
        node->nodesRight = getAmount(node->right);
        contaNos(node->right);
    }
}

int getAmount(Node* node){
    if (node == NULL) return 0;
    if (node->left != NULL) return 1 + getAmount(node->left);
    if (node->right != NULL) return 1 + getAmount(node->right);
}

int checkBinary(Node* node){
    if (node == NULL) return 0;

    if(node->left != NULL && node->left->key > node->key) return -1;
    if(node->right != NULL && node->right->key < node->key) return -1;

    if (checkBinary(node->left)!=0) return -1;
    else if (checkBinary(node->right)!=0) return -1; 
    else return 0;
}

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

int getHeight(Node* node){
    if (node == NULL) return -1;
    else
        return 1 + max(getHeight(node->left),getHeight(node->right));
}

void addHeight(Node* node){
    if (node == NULL) return;

    node->height = getHeight(node);

    if (node->left != NULL) addHeight(node->left);
    if (node->right != NULL) addHeight(node->right);
}

void addFb(Node* node){
    if (node == NULL) return;
    else if (node->left != NULL && node->right != NULL) node->fb = abs(node->left->height - node->right->height);
    else if (node->left != NULL && node->right == NULL) node->fb = node->left->height;
    else if (node->left == NULL && node->right != NULL) node->fb = node->right->height;
    else node->fb = 0;

    if (node->left != NULL) addFb(node->left);
    if (node->right != NULL) addFb(node->right);
}

int checkAVL(Node* node){
    if (node == NULL) return 0;

    if (node->fb>1) return -1;

    if(checkAVL(node->left)!=0) return -1;
    else if(checkAVL(node->right)!=0) return -1;
    else return 0;
}