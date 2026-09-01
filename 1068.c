/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 01/09/2026
Objetivo    : Identificar o fechamento correto de parênteses em uma expressão algébrica
Dificuldade : Criar a lógica usando pilhas
Uso de IA   : Usei para simplificar a lógica inicial que havia pensado e no final, para corrigir erros de processamento de strings em C.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

// Definicao estrutura pilha
typedef struct tpilha{
    struct tpilha *baixo;
}TParen;

// F. Abertura de parenteses, cria novo elemento na pilha
TParen* abrir_parentese(TParen* pilha){
    TParen *novo = (TParen *) malloc(sizeof(TParen));
    if (pilha == NULL){
        pilha = novo;
        novo->baixo = NULL;
        return pilha;

    } else {
        novo->baixo = pilha;
        pilha = novo;
        return pilha;
    }
}

// F. Fechamento de parenteses, descarta elemento existente da pilha
TParen *fechar_parentese(TParen* pilha, int *pctrl){
    if (pilha == NULL) {
        *pctrl = 1;
        return NULL;
    } else {
        TParen *topo;
        topo = pilha;
        pilha = pilha->baixo;
        free(topo);
        return pilha;
    }
}

// Libera todo o restante da pilha 
void liberar_pilha(TParen *pilha){
    TParen *atual = pilha;
    while (atual != NULL){
        TParen *prox = atual->baixo;
        free(atual);
        atual = prox;
    }
}

// F. Execucao. Executa cada função de acordo com caracter de entrada
TParen* run_code(TParen *pilha, char c, int *pctrl){
    if (c == '('){
        pilha = abrir_parentese(pilha);
    } else if (c == ')'){
        pilha = fechar_parentese(pilha, pctrl);
    }
    return pilha;
}

int main(){
    // Definicao de variáveis
    char v[1001] = {};
    TParen *pilha = NULL;
    int j = 0;
    
    // Loop externo, exeecuta até que não aja mais inputs no buffer.
    while (fgets(v, sizeof(v), stdin) != NULL) {
        pilha = NULL;
        int controle = 0;
        int *pcontrole = &controle;

        for (int i = 0; v[i] != '\0'; i++){
            pilha = run_code(pilha, v[i], pcontrole);
        }

        // Processamento da resposta de saída
        if (pilha == NULL && *pcontrole != 1){
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        
        j++;
        // Liberação de memória da pilha restante para nova iteração.
        liberar_pilha(pilha);
    }
    return 0;
}