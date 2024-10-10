#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000

int* geraAleatorios(int tamanho);
void imprimeVetor(int* vetor, int tamanho);
void ordenaVetor(int* vetor);
void buscaInteiro(int* fonte, int tamanhoFonte, int* procurados, int tamanhoProcurados);
void buscaBinaria(int* vetor, int tamanho, int procurado);
int comparaInteiros(int inteiro1, int inteiro2);

int main(void){
  int* fonte;
  int* procurados;
  
  fonte = geraAleatorios(TAMANHO);
  procurados = geraAleatorios(TAMANHO);
  ordenaVetor(fonte);
  
  // printf("Fonte:\n");
  // imprimeVetor(fonte, TAMANHO);
  
  // printf("Procurados:\n");
  // imprimeVetor(procurados, TAMANHO);
  
  buscaInteiro(fonte, TAMANHO, procurados, TAMANHO);
  
  free(fonte);
  free(procurados);

  return 0;
}

int* geraAleatorios(int tamanho){
  int i;
  int* aleatorios;
  aleatorios = (int*)malloc(sizeof(int)*tamanho);
  for(i=0; i<tamanho; i++){
    aleatorios[i] = rand() % tamanho;
  }
  return aleatorios;
}

void imprimeVetor(int* vetor, int tamanho){
  int i;
  for(i=0; i<tamanho; i++){
    printf("%d\n", vetor[i]);
  }
  printf("\n");
  return;
}

void ordenaVetor(int* vetor){
  int i, j, auxiliar;
  for(i=0; i<TAMANHO; i++){
    for(j=0; j<TAMANHO; j++){
      if (vetor[i]<vetor[j]){
        auxiliar = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = auxiliar;
      }
    }
  }
  return;
}

void buscaInteiro(int* fonte, int tamanhoFonte, int* procurados, int tamanhoProcurados){
  int i;
  clock_t start, end;
  double tempo;
  start = clock();
  for(i=0; i<tamanhoProcurados; i++){
    // printf("Procurando %d\n", procurados[i]);
    buscaBinaria(fonte, tamanhoFonte, procurados[i]);
  }
  end = clock();
  tempo = (double)(end-start) / CLOCKS_PER_SEC;
  printf("Tempo de busca: %.10f segundos\n\n", tempo);
  return;
}

void buscaBinaria(int* vetor, int tamanho, int procurado){
  int inicio, meio, fim, resultado;
  inicio = 0;
  meio = 0;
  fim = tamanho-1;
  while(meio<=fim){
    meio = (inicio+fim)/2;
    resultado = comparaInteiros(procurado, vetor[meio]);
    if (resultado == -1) fim = meio-1;
    else if(resultado == 1) inicio = meio+1;
    else{
      printf("%d encontrado\n", procurado);
      return;
    }
  }
  // printf("%d não encontrado\n", procurado);
  return;
}

int comparaInteiros(int inteiro1, int inteiro2){
  if(inteiro1 == inteiro2) return 0;
  else if(inteiro1 < inteiro2) return -1;
  else return 1;
}