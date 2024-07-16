#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int n){
for(int i = 0; i < n; i++) {
    printf("%d ",vetor[i]);
}
}

void multiplica(int vetor[], int n, double v){
    for (int i = 0; i < n; i++){
        vetor[i] = vetor[i] * v;
    }
    


}

int main(){
    int tamanho_vetor;
    scanf("%d", &tamanho_vetor);
    
    int vetor[tamanho_vetor];
    for (int i = 0; i < tamanho_vetor; i++)
    {
        scanf("%d", &vetor[i]);
    }

    double multiplicar;
    scanf("%lf", &multiplicar);

    imprime(vetor, tamanho_vetor);

    multiplica(vetor, tamanho_vetor, multiplicar);

    imprime(vetor, tamanho_vetor);

    multiplicar = 1/multiplicar;

    multiplica(vetor, tamanho_vetor, multiplicar);

    imprime(vetor, tamanho_vetor);
    
 return 0;   
}