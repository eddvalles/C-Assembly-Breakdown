/*
Chapter 10: Exercise 10.6

Given the following structure and variable definitions,
struct customer {
    char lastName[15];
    char firstName[15];
    unsigned int customerNumber;
    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;
customerPtr = &customerRecord;

write an expression that can be used to access the structure members in each of the following parts:
a) Member lastName of structure customerRecord.
b) Member lastName of the structure pointed to by customerPtr.
c) Member firstName of structure customerRecord.
d) Member firstName of the structure pointed to by customerPtr.
e) Member customerNumber of structure customerRecord.
f) Member customerNumber of the structure pointed to by customerPtr.
g) Member phoneNumber of member personal of structure customerRecord.
h) Member phoneNumber of member personal of the structure pointed to by customerPtr.
i) Member address of member personal of structure customerRecord.
j) Member address of member personal of the structure pointed to by customerPtr.
k) Member city of member personal of structure customerRecord.
l) Member city of member personal of the structure pointed to by customerPtr.
m) Member state of member personal of structure customerRecord.
n) Member state of member personal of the structure pointed to by customerPtr.
o) Member zipCode of member personal of structure customerRecord.
p) Member zipCode of member personal of the structure pointed to by customerPtr.
*/

#include <stdio.h>
#include <string.h>

struct customer {
    char lastName[15];
    char firstName[15];
    unsigned int customerNumber;
    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
};

int main(void)
{
    struct customer customerRecord, *customerPtr;

    customerPtr = &customerRecord;

    strcpy(customerRecord.lastName, "Billybob");
    strcpy(customerRecord.firstName, "John");
    customerRecord.customerNumber = 2456;
    strcpy(customerRecord.personal.phoneNumber, "111-222-333");
    strcpy(customerRecord.personal.address, "555 that St");

    puts("a) Member lastName of structure customerRecord:");
    printf("Last Name: %s\n\n", customerRecord.lastName);

    puts("b) Member lastName of the structure pointed to by customerPtr:");
    printf("Last Name: %s\n\n", customerPtr->lastName);

    puts("c) Member firstName of structure customerRecord:");
    printf("Last Name: %s\n\n", customerRecord.firstName);

    puts("d) Member firstName of the structure pointed to by customerPtr:");
    printf("Last Name: %s\n\n", customerPtr->firstName);

    puts("e) Member customerNumber of structure customerRecord:");
    printf("Customer Number: %d\n\n", customerRecord.customerNumber);

    puts("f) Member customerNumber of the structure pointed to by customerPtr:");
    printf("Customer Number: %d\n\n", customerPtr->customerNumber);

    puts("g) Member phoneNumber of member personal of structure customerRecord:");
    printf("Phone Number: %s\n\n", customerRecord.personal.phoneNumber);

    puts("h) Member phoneNumber of member personal of the structure pointed to by customerPtr");
    printf("Phone Number: %s\n\n", customerPtr->personal.phoneNumber);

    puts("i) Member address of member personal of structure customerRecord.");
    printf("Address: %s\n\n", customerRecord.personal.address);

    

    return 0;
}