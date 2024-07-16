#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    float comprimento_sepala; // Q_x
    float largura_sepala;     // Q_y
    float comprimento_petala; // P_x
    float largura_petala;     // P_y
    char tipo[50];
    float distancia;
} Iris;

void calcular_distancia_identificadas(Iris registros_identificados[], int num_flores, Iris nao_identificada) { //calcula a distancia entre as flores identificadas e a nao identificada
    for (int i = 0; i < num_flores; i++) {
        float subtracao_comp = registros_identificados[i].comprimento_sepala - nao_identificada.comprimento_sepala;
        float subtracao_lar = registros_identificados[i].largura_sepala - nao_identificada.largura_sepala;
        registros_identificados[i].distancia = sqrt((subtracao_comp * subtracao_comp) + (subtracao_lar * subtracao_lar));
    }
}

int main() {
    int num_flores;
    scanf("%d", &num_flores);

    Iris registros_identificados[num_flores];
    for (int i = 0; i < num_flores; i++) { // absorve uma lista de flores
        scanf("%f", &registros_identificados[i].comprimento_sepala);
        scanf("%f", &registros_identificados[i].largura_sepala);
        scanf("%f", &registros_identificados[i].comprimento_petala);
        scanf("%f", &registros_identificados[i].largura_petala);
        getchar(); // remove o '\n' restante no buffer
        fgets(registros_identificados[i].tipo, sizeof(registros_identificados[i].tipo), stdin);
        registros_identificados[i].tipo[strcspn(registros_identificados[i].tipo, "\n")] = '\0';
    }
    
    Iris nao_identificada; // absorve uma flor não identificada
    scanf("%f", &nao_identificada.comprimento_sepala);
    scanf("%f", &nao_identificada.largura_sepala);
    scanf("%f", &nao_identificada.comprimento_petala);
    scanf("%f", &nao_identificada.largura_petala);
    
    calcular_distancia_identificadas(registros_identificados, num_flores, nao_identificada);

    float menor_distancia = registros_identificados[0].distancia;
    int indice_menor_distancia = 0;
    for (int i = 1; i < num_flores; i++) { // procura qual o tipo de flor tem a menor distancia
        if (registros_identificados[i].distancia < menor_distancia) {
            menor_distancia = registros_identificados[i].distancia;
            indice_menor_distancia = i;
        }
    }

    printf("%s\n", registros_identificados[indice_menor_distancia].tipo);

    return 0;
}