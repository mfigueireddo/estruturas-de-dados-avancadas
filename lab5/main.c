#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

void soma_um(long *vetor);

int main(void){

    long vetor[1000];

    long aux;
    int indice = 0;

    FILE* arquivo = fopen("cpf_list.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(arquivo, " %ld", &aux) == 1) {
        vetor[indice++] = aux;
    }

    soma_um(vetor);

}