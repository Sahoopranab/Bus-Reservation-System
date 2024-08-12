#include <stdio.h>
#include <string.h>
#include "bus.h"

Bus buses[MAX_BUSES];
int busCount = 0;

void addBus() {
    if (busCount >= MAX_BUSES) {
        printf("Cannot add more buses!\n");
        return;
    }

    Bus newBus;
    newBus.busID = busCount + 1;
    printf("Enter bus name: ");
    scanf("%s", newBus.busName);
    newBus.totalSeats = MAX_SEATS;
    newBus.availableSeats = MAX_SEATS;

    buses[busCount] = newBus;
    busCount++;

    printf("Bus added successfully!\n");
}

void viewBuses() {
    if (busCount == 0) {
        printf("No buses available!\n");
        return;
    }

    printf("Available Buses:\n");
    for (int i = 0; i < busCount; i++) {
        printf("Bus ID: %d, Name: %s, Available Seats: %d\n", 
                buses[i].busID, buses[i].busName, buses[i].availableSeats);
    }
}
