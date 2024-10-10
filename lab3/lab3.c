#include <stdio.h>
#include <stdlib.h>

struct Arvore{
  int chave;
  int nivel;
  int altura;
  struct Arvore* filho_esquerda;
  struct Arvore* filho_direita;
  struct Arvore* pai;
};

typedef struct Arvore Arvore;

int max(int a, int b);
Arvore* criaNo(int chave);
void insereEsquerda(Arvore* pPai, Arvore* pFilho, int nivel);
void insereDireita(Arvore* pPai, Arvore* pFilho, int nivel);
int getAltura(Arvore* pArvore);
void addAltura(Arvore* pArvore);
void imprimeArvore(Arvore* pArvore);
void liberaArvore(Arvore** vPonteiros, int tamanho);

int main(void) {

	int posVetor = 0;
  int nivel = 1;
	int i;

	int vNumeros[] = { 10, 5, 15, 3, 7, 13, 20, 1, 4, 6 };
	Arvore* vPonteiros[10];
	Arvore* pAux;

	for (i = 0; i < 10; i++) {

		pAux = criaNo(vNumeros[i]); // Cria um espaço na memória pro nó

		if (i == 0){
            vPonteiros[i] = pAux; // Caso da primeira chave -> guarda a primeira chave no vetor
            pAux->nivel = 0;
            printf("** Raiz de chave %d (nível %d) **\n\n", pAux->chave, pAux->nivel);
        }

		else { // Demais casos
			vPonteiros[i] = pAux; // Guarda a chave N no vetor
			if (vPonteiros[posVetor]->filho_esquerda == NULL) insereEsquerda(vPonteiros[posVetor], pAux, nivel); // Caso a esquerda esteja disponível
			else if (vPonteiros[posVetor]->filho_direita == NULL){ // Caso a direita esteja disponível
                insereDireita(vPonteiros[posVetor++], pAux, nivel); 
                nivel++;
            } 
		}
	}

	addAltura(vPonteiros[0]);

	imprimeArvore(vPonteiros[0]);
	liberaArvore(vPonteiros, 10);

	return 0;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

Arvore* criaNo(int chave) {

	Arvore* novo_no = (Arvore*)malloc(sizeof(Arvore));
	if (novo_no == NULL) exit(1);

	novo_no->chave = chave;
    novo_no->nivel = NULL;
	novo_no->altura = NULL;
	novo_no->filho_esquerda = NULL;
	novo_no->filho_direita = NULL;
	novo_no->pai = NULL;

	printf("-- Nó de chave %d criado --\n\n", chave);

	return novo_no;
}

void insereEsquerda(Arvore* pPai, Arvore* pFilho, int nivel) {
	pPai->filho_esquerda = pFilho;
	pFilho->pai = pPai;
    pFilho->nivel = nivel;
	printf("** Nó de chave %d (nível %d) inserido como filho esquerdo de %d **\n\n", pFilho->chave, pFilho->nivel, pPai->chave);
}

void insereDireita(Arvore* pPai, Arvore* pFilho, int nivel) {
	pPai->filho_direita = pFilho;
	pFilho->pai = pPai;
    pFilho->nivel = nivel;
	printf("** Nó de chave %d (nível %d) inserido como filho direito de %d **\n\n", pFilho->chave, pFilho->nivel, pPai->chave);
}

int getAltura(Arvore* pArvore){
	if (pArvore == NULL) return -1;
	else{
		if (pArvore->filho_esquerda == NULL && pArvore->filho_direita == NULL) return 0;
		else return 1 + max(getAltura(pArvore->filho_esquerda),getAltura(pArvore->filho_direita));
	}
}

void addAltura(Arvore* pArvore){
	if (pArvore == NULL){
		printf("\n\nÁrvore inexistente\n\n");
		return;
	}

	pArvore->altura = getAltura(pArvore);
	
	if (pArvore->filho_esquerda != NULL) addAltura(pArvore->filho_esquerda);
	if (pArvore->filho_direita != NULL) addAltura(pArvore->filho_direita);
}

void imprimeArvore(Arvore* pArvore) {

	if (pArvore == NULL){
		printf("Arvore inexistente\n");
		return;
	}

	printf("Endereço: 0x%p\nChave: %d\nNível: %d\nAltura: %d\nPai: 0x%p\nFilho da esquerda: 0x%p\nFilho da direita: 0x%p\n\n", pArvore, pArvore->chave, pArvore->nivel, pArvore->altura, pArvore->pai, pArvore->filho_esquerda, pArvore->filho_direita);

	if (pArvore->filho_esquerda != NULL) imprimeArvore(pArvore->filho_esquerda);
	if (pArvore->filho_direita != NULL) imprimeArvore(pArvore->filho_direita);
}

void liberaArvore(Arvore** vPonteiros, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		free(vPonteiros[i]);
	}
	printf("++ Vetor esvaziado ++");
}