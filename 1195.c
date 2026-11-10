/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 10/11/2026
Objetivo    : Organizar saída de árvore binária em prefixa, infixa e pósfixa
Dificuldade : Compreender a melhor forma de abordar a manipulação de árvores, fazendo de forma recursiva ou iterativa.
Uso de IA   : Usei para apontamentos acerca da melhor forma de escrever funções de manipulação da árvore e para relembrar as definições de prefixa, infixa e posfixa;
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int info;
    struct no *e;
    struct no *d;
} Tno;

// Função que insere um  número n na árvore;
Tno* inserir(Tno *arv, int n){
    if (arv == NULL){
        Tno* novo = (Tno*) malloc (sizeof(Tno));
        if (novo == NULL) return NULL;
        novo->info = n;
        novo->e = NULL;
        novo->d = NULL;
        return novo;
    }
    
    if (n < arv->info) {
        arv->e = inserir(arv->e, n);
    } else if (n > arv->info) {
        arv->d = inserir(arv->d, n);
    }

    return arv;
}

// F. Libera a memória alocada da árvore
void liberar (Tno* arv){
    if (arv == NULL) return;
    liberar (arv->e);
    liberar (arv->d);
    free (arv);
}

// F. Imprime a organização prefixa da árvore
void prefix (Tno *arv){
    if (arv == NULL){
        return;
    }

    printf(" %d", arv->info);
    prefix(arv->e);
    prefix(arv->d);
}

// F. Imprime a organização infixa da árvore
void infix (Tno *arv){
    if (arv == NULL){
        return;
    }

    infix (arv->e);
    printf(" %d", arv->info);
    infix (arv->d);
}

// F. Imprime a organização posfixa da árvore
void posfix (Tno *arv){
    if (arv == NULL){
        return;
    }
    posfix (arv->e);
    posfix (arv->d);
    printf(" %d", arv->info);
}

// Execução
int main(){
    int C, N;
    scanf("%d", &C);

    for (int k = 0; k < C; k++){
        Tno *arv = NULL;

        scanf("%d", &N);

        printf("Case %d:\n", k + 1);
        for (int i = 0; i < N; i++){
            int n;
            scanf("%d", &n);
            arv = inserir(arv, n);
        }

        // Organização estética exigida pelo exercício
        printf("Pre.:");
        prefix(arv);
        printf("\n");

        printf("In..:");
        infix(arv);
        printf("\n");

        printf("Post:");
        posfix(arv);
        printf("\n\n");  

        // Desalocação da memória da árvore
        liberar (arv);
    }
    return 0;
}