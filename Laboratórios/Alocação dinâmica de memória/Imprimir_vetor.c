#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int *p, int x){
    for(int i = 0; i < x; i++){
        scanf("%d", &p[i]);
    }


}

int main(){
int tamanho_vetor;
scanf("%d", &tamanho_vetor);

int *vetor;
vetor = (int *) malloc(tamanho_vetor * sizeof(int));
if(vetor == NULL){
    printf("Memoria insuficiente!");
    exit(1);
}
ler_vetor(vetor, tamanho_vetor);
for(int j = 0; j < tamanho_vetor; j++){
    printf("%d\n", vetor[j]);
}
    free(vetor);

    return 0;
}