#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    unsigned int idade;
    float salario;
    char rua[50];
    unsigned int numero;
    char estado[50];
} cadastro;

int main() {
    cadastro cad[5];
    char comando[10];
    char nome[50];
    unsigned int idade;
    float salario;
    char rua[50];
    unsigned int numero;
    char estado[50];
    
    int controleDeEspaco = 0;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            scanf("%s %u %f %s %u %s", nome, &idade, &salario, rua, &numero, estado);
            if (controleDeEspaco < 5) {
                strcpy(cad[controleDeEspaco].nome, nome);
                cad[controleDeEspaco].idade = idade;
                cad[controleDeEspaco].salario = salario;
                strcpy(cad[controleDeEspaco].rua, rua);
                cad[controleDeEspaco].numero = numero;
                strcpy(cad[controleDeEspaco].estado, estado);
                printf("Registro %s %u %.2f %s %u %s inserido\n", nome, idade, salario, rua, numero, estado);
                controleDeEspaco++;
            } else {
                printf("Espaco insuficiente\n");
            }
        } else if (strcmp(comando, "mostrar") == 0) {
            scanf("%s", nome);
            int encontrado = 0;
            for (int i = 0; i < 5; i++) {
                if (strcmp(cad[i].nome, nome) == 0) {
                    printf("Registro %s %u %.2f %s %u %s\n", cad[i].nome, cad[i].idade, cad[i].salario, cad[i].rua, cad[i].numero, cad[i].estado);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Registro ausente\n");
            }
        } else if (strcmp(comando, "alterar") == 0) {
            scanf("%s", nome);
            int encontrado2 = 0;
            for (int i = 0; i < 5; i++) {
                if (strcmp(cad[i].nome, nome) == 0) {
                    // Lê os novos dados, mas não altera o nome
                    scanf("%u %f %s %u %s", &idade, &salario, rua, &numero, estado);
                    cad[i].idade = idade;
                    cad[i].salario = salario;
                    strcpy(cad[i].rua, rua);
                    cad[i].numero = numero;
                    strcpy(cad[i].estado, estado);
                    printf("Registro %s %u %.2f %s %u %s alterado\n", cad[i].nome, cad[i].idade, cad[i].salario, cad[i].rua, cad[i].numero, cad[i].estado);
                    encontrado2 = 1;
                    break;
                }
            }
            if (!encontrado2) {
                printf("Registro ausente para alteracao\n");
            }
        } 
    }

    return 0;
}