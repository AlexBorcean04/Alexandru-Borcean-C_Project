#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct {
    char name[100];
    int quantity;
    double price;
} Product;
extern Product products[100];
extern int numProducts;
void addProduct(const char *name, int quantity, double price);
void searchProductByName(const char *name);
void searchProductByPrice(double min_price, double max_price);

#endif
