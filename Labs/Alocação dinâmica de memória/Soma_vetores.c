#include <stdlib.h>
#include <stdio.h>
void soma(int *v1, int *v2, int *v3, int n){
for(int i = 0; i < n; i++){
    v3[i] = v1[i] + v2[i];
}
}


int main(){ //aloquei memória de 3 maneiras diferentes para fins de aprendizagem e teste
    int tamanho_vetores;
    scanf("%d", &tamanho_vetores);
    int *vetor1, *vetor2, *vetor3;
    vetor1 = (int *)malloc(tamanho_vetores*sizeof(int));
    for(int i = 0; i < tamanho_vetores; i++){
        scanf("%d",&vetor1[i]);
    }
    vetor2 = (int *)calloc(tamanho_vetores,sizeof(int));
    for(int i = 0; i < tamanho_vetores; i++){
        scanf("%d",&vetor2[i]);
    }
    vetor3 = (int *)realloc(NULL,tamanho_vetores*sizeof(int));

    soma(vetor1, vetor2, vetor3, tamanho_vetores);
    for(int i = 0; i < tamanho_vetores; i++) printf("%d\n", vetor3[i]);

    free(vetor1);
    free(vetor2);
    free(vetor3);
    return 0;
}