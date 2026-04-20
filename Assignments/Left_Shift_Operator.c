/*
Exercise 10.11 and 10.12

10.11 (Left Shifting Integers)
Left shifting an unsigned int by 1 bit is equivalent to multiplying the value by 2. Write function power2()
that takes two integer arguments number and pow and calculates
    number * 2^pow
Use the shift operator to calculate the result. Print the values as integers and as bits.
*/
#include <stdio.h>

unsigned int power2(unsigned int number, int pow);
void displayBits(unsigned int value); // prototype

int main(void)
{
    unsigned int number;
    unsigned int power;
    unsigned int result;

    puts("Enter a number: ");
    scanf("%d", &number);

    puts("Enter a power: ");
    scanf("%d", &power);

    printf("Number: %d\nBits: ", number);
    displayBits(number);

    result = power2(number, power);
    printf("Result: %d\nBits: ", result);
    displayBits(result);

    return 0;
}

unsigned int power2(unsigned int number, int pow) {
    return number <<= pow;
}

void displayBits(unsigned int value)
{
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;

    // loop through bits
    for (unsigned int c = 1; c <= 32; ++c) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // shift value left 1, same as value = value << 1;

        if (c % 8 == 0) { // output a space after 8 bits
            putchar(' ');
        }
    }

    putchar('\n');
}