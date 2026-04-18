/*
Chapter 10: Exercise 10.5

Provide the definition for each of the following structures and unions:
a) Structure inventory containing character array partName[30], integer partNumber,
floating-point price, integer stock and integer reorder.

b) Union data containing char c, short s, long b, float f and double d.

c) A structure called address that contains character arrays
streetAddress[25], city[20], state[3] and zipCode[6].

d) Structure student that contains arrays firstName[15] and
lastName[15] and variable homeAddress of type struct address from part (c).

e) Structure test containing 16 bit fields with widths of 1 bit. The names of the bit fields
are the letters a to p.
*/
#include <stdio.h>

struct inventory {
    char  partName[30];
    int   partNumber;
    float price;
    int   stock;
    int   reorder;
};

union data {
    char   c;
    short  s;
    long   b;
    float  f;
    double d;
};

struct address {
    char streetAddress[25];
    char city[20];
    char state[3];
    char zipCode[6];
};

struct student {
    char firstName[15];
    char lastName[15];
    struct address homeAddress; 
};

struct test {
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int d : 1;
    unsigned int e : 1;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int i : 1;
    unsigned int j : 1;
    unsigned int k : 1;
    unsigned int l : 1;
    unsigned int m : 1;
    unsigned int n : 1;
    unsigned int o : 1;
    unsigned int p : 1;
};

int main(void)
{
    return 0;
}