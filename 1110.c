/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 28/08/2026
Objetivo    : Pegar a primeira carta de um baralho e jogar fora, e colocar a segunda no fundo até que sobre só uma carta
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

// Definição de estrutura carta
typedef struct Carta{
    int valor;
    struct Carta *baixo; 
} TCarta;

// F. Criar carta
TCarta* criar_carta(int v){
    TCarta *C = (TCarta *) malloc(sizeof(TCarta));
    if (C != NULL){
        C->valor = v;
        C->baixo = NULL;
    }
    return C;
}

// F. Criar baralho
TCarta* criar_baralho(TCarta *baralho, int n){
    int i;
    for (i = n; i > 0; i--){
        TCarta *nova = criar_carta(i);
        nova->baixo = baralho;
        baralho = nova;
    }
    return baralho;
}

// F. Remover carta do baralho
TCarta* remover_carta(TCarta* baralho, int *valor_rm){
    if (baralho == NULL) return NULL;

    TCarta* aux = baralho->baixo;
    *valor_rm = baralho->valor;
    free(baralho);
    return aux;
}

// F. Navegar até ultima carta
TCarta* ultima_carta(TCarta* baralho){
    if (baralho == NULL || baralho->baixo == NULL) return baralho;

    TCarta *aux = baralho;
    TCarta *topo = baralho;

    while (aux->baixo != NULL){
        aux = aux->baixo;
    }
    baralho = topo->baixo;
    aux->baixo = topo;
    topo->baixo = NULL;
    return baralho;
}

int main(){
    int n, i;

    // Processamento
    while (scanf("%d", &n) == 1 && n != 0){
        TCarta *pbar = NULL;
        pbar = criar_baralho(pbar, n);
        
        int *valores_rm = (int *) malloc(n * sizeof(int));

        for (i = 0; pbar->baixo != NULL; i++){
            pbar = remover_carta(pbar, &valores_rm[i]);
            pbar = ultima_carta(pbar);
        }

        printf("Discarded cards:");
        for (i = 0; i < n - 1; i++){
            if (i == 0) printf(" %d", valores_rm[i]); 
            else printf(", %d", valores_rm[i]);
        }
        printf("\n");
        
        printf("Remaining card: %d\n", pbar->valor);

        // Liberação de memória
        free(pbar);
        free(valores_rm);
    }

    return 0;
}