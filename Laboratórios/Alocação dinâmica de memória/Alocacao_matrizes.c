#include <stdio.h>
#include <stdlib.h>

int main(){
int qtd_linhas, qtd_colunas;
scanf("%d", &qtd_linhas);
scanf("%d", &qtd_colunas);

int **matriz;
matriz = (int **)calloc(qtd_linhas,sizeof(int *));
for(int i = 0; i < qtd_linhas; i++){
    matriz[i] = (int *)calloc(qtd_colunas,sizeof(int));
    for(int j = 0; j < qtd_colunas; j++){
        scanf("%d", &matriz[i][j]);
    }
}
for(int i = 0; i < qtd_linhas; i++){
    for(int j = 0; j < qtd_colunas; j++){
        printf("%d ", matriz[i][j]);
    }
}
for(int i = 0; i < qtd_linhas; i++) free(matriz[i]);

free(matriz);
    return 0;
}