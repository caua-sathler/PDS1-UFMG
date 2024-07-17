#include <stdio.h>
#include <stdlib.h>

int main (){
    int matriz[1000][1000];
    int linhas;
    int colunas;
        scanf("%d", &linhas);
        scanf("%d", &colunas);
            for(int i = 0; i < linhas; i++){
                for(int j = 0; j < colunas; j++){
                        scanf("%d", &matriz[i][j]);
}
}
     int matrizOposta[1000][1000];
     for(int i = 0; i < linhas; i++){
                for(int j = 0; j < colunas; j++){
                        matrizOposta [i][j] = - matriz[i][j];
                        printf("%d\n", matrizOposta[i][j]);
     
} }
return 0; 
}