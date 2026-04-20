/*
10.12 (Packing Characters into an Integer)
The left-shift operator can be used to pack four character values into a four-byte unsigned int variable.

Write a program that inputs four characters from the keyboard and passes them to function packCharacters().
To pack four characters into an unsigned int variable, assign the first charcter to the unsigned int variable,
shift the unsigned int variable left by 8 positions and combine the unsigned variable with the second character
using the bitwise inclusive OR operator. 

Repeat this process for the third and fourth characters.

The program should output the characters in their bit format before and after they're packed into the
unsigned int to prove that the characters are in fact packed correctly in the unsigned int variable.
*/
#include <stdio.h>

void displayBits(unsigned int value);
void packCharacters(unsigned int * const store, char char1, char char2, char char3, char char4);

int main(void)
{
    unsigned int store;

    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';

    printf("Store:\n");
    displayBits(store);

    packCharacters(&store, a, b, c, d);

    printf("Store (packed):\n");
    displayBits(store);

    return 0;
}

void packCharacters(unsigned int * const store, char char1, char char2, char char3, char char4) {
    *store = char1;

    *store <<= 8;

    *store = *store | char2;

    *store <<= 8;

    *store = *store | char3;

    *store <<= 8;

    *store = *store | char4;
}

void displayBits(unsigned int value)
{
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;

    printf("%7u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= 32; ++c) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // shift value left by 1, same as value = value << 1;

        if (c % 8 == 0) { // output a space after 8 bits
            putchar(' ');
        }
    }

    putchar('\n');
}