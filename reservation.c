#include <stdio.h>
#include <string.h>
#include "reservation.h"
#include "bus.h"

Reservation reservations[MAX_RESERVATIONS];
int reservationCount = 0;

void bookSeat() {
    int busID, seatNumber;
    char customerName[20];

    printf("Enter Bus ID: ");
    scanf("%d", &busID);

    // Find the bus
    Bus *bus = NULL;
    for (int i = 0; i < MAX_BUSES; i++) {
        if (buses[i].busID == busID) {
            bus = &buses[i];
            break;
        }
    }

    if (bus == NULL) {
        printf("Invalid Bus ID!\n");
        return;
    }

    if (bus->availableSeats <= 0) {
        printf("No seats available!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", customerName);
    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    Reservation newReservation;
    newReservation.reservationID = reservationCount + 1;
    newReservation.busID = busID;
    strcpy(newReservation.customerName, customerName);
    newReservation.seatNumber = seatNumber;

    reservations[reservationCount] = newReservation;
    reservationCount++;

    // Update available seats in the bus
    bus->availableSeats--;

    printf("Seat booked successfully!\n");
}

void cancelReservation() {
    int reservationID;

    printf("Enter Reservation ID: ");
    scanf("%d", &reservationID);

    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].reservationID == reservationID) {
            // Find the bus and update the available seats
            for (int j = 0; j < busCount; j++) {
                if (buses[j].busID == reservations[i].busID) {
                    buses[j].availableSeats++;
                    break;
                }
            }

            // Shift the reservations
            for (int j = i; j < reservationCount - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            reservationCount--;

            printf("Reservation canceled successfully!\n");
            return;
        }
    }

    printf("Invalid Reservation ID!\n");
}

void viewReservations(int busID) {
    int found = 0;
    printf("Reservations for Bus ID %d:\n", busID);
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].busID == busID) {
            printf("Reservation ID: %d, Customer: %s, Seat Number: %d\n",
                   reservations[i].reservationID, reservations[i].customerName, reservations[i].seatNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("No reservations found for this bus.\n");
    }
}
