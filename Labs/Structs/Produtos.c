#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char marca[50];
    float preco;
} Produto;

int main() {
    Produto produtos[8];
    char nome[50];
    char marca[50];
    float preco;
    int totalProdutos = 0;
    float precoTotal = 0.0;
    int contagemMarcas[8] = {0}; // Para contar produtos por marca
    char marcas[8][50]; // Para armazenar marcas únicas
    int numMarcas = 0; // Número de marcas únicas

    // Leitura dos produtos
    for (int i = 0; i < 8; i++) {
        scanf("%s %s %f", nome, marca, &preco);
        strcpy(produtos[i].nome, nome);
        strcpy(produtos[i].marca, marca);
        produtos[i].preco = preco;
        precoTotal += produtos[i].preco;
        totalProdutos++;

        // Verifica se a marca já foi registrada
        int marcaExistente = 0;
        for (int j = 0; j < numMarcas; j++) {
            if (strcmp(marcas[j], marca) == 0) {
                contagemMarcas[j]++;
                marcaExistente = 1;
                break;
            }
        }
        // Se a marca não foi registrada, adiciona nova marca
        if (!marcaExistente) {
            strcpy(marcas[numMarcas], marca);
            contagemMarcas[numMarcas]++;
            numMarcas++;
        }
    }

    // Calcula a média total
    float mediaTotal = precoTotal / totalProdutos;

    // Calcula a média por marca
    float mediaPorMarca[8] = {0.0};
    for (int i = 0; i < numMarcas; i++) {
        float somaPrecoMarca = 0.0;
        int contagemProdutosMarca = 0;
        for (int j = 0; j < 8; j++) {
            if (strcmp(produtos[j].marca, marcas[i]) == 0) {
                somaPrecoMarca += produtos[j].preco;
                contagemProdutosMarca++;
            }
        }
        mediaPorMarca[i] = somaPrecoMarca / contagemProdutosMarca;
    }

    // Imprime o número de produtos por marca
    for (int i = 0; i < numMarcas; i++) {
        printf("%s %d\n", marcas[i], contagemMarcas[i]);
    }

    // Imprime a média total
    printf("media total %.2f\n", mediaTotal);

    // Imprime a média por marca
    for (int i = 0; i < numMarcas; i++) {
        printf("media %s %.2f\n", marcas[i], mediaPorMarca[i]);
    }

    return 0;
}