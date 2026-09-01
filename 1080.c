/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 15/08/2026
Objetivo    : Identificar maior elemento de um vetor
Dificuldade : Relembrar sintaxe da linguagem C
Uso de IA   : Não utilizei
-------------------------------------------------------------------------- */
#include <stdio.h>

int main(){
    // Definicao de variaveis
    int x, maior = -9999999, posm = -1;
    for (int i = 0; i < 100 ; i++){
        // Processamento de input
        scanf("%d", &x);
        if (x > maior){
            maior = x;
            posm = i + 1;
        }
    }
    // Impressao dos resultados
    printf("%d\n", maior);
    printf("%d\n", posm);
    return 0;
}