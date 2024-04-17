#ifndef ORDER_H
#define ORDER_H


typedef struct {
    int orderCode;
    char productName[100];
    int quantity;
    double totalAmount;
    char userName[50];
    char userSurname[50];
} Order;
extern Order orders[100];
extern int numOrders;

void placeOrder(int code, const char *productName, int quantity, double paidAmount, const char *userName, const char *userSurname);
void viewOrders(const char *userName, const char *userSurname);

#endif
