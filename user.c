#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    char username[20];
    char password[20];
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void adminLogin() {
    char username[20], password[20];

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Admin login successful!\n");
    } else {
        printf("Invalid admin credentials!\n");
    }
}

void registerCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Cannot register more customers!\n");
        return;
    }

    Customer newCustomer;
    printf("Enter new username: ");
    scanf("%s", newCustomer.username);
    printf("Enter new password: ");
    scanf("%s", newCustomer.password);

    customers[customerCount] = newCustomer;
    customerCount++;

    printf("Customer registered successfully!\n");
}

int validateCustomer(char* username, char* password) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].username, username) == 0 && strcmp(customers[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void customerLogin() {
    char username[20], password[20];

    printf("Enter customer username: ");
    scanf("%s", username);
    printf("Enter customer password: ");
    scanf("%s", password);

    if (validateCustomer(username, password)) {
        printf("Customer login successful!\n");
    } else {
        printf("Invalid customer credentials!\n");
    }
}
