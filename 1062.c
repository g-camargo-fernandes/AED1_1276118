/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 01/10/2026
Objetivo    : Testar possibilidades de organização de trens em estação
Dificuldade : Lidar com várias entradas sequenciais.
Uso de IA   : Usei para conectar o input com o mecanismo que o beecrowd explicou sobre qual vagão vem primeiro. 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Nó
typedef struct NO{
    int a;
    struct NO* baixo;
}TNO;

// Função push (colocar no topo da pilha)
TNO* push(TNO* topo, int c){
    TNO* novo = (TNO*) malloc(sizeof(TNO));
    if (novo == NULL){
        return topo;
    }
    novo->baixo = topo;
    topo = novo;
    novo->a = c;
    return topo;
}

// Função pop (tirar do topo da pilha)
TNO* pop(TNO* topo){
    if (topo == NULL) return topo;
    TNO* aux = topo;
    topo = topo->baixo;
    free(aux);
    return topo;
}

// Função de liberar memória alocada
TNO* limpar_pilha(TNO* topo){
    while (topo != NULL){
        TNO *aux;
        aux = topo;
        topo = topo->baixo;
        free(aux);
    }
    return NULL;
}


int main(){
    int N;

    // Verificacação de todos os testes de um dado N;
    while (scanf("%d", &N) == 1 && N != 0){  
        int saida[N];

        // Verificação de uma permutação individual
        while (1){
            scanf("%d", &saida[0]);
            if (saida[0] == 0) {
                printf("\n");
                break;
            }

            // Leitura de toda a permutação
            for (int i = 1; i < N; i++){
                scanf("%d", &saida [i]);
            }
            
            TNO* topo_p = NULL;
            int v_atual = 1;
            int possivel = 1;

            // Análise de uma única permutação
            for (int i = 0; i < N; i++){
                if (topo_p != NULL && saida[i] == topo_p->a ){
                    topo_p = pop(topo_p);

                } else {
                    while (v_atual <= N && (topo_p == NULL || saida[i] != topo_p->a)){
                        topo_p = push(topo_p, v_atual);
                        v_atual++;
                    }

                    if (topo_p != NULL && saida[i] == topo_p->a) {
                        topo_p = pop(topo_p);

                    } else if (v_atual > N){
                        printf("No\n");
                        possivel = 0;
                        break;

                    }
                }
            }
            if (possivel == 1) printf("Yes\n");
            topo_p = limpar_pilha(topo_p);
        }
    }
    return 0;   
}