#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a movie ticket booking
struct TicketBooking {
    char customerName[50];
    int numTickets;
    struct TicketBooking* next;
};

struct TicketBooking* front = NULL;
struct TicketBooking* rear = NULL;

// Function to enqueue (add) a ticket booking
void enqueue(const char* customerName, int numTickets) {
    struct TicketBooking* newBooking = (struct TicketBooking*)malloc(sizeof(struct TicketBooking));
    if (newBooking == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newBooking->customerName, customerName);
    newBooking->numTickets = numTickets;
    newBooking->next = NULL;

    if (rear == NULL) {
        front = rear = newBooking;
    } else {
        rear->next = newBooking;
        rear = newBooking;
    }
}

// Function to dequeue (process) a ticket booking
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct TicketBooking* bookingToRemove = front;
    front = front->next;

    printf("Processing booking for %s: %d ticket(s).\n", bookingToRemove->customerName, bookingToRemove->numTickets);

    free(bookingToRemove);
}

// Function to display all ticket bookings
void displayBookings() {
    struct TicketBooking* current = front;
    printf("Current Ticket Bookings:\n");
    while (current != NULL) {
        printf("%s: %d ticket(s)\n", current->customerName, current->numTickets);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50];
    int numTickets;

    while (1) {
        printf("\nMovie Ticket Booking System\n");
        printf("1. Book a Ticket\n");
        printf("2. Process Booking (FCFS)\n");
        printf("3. Display Bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter number of tickets: ");
                scanf("%d", &numTickets);
                enqueue(name, numTickets);
                printf("Booking added to the queue.\n");
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayBookings();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }return 0;}