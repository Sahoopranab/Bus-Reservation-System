#include <stdio.h>
#include <stdlib.h>
#include "bus.h"
#include "reservation.h"
#include "user.h"

void displayMenu() {
    printf("1. Admin Login\n");
    printf("2. Customer Login\n");
    printf("3. Customer Registration\n");
    printf("4. Exit\n");
}

void displayAdminMenu() {
    printf("1. Add Bus\n");
    printf("2. View Buses\n");
    printf("3. View Reservations\n");
    printf("4. Logout\n");
}

void displayCustomerMenu() {
    printf("1. View Buses\n");
    printf("2. Book Seat\n");
    printf("3. Cancel Reservation\n");
    printf("4. Logout\n");
}

int main() {
    int choice, busID;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminLogin();
                while (1) {
                    displayAdminMenu();
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    if (choice == 4) break;
                    switch (choice) {
                        case 1:
                            addBus();
                            break;
                        case 2:
                            viewBuses();
                            break;
                        case 3:
                            printf("Enter Bus ID: ");
                            scanf("%d", &busID);
                            viewReservations(busID);
                            break;
                        default:
                            printf("Invalid choice!\n");
                    }
                }
                break;

            case 2:
                customerLogin();
                while (1) {
                    displayCustomerMenu();
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    if (choice == 4) break;
                    switch (choice) {
                        case 1:
                            viewBuses();
                            break;
                        case 2:
                            bookSeat();
                            break;
                        case 3:
                            cancelReservation();
                            break;
                        default:
                            printf("Invalid choice!\n");
                    }
                }
                break;

            case 3:
                registerCustomer();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}