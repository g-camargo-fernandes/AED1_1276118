/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 27/08/2026
Objetivo    : Verificar um tabuleiro sudoku usando matriz de ponteiros
Dificuldade : Implementar a lógica de ponteiros
Uso de IA   : Na primeira versão sem ponteiros, utilizei IA para revisar erros de sintaxe que havia esquecido nas férias, 
e também para o desenvolvimento de parte da lógica de verificação de linhas.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Matriz M global para que todas as funções possam analizá-la
int **M;

// F. Processamento de entrada na matriz
void criar_mtr(){
    for (int i = 0; i < 9; i++){
        scanf("%i %i %i %i %i %i %i %i %i", &M[i][0], &M[i][1], &M[i][2], &M[i][3], &M[i][4], &M[i][5], &M[i][6], &M[i][7], &M[i][8]);
    }
}

// F. Verificação de vertical
int verif_vert(int col){
    int visto[10] = {0}, num;

    for(int i = 0; i < 9; i++){
        num = M[i][col];
    
        if (num < 1 || num > 9 || visto[num] == 1)
            return 0;
        else
            visto[num] = 1;
    } 
    return 1; 
}

// F. Verificação de horizontal
int verif_hor(int lin){
    int visto[10] = {0}, num;

    for(int i = 0; i < 9; i++){
        num = M[lin][i];
    
        if (num < 1 || num > 9 || visto[num] == 1)
            return 0;
        else
            visto[num] = 1;
    } 
    return 1; 
}

// F. Verificação de quadrados internos 3x3
int verif_quadr(int i_inicio, int j_inicio){
    int visto[10] = {0}, i, j, num;

    for (i = i_inicio; i < i_inicio + 3; i++){
        for (j = j_inicio; j < j_inicio + 3; j++){
            num = M[i][j];
            
            if (num < 1 || num > 9 || visto[num] == 1){
                return 0;
            }

            visto[num] = 1;
        }
    }
    return 1;
    
}
int main(){
    // Declaração de variáveis
    int i, m, k, n;
    
    // Criação de M[][]
    M = (int **) malloc(9 * sizeof(int *));
    if (M == NULL){
        printf("Erro de alocação\n");
        return 1;
    }
    for (i = 0; i < 9; i++){
        M[i] = (int *) malloc(9 * sizeof(int));
        if (M[i] == NULL){
            printf("Erro de alocacao\n");
            return 1; 
        }
    }

    // Processamento de entrada
    scanf("%d", &n);
    int resultados[n];
    for (k = 0; k < n; k++){
        resultados[k] = 1;
        criar_mtr();
        
        // Análise de entradas com as funções específicas
        for (m = 0; m < 9 && resultados[k] == 1; m++){
            resultados[k] = verif_hor(m);
        }
        for (m = 0; m < 9 && resultados[k] == 1; m++){
            resultados[k] = verif_vert(m);
        }
        for (m = 0; m < 9 && resultados[k] == 1; m++){
            resultados[k] = verif_quadr((m % 3) * 3, (m / 3) * 3); 
        }

        // Impressão do resultado
        printf("Instancia %d\n", k + 1);
        if (resultados[k] == 1)
            printf("SIM\n\n");
        else 
            printf("NAO\n\n");
    }

    // Liberação da memória alocada da matriz M
    for (i = 0; i < 9; i++){
        free(M[i]);
    }
    free(M);
    return 0;
}
