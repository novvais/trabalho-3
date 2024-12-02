#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

int main() {
    int capacity = 100;
    Inventory inventory = createInventory(capacity);
    int option;
    char category[50], name[50];
    double price;
    int stock;

    while (1) {
        printf("\n--- Menu de opcoes ---\n\n");
        printf("1. Adicionar produto\n");
        printf("2. Apresentar produtos por categoria (ordem alfabetica)\n");
        printf("3. Apresentar produtos por categoria (menor preco)\n");
        printf("4. Verificar produtos com estoque baixo\n");
        printf("5. Buscar produto pelo nome\n");
        printf("6. Sair\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]%*c", name); 

                printf("Digite a categoria do produto: ");
                scanf(" %[^\n]%*c", category);  

                printf("Digite o preco do produto: ");
                scanf("%lf", &price);

                printf("Digite a quantidade em estoque: ");
                scanf("%d", &stock);

                Product product;
                strcpy(product.name, name);
                strcpy(product.category, category);
                product.price = price;
                product.stock = stock;

                addProduct(&inventory, product);

                break;
            
            case 2:
                printf("Digite a categoria para ordenar por nome: ");
                scanf(" %[^\n]%*c", category);

                printf("\n");

                displayByCategory(&inventory, category);

                break;

            case 3:
                printf("Digite a categoria para ordenar por preco: ");
                scanf(" %[^\n]%*c", category);

                printf("\n");

                displayByCategoryPrice(&inventory, category);

                break;

            case 4:
                checkStock(&inventory);

                break;

            case 5:
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]%*c", name);  // Captura nome com espaços

                // Buscar o produto usando busca linear
                int result = searchProduct(&inventory, name);

                if (result != -1) {
                    printf("Produto encontrado:\n");
                    printf("  Nome: %s\n", inventory.products[result].name);
                    printf("  Categoria: %s\n", inventory.products[result].category);
                    printf("  Preco: R$ %.2f\n", inventory.products[result].price);
                    printf("  Quantidade em estoque: %d\n", inventory.products[result].stock);
                } else {
                    printf("Produto nao encontrado.\n");
                }

                break;

            case 6:
                printf("Saindo...");

                free(inventory.products);

                return 0;

            default:
                printf("Opcao invalida! Tente novamente.\n");

                break;
        }
    }

    return 0;
}
