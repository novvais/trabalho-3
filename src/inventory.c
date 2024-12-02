#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

Inventory createInventory(int capacity) {
    Inventory inventory;
    inventory.products = malloc(10 * sizeof(Product));
    inventory.quantity = 0;
    inventory.capacity = capacity;

    return inventory;
}

void addProduct(Inventory *inventory, Product product) {
    if (inventory->quantity >= inventory->capacity) {
        printf("Inventario cheio!");

        return;
    } 

    inventory->products = realloc(inventory->products, inventory->capacity * sizeof(Product));

    strcpy(inventory->products[inventory->quantity].name, product.name);
    
    strcpy(inventory->products[inventory->quantity].category, product.category);

    inventory->products[inventory->quantity].price = product.price;

    inventory->products[inventory->quantity].stock = product.stock;

    inventory->quantity++;
}

void displayByCategory(Inventory *inventory, const char *category) {
    int count = 0;

    for (int i = 0; i < inventory->quantity; i++) {
        if (strcmp(inventory->products[i].category, category) == 0) {
            if (i != count) {
                Product temp = inventory->products[count];
                inventory->products[count] = inventory->products[i];
                inventory->products[i] = temp;
            }
            count++;
        }
    }

    if (count == 0) {
        printf("Nenhum produto encontrado na categoria '%s'.\n", category);
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcasecmp(inventory->products[j].name, inventory->products[j + 1].name) > 0) {
                Product temp = inventory->products[j];
                inventory->products[j] = inventory->products[j + 1];
                inventory->products[j + 1] = temp;
            }
        }
    }

    printf("Produtos da categoria '%s' ordenados por nome:\n\n", category);
    for (int i = 0; i < count; i++) {
        printf("Produto: %s | Preco: %.2f | Estoque: %d\n",
               inventory->products[i].name,
               inventory->products[i].price,
               inventory->products[i].stock);
    }
}

void displayByCategoryPrice(Inventory *inventory, const char *category) {
    for (int i = 0; i < inventory->quantity - 1; i++) {
        for (int j = i + 1; j < inventory->quantity; j++) {
            if (inventory->products[i].price > inventory->products[j].price) {
                Product temp = inventory->products[i];
                inventory->products[i] = inventory->products[j];
                inventory->products[j] = temp;
            }
        }
    }

    for (int i = 0; i < inventory->quantity; i++) {
        if (strcmp(inventory->products[i].category, category) == 0) {
            printf("Produto: %s \n Preco: %.2f \n Estoque: %d \n\n",
                inventory->products[i].name,
                inventory->products[i].price,
                inventory->products[i].stock
            );
        }
    }
}

int searchProduct(Inventory *inventory, const char *nameProduct) {
    for (int i = 0; i < inventory->quantity; i++) {
        if (strcmp(inventory->products[i].name, nameProduct) == 0) {
            return i;
        }
    }

    return -1;
}

void checkStock(Inventory *inventory) {
    for (int i = 0; i < inventory->quantity; i++) {
        if (inventory->products[i].stock < 5) {
            printf("Produto: %s | Estoque: %d (necessario reabastecer)\n",
                inventory->products[i].name,
                inventory->products[i].stock
            );
        }
    }
}

