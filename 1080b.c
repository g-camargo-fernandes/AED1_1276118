/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Identificar maior elemento de um vetor
Dificuldade : Incorporar ponteiros e alocação dinâmica
Uso de IA   : Utilizei para compreender melhor a alocação dinâmica
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(){
    // Definição de variáveis
    int maior = -9999999, posm = -1;
    int *vetor;
    vetor = (int *) malloc(100 * sizeof(int));

    // Processamento de dados
    for (int i = 0; i < 5 ; i++){
        scanf("%d", &vetor[i]);
        if (vetor[i] > maior){
            maior = vetor[i];
            posm = i + 1;
        }
    }

    // Impressao dos resultados
    printf("\n\n%d\n", maior);
    printf("%d\n", posm);
    
    // Liberacao de memória
    free(vetor);
    return 0;
}