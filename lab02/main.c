#include <stdio.h>
#include <stdlib.h>

struct Paciente{
  int id;
  char cor;
  struct Paciente* proximo;
};

typedef struct Paciente Paciente;

Paciente* inserePaciente(Paciente* lista, int id, char cor);
void imprimeLista(Paciente* lista);
void removeLista(Paciente** lista, int id);
void liberaLista(Paciente* lista);

int main(void){
  
  FILE* arq_entrada;
  int qtdArgs, idAux;
  char charAux, tipo;
  
  Paciente* lista = NULL;
  
  arq_entrada = fopen("entrada.txt","r");
  
  while(!feof(arq_entrada)){
    qtdArgs = fscanf(arq_entrada, " %c %d %c\n", &tipo, &idAux, &charAux);
    if (qtdArgs != 3) exit(1);
    if (tipo == 'E'){
      lista = inserePaciente(lista,idAux,charAux);
      imprimeLista(lista);
    }
    else if (tipo == 'S'){
      removeLista(&lista,idAux);
      imprimeLista(lista);
    }
  }
  
  liberaLista(lista);
  fclose(arq_entrada);
  
  return 0;
}

Paciente* inserePaciente(Paciente* lista, int id, char cor){
  
  Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
  if (novoPaciente == NULL) exit(1);
  novoPaciente->id = id;
  novoPaciente->cor = cor;
  
  if (lista==NULL)lista = novoPaciente;
  else{
    Paciente* p = lista;
    Paciente* aux = NULL;
    for(;p!=NULL;p=p->proximo){
      if ((p->cor == 'Y' && cor == 'R') || (p->cor == 'G' && (cor == 'R' || cor == 'Y'))){
        if (aux == NULL){
          novoPaciente->proximo = lista;
          lista = novoPaciente;
        }
        else{
          aux->proximo = novoPaciente;
          novoPaciente->proximo = p;
        }
        printf("*PACIENTE %d %c INSERIDO*\n",id,cor);
        return lista;
      }
      aux = p;
    }
    aux->proximo = novoPaciente;
    novoPaciente->proximo = NULL;
  }
  
  printf("*PACIENTE %d %c INSERIDO*\n",id,cor);
  
  return lista;
}

void imprimeLista(Paciente* lista){
  for(Paciente* p = lista; p != NULL; p=p->proximo){
    printf("Id: %d\tCor: %c\n", p->id, p->cor);
  }
}

void removeLista(Paciente** lista, int id){
  Paciente* p = *lista;
  Paciente* aux = NULL;
  for(; p!=NULL; p=p->proximo){
    if (p->id == id) break;
    aux = p;
  }
  if (p == NULL) printf("*PACIENTE NÃO ENCONTRADO\n");
  else{
    if (aux == NULL) *lista = (*lista)->proximo;
    else aux->proximo = p->proximo;
    free(p);
    printf("*PACIENTE %d REMOVIDO*\n", id);
  }
}

void liberaLista(Paciente* lista){
  Paciente* p = lista;
  Paciente* aux;
  while(p!=NULL){
    aux = p->proximo;
    free(p);
    p = aux;
  }
  printf("*LISTA LIBERADA*\n");
}