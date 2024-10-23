#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

void exibe_vetor(long *vetor, int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%ld\n", vetor[i]);
    }
}

void soma_um(long *vetor){

    long hash[TAM];

    for(int i=0; i<TAM; i++){
        hash[i] = -1;
    }

    int indice, colisoes;
    colisoes = 0;

    for(int i=0; i<TAM; i++){
        indice = vetor[i] % TAM;
        while(hash[indice] != -1){
            indice++;
            colisoes++;
            if (indice == TAM){
                indice = 0;
            }
        }
        hash[indice] = vetor[indice];
    }

    exibe_vetor(hash, TAM);

    // printf("Houveram %d colisões com o método soma um.\n\n", colisoes);
}