#include <stdio.h>
#include <string.h>

// Definição da struct Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Definição da struct Evento
typedef struct {
    char nome[100];
    char local[100];
    Data data;
} Evento;

// Função para cadastrar eventos
void cadastrar_eventos(Evento agenda[], int n) {
    for (int i = 0; i < n; i++) {
        scanf(" %s", agenda[i].nome);
        scanf(" %s", agenda[i].local);
        scanf("%d", &agenda[i].data.dia);
        scanf("%d", &agenda[i].data.mes);
        scanf("%d", &agenda[i].data.ano);
    }
}

// Função para imprimir eventos em uma data específica
void imprimir_eventos(Evento agenda[], Data data, int n) {
    int encontrado = 0;
    
    for (int i = 0; i < n; i++) {
        if (agenda[i].data.dia == data.dia && agenda[i].data.mes == data.mes && agenda[i].data.ano == data.ano) {
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("Nenhum evento encontrado!\n");
    }
}
int main() {
    int n;;
    scanf("%d", &n);

    Evento eventos[n];
    cadastrar_eventos(eventos, n);

    Data dataBusca;
    scanf("%d %d %d", &dataBusca.dia, &dataBusca.mes, &dataBusca.ano);

    imprimir_eventos(eventos, dataBusca, n);

    return 0;
}