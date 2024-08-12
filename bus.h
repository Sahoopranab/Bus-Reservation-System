#ifndef BUS_H
#define BUS_H

#define MAX_BUSES 50
#define MAX_SEATS 40

typedef struct {
    int busID;
    char busName[50];
    int totalSeats;
    int availableSeats;
} Bus;

extern Bus buses[MAX_BUSES];
extern int busCount;

void addBus();
void viewBuses();

#endif
