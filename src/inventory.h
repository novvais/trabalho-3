#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct {
    char name[100];    
    char category[50];  
    double price;       
    int stock;          
} Product;

typedef struct {
    Product *products; 
    int quantity;       
    int capacity;      
} Inventory;

Inventory createInventory(int capacity);

void addProduct(Inventory *inventory, Product product);
void displayByCategory(Inventory *inventory, const char *category);
void displayByCategoryPrice(Inventory *inventory, const char *category);
int searchProduct(Inventory *inventory, const char *nameProduct);
void checkStock(Inventory *inventory);

#endif 
