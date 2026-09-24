/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Camargo Fernandes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 24/09/2026
Objetivo    : Realizar busca binária e comparar a distância percorrida pelo carteiro entre casas
Dificuldade : Acertar índices da busca binária
Uso de IA   : Usei para auxiliar no refino da busca binária
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// F: Busca Binária
int buscabin (int *pacote, int casas[], int tam){
    int e = 0, m, d = tam;
    
    while (e < d){
        m = e + (d - e)/2;
        if (casas[m] < *pacote){
            e = m + 1;
        }
        else {
            d = m;
        }
    }
    return e; // Indice referente ao pacote no vetor casas[]
}

// F: Cálculo de passos por busca binária
int calc_passos (int *p0, int *pacote, int casas[], int tam){
    int passo;
    int pos_pacote = buscabin (pacote, casas, tam);
    passo = abs(pos_pacote - *p0);
    *p0 = pos_pacote;
    return passo;
}

int main(){
    int N, M, i; // N (numero das casas); M (qtd pacotes)
    scanf("%d", &N);
    scanf("%d", &M);
    int casas[N], pacotes[M];
    
    // Leitura do input
    for (i = 0; i < N; i++){
        scanf("%d", &casas[i]);
    }
    for (i = 0; i < M; i++){
        scanf("%d", &pacotes[i]);
    }

    // Loop de execução
    int tpassos = 0, pinicial = 0;
    for (i = 0; i < M; i++){
        tpassos += calc_passos (&pinicial, &pacotes[i], casas, N);
    }

    // Impressão do resultado
    printf("%d\n", tpassos);
    return 0;
}