# Bus Reservation System

## Overview
The Bus Reservation System is a simple C project that allows users to manage bus reservations. The system supports both admin and customer functionalities, including the ability to add buses, view available buses, book seats, and cancel reservations.

## Features
- **Admin Login:**
  - Add new buses to the system.
  - View all available buses.
  - View reservations for a specific bus.

- **Customer Login:**
  - Register as a new customer.
  - View available buses.
  - Book a seat on a bus.
  - Cancel an existing reservation.

## Project Structure


├── main.c             # Main program file
├── bus.c              # Source file containing bus-related functions
├── bus.h              # Header file for bus-related functions
├── reservation.c      # Source file containing reservation-related functions
├── reservation.h      # Header file for reservation-related functions
├── user.c             # Source file containing user login and registration functions
├── user.h             # Header file for user login and registration functions
└── README.md          # Project documentation

Usage : -
Admin Login:

Username: admin
Password: admin123

Customer Registration:

Register a new customer to use the system.
Customer Login:

Log in with your username and password to view buses and make reservations.

Example : -

# After running the program
1. Admin Login
2. Customer Login
3. Customer Registration
4. Exit

# Admin login
Enter admin username: admin
Enter admin password: admin123

# Add a bus
Enter bus name: Bus101

# View available buses
Bus ID: 1, Name: Bus101, Available Seats: 40

# Customer registration and login
Enter new username: john_doe
Enter new password: password123
Customer registered successfully!

Enter customer username: john_doe
Enter customer password: password123
Customer login successful!


Contact
For any questions or suggestions, feel free to contact me at sahoopranab2004@gmail.com

# Book a seat
Enter Bus ID: 1
Enter seat number (1-40): 5
Seat booked successfully!
