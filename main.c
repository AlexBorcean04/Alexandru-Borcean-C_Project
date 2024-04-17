#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "order.h"
#include "product.h"
#include "user.h"

void clearInputBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exitShop(){
    printf("Thank you for using the Online Shop. Goodbye!\n");
    exit(0);
}

void loginUser(const char *username, const char *password, int *loggedIn);
void createAccount(const char *username, const char *password);
void addProduct(const char *name, int quantity, double price);
void placeOrder(int code, const char *productName, int quantity, double paidAmount, const char *userName, const char *userSurname);
void viewOrders(const char *userName, const char *userSurname);
void searchProductByName(const char *name);
void searchProductByPrice(double minPrice, double maxPrice);
void clearInputBuffer();
void exitShop();
void saveOrders();
void loadOrders();
void loadProducts();
void saveProducts();

int main() {
    loadOrders();
    loadProducts();
    int loggedIn = 0;
    int option;
    char username[100], password[100];

    while (!loggedIn) {
        printf("Welcome to Online Shop\n");
        printf("1. Login\n");
        printf("2. Create Account\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        clearInputBuffer();

        switch (option) {
            case 1:
                printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = 0;
            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = 0;
            loginUser(username, password, &loggedIn);
            break;

            case 2:
                printf("Choose a username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = 0;
            printf("Choose a password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = 0;
            createAccount(username, password);
            break;

            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }



    while (1) {
        printf("\nOnline Shop Main Menu\n");
        printf("1. Add a Product\n");
        printf("2. Place an Order\n");
        printf("3. View Orders\n");
        printf("4. Search for a Product by Name\n");
        printf("5. Search for a Product by Price\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        switch (option) {
            case 1: {
                char name[100];
                int quantity;
                double price;
                printf("Enter product name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%lf", &price);
                clearInputBuffer();
                addProduct(name, quantity, price);
                break;
            }
            case 2: {
                int orderCode;
                char productName[100];
                int quantity;
                char userName[100];
                char userSurname[100];
                double totalAmount;
                printf("Enter order code: ");
                scanf("%d", &orderCode);
                clearInputBuffer();
                printf("Enter product name: ");
                fgets(productName, sizeof(productName), stdin);
                productName[strcspn(productName, "\n")] = 0;

                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter total amount paid: ");
                scanf("%lf", &totalAmount);
                clearInputBuffer();
                printf("Enter user's first name: ");
                fgets(userName, sizeof(userName), stdin);
                userName[strcspn(userName, "\n")] = 0;

                printf("Enter user's surname: ");
                fgets(userSurname, sizeof(userSurname), stdin);
                userSurname[strcspn(userSurname, "\n")] = 0;


                placeOrder(orderCode, productName, quantity, totalAmount, userName, userSurname);

                break;
            }

            case 3: {
                char userName[100];
                char userSurname[100];
                printf("Enter user's first name: ");
                fgets(userName, sizeof(userName), stdin);
                userName[strcspn(userName, "\n")] = 0;
                printf("Enter user's surname: ");
                fgets(userSurname, sizeof(userSurname), stdin);
                userSurname[strcspn(userSurname, "\n")] = 0;
                viewOrders(userName, userSurname);
                break;
            }
            case 4: {
                char name[100];
                printf("Enter product name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                searchProductByName(name);
                break;
            }
            case 5: {
                double minPrice, maxPrice;
                printf("Enter minimum price: ");
                scanf("%lf", &minPrice);
                printf("Enter maximum price: ");
                scanf("%lf", &maxPrice);
                clearInputBuffer();
                searchProductByPrice(minPrice, maxPrice);
                break;
            }
            case 6:
                saveProducts();
                saveOrders();
                exitShop();
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }
}
