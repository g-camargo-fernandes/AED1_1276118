/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 12/11/2026
Objetivo    : Imprimir operações em árvores binárias
Dificuldade : Estruturar a saída esperada pelo Beecrowd
Uso de IA   : Usei para revisar o código e apontar erros na leitura do beecrowd
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definição de estrutura da árvore
typedef struct no {
    char info;
    struct no *e;
    struct no *d;
} Tno;

// Função inserir
Tno * inserir (Tno * arv, char c){

    // Criação da árvore
    if (arv == NULL){
        Tno * novo = (Tno *) malloc (sizeof(Tno));
        if (novo == NULL) return NULL;  
        novo->info = c;
        novo->e = NULL;
        novo->d = NULL;
        return novo;
    }

    // Inserção nas subárvores 
    if (c < arv->info) {
        arv->e = inserir (arv->e, c);
    } else if (c > arv->info) {
        arv->d = inserir (arv->d, c);
    }

    return arv;
}


// Função prefixa
void sub_prefix (Tno *arv, int *ordem){
    if (arv == NULL) {
        return;
    }
    if (*ordem != 0){
        printf(" ");
    }

    printf("%c", arv->info);
    (*ordem)++;

    sub_prefix (arv->e, ordem);
    sub_prefix (arv->d, ordem);
}

// Função que organiza a saída da função prefixa
void prefix (Tno * arv) {
    int ordem = 0;
    sub_prefix (arv, &ordem);
    printf("\n");
}


// Função infixa
void sub_infixa (Tno *arv, int *ordem){
    if (arv == NULL) return;

    sub_infixa (arv->e, ordem);
    if (*ordem != 0){
        printf(" ");
    }
    printf("%c", arv->info);
    (*ordem)++;

    sub_infixa (arv->d, ordem);
}

// Função que organiza a saída da função infixa
void infix (Tno* arv){
    int ordem = 0;
    sub_infixa (arv, &ordem);
    printf("\n");
}

// Função Posfixa
void sub_posfix (Tno* arv, int *ordem){
    if (arv == NULL){
        return;
    }
    sub_posfix (arv->e, ordem);
    sub_posfix (arv->d, ordem);

    if (*ordem != 0){
        printf(" ");
    }
    printf("%c", arv->info);
    (*ordem)++;
}

// Função que organiza a saída da função posfixa
void posfix (Tno* arv){
    int ordem = 0;
    sub_posfix (arv, &ordem);
    printf("\n");
}

// Função de busca
int sub_busca (Tno *arv, char c){
    int a;

    if (arv == NULL) return 0;
    if (arv->info == c){
        printf("%c existe\n", c);
        return 1;
    } else {
        if (c < arv->info){
            a = sub_busca (arv->e, c);
        } else {
            a = sub_busca (arv->d, c);
        }
        return a;
    }
}

// Função que organiza a saída da função de busca
void busca (Tno *arv, char c){
    int r = sub_busca(arv, c);
    if (r == 1) return;
    else printf("%c nao existe\n", c);
}

// Função que libera memória alocada pela árvore 
void liberar (Tno* arv){
    if (arv == NULL) return;
    liberar (arv->e);
    liberar (arv->d);
    free (arv);
}

int main (){
    char c[20];
    Tno *arv = NULL;

    // Loop de processamento
    while (fgets(c, sizeof(c), stdin) != NULL){

        c[strcspn(c, "\r\n")] = '\0';

        // INSERIR
        if (c[0] == 'I' && c[1] == ' '){
            arv = inserir (arv, c[2]); 
        }

        // BUSCA
        else if (c[0] == 'P' && c[1] == ' '){
            busca(arv, c[2]);
        }
        
        // INFIXA
        else if (strcmp(c, "INFIXA") == 0){
            infix(arv);
        }

        // POSFIXA
        else if (strcmp(c, "POSFIXA") == 0){
            posfix(arv);
        }

        // PREFIXA
        else if (strcmp(c, "PREFIXA") == 0){
            prefix(arv);
        }
       
    }
    
    // Liberação da memória
    liberar (arv);
    return 0;
}