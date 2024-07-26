#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
    char estado[3];
} produto; //struct para armanzenar os dados dos produtos

//1 função para gerar relatório
void relatorio_estoque(produto produtos[], int num_produtos_lista, const char *nome_do_arquivo_gerado) {
    produto temp;
    for (int i = 0; i < num_produtos_lista - 1; i++) { //ordena a struct em ordem alfabética através do Bubble Sort
        for (int j = i + 1; j < num_produtos_lista; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    FILE *relatorio = fopen(nome_do_arquivo_gerado, "w"); //gera o arquivo de saída com os produtos
    if (relatorio == NULL) {
        printf("Erro ao gerar arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < num_produtos_lista; i++) { //escreve os produtos em ordem alfabetica no arquivo gerado
        fprintf(relatorio, "%d\n%s\n%d\n%.2f\n%s\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].estado);
    }
    fclose(relatorio);
}
//2 função para pesquisar por código do produto
void pesquisa_por_codigo(produto produtos[], int num_produtos_lista, const char *codigo_produto){
    int codigo_numerico_prod = atoi(codigo_produto); //transforma o código do produto armazenado como char em argv para int
    for (int i = 0; i < num_produtos_lista; i++){
        if(produtos[i].codigo == codigo_numerico_prod){ //com o loop for passa por todos os produtos comparando os codigos. Se for igual, printa na tela o produto pesquisado.
            printf("%d\n%s\n%d\n%.2f\n%s\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].estado);
            break;
        }
    }
}
//3 função para verificar o menor estoque de produto
void dados_menor_estoque(produto produtos[], int num_produtos_lista){
    int menor_estoque = produtos[0].quantidade; //inicializa o menor estoque como o primeiro elemento do array
    int indice_menor_estoque = 0;

    // encontra o índice do produto com menor estoque
    for (int i = 1; i < num_produtos_lista; i++) {
        if (produtos[i].quantidade < menor_estoque) {
            menor_estoque = produtos[i].quantidade;
            indice_menor_estoque = i;
        }
    }

    // imprime os dados do produto com menor estoque
    printf("%d\n%s\n%d\n%.2f\n%s\n",
           produtos[indice_menor_estoque].codigo,
           produtos[indice_menor_estoque].nome,
           produtos[indice_menor_estoque].quantidade,
           produtos[indice_menor_estoque].preco,
           produtos[indice_menor_estoque].estado);
}
//4 função para listar os produtos de cada estado 
void listar_por_estado(produto produtos[], int num_produtos_lista, const char *estado_pesquisado){
    produto temp;
    for (int i = 0; i < num_produtos_lista - 1; i++) { //coloca a lista em ordem alfabetica por Bubble Sort
        for (int j = i + 1; j < num_produtos_lista; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
    for(int w = 0; w < num_produtos_lista; w++){ //passa por todos os produtos verificando se é o estado pesquisado. Se for, imprime o produto.
        if (strcasecmp(produtos[w].estado, estado_pesquisado) == 0){
            printf("%d\n%s\n%d\n%.2f\n%s\n", produtos[w].codigo, produtos[w].nome, produtos[w].quantidade, produtos[w].preco, produtos[w].estado);
        }
    }
}
//5 função para verificar o menor estoque de produto em cada estado
void menor_quantidade_por_estado(produto produtos[], int num_produtos_lista, const char *estado_da_pesquisa){
    int primeiroItem_estado;
    for(int x = 0; x < num_produtos_lista; x++){ //varre a struct buscando o primeiro produto que corresponda ao estado pesquisado, garantindo que o primeiro produto seja do estado desejado e mitiga iterações desnecessárias
        if(strcmp(produtos[x].estado, estado_da_pesquisa) == 0){
            primeiroItem_estado = x;
            break;
        }
    }
    int menorEstoque = produtos[primeiroItem_estado].quantidade; //faz com que o menor estoque seja do primeiro item do estado encontrado
    int menorEstoque_codigo = produtos[primeiroItem_estado].codigo; //guarda o código desse item
    for (int i = primeiroItem_estado + 1; i < num_produtos_lista; i++){ //faz a comparação. Se houver algum estoque daquele estado que seja menor que o inicial, os valores são trocados.
        if(strcmp(produtos[i].estado, estado_da_pesquisa) == 0 && produtos[i].quantidade < menorEstoque){
            menorEstoque = produtos[i].quantidade;
            menorEstoque_codigo = produtos[i].codigo;
        }
    }
    for (int j = primeiroItem_estado; j < num_produtos_lista; j++){
        if(produtos[j].codigo == menorEstoque_codigo){ //imprime o produto com menor estoque do estado pesquisado
            printf("%d\n%s\n%d\n%.2f\n%s\n", produtos[j].codigo, produtos[j].nome, produtos[j].quantidade, produtos[j].preco, produtos[j].estado);
            break;
        }
    }
}
//6 função para somar todos os produtos
void quantidade_total(produto produtos[], int num_produtos_lista){
    int soma = 0;
    for(int i = 0; i < num_produtos_lista; i++){ //soma todos os produtos da lista
        soma += produtos[i].quantidade;
    }
    printf("%d\n", soma); //printa a soma
}

int main(int argc, char *argv[]){

    char *param1 = argv[1];
    char *param2 = argv[2];
    char *param3 = argv[3];

    FILE *arq = fopen(param1, "r"); //abre o arquivo com o nome fornecido em argv[1]
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

   
    char linha[256];
    int num_de_produtos = 0;

    if (fgets(linha, sizeof(linha), arq) != NULL) {
        num_de_produtos = atoi(linha); //lê o primeiro número do arquivo e o transforma em int. Esse número corresponde ao número de produtos do arquivo e é utilizado para evitar iterações desnecessárias
        if (num_de_produtos > 1000) {
            fclose(arq);
            printf("Número de produtos maior que 1000.\n");
            return 1;
        }
    produto *produtos;
    produtos = (produto *) malloc(num_de_produtos*sizeof(produto));

        for (int i = 0; i < num_de_produtos; i++) { //absorve todo conteúdo do arquivo nostruct
            if (fgets(linha, sizeof(linha), arq) != NULL) {
                sscanf(linha, "%d", &produtos[i].codigo);
            }
            if (fgets(linha, sizeof(linha), arq) != NULL) {
                strcpy(produtos[i].nome, linha);
                produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0'; // remove o '\n'
            }
            if (fgets(linha, sizeof(linha), arq) != NULL) {
                sscanf(linha, "%d", &produtos[i].quantidade);
            }
            if (fgets(linha, sizeof(linha), arq) != NULL) {
                sscanf(linha, "%f", &produtos[i].preco);
            }
            if (fgets(linha, sizeof(linha), arq) != NULL) {
                sscanf(linha, "%2s", produtos[i].estado);
            }
        }
        fclose(arq); //fecha o arquivo pois todo seu conteúdo já está dentro do programa

//uso de if statements para verificar qual comando foi dado para argv[2]. O uso de strcmp se dá pois argv armazena tudo como char. Executa a função correspondente ao comando. 
        if (strcmp(param2, "1") == 0) {
            relatorio_estoque(produtos, num_de_produtos, param3);
        } else if (strcmp(param2, "2") == 0) {
            pesquisa_por_codigo(produtos, num_de_produtos, param3);
        } else if (strcmp(param2, "3") == 0) {
            dados_menor_estoque(produtos, num_de_produtos);
        } else if (strcmp(param2, "4") == 0) {
            listar_por_estado(produtos, num_de_produtos, param3);
        } else if (strcmp(param2, "5") == 0) {
            menor_quantidade_por_estado(produtos, num_de_produtos, param3);
        } else if (strcmp(param2, "6") == 0) {
            quantidade_total(produtos, num_de_produtos);
        }
    free(produtos);
    }
    
    return 0;
}