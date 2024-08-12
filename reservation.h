#ifndef RESERVATION_H
#define RESERVATION_H

#define MAX_RESERVATIONS 100

typedef struct {
    int reservationID;
    int busID;
    char customerName[20];
    int seatNumber;
} Reservation;

void bookSeat();
void cancelReservation();
void viewReservations(int busID);

#endif
