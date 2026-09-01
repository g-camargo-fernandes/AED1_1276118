#include <stdio.h>

int main(){
    int x, maior = -9999999, posm = -1;
    for (int i = 0; i < 100 ; i++){
        scanf("%d", &x);
        if (x > maior){
            maior = x;
            posm = i + 1;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posm);
    return 0;
}
