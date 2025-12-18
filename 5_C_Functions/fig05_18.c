// Fig. 5.18: fig05_18.c
// Recursive factorial function.
#include <stdio.h>

unsigned long long int factorial(unsigned int number);

int main(void){
    // during each iteration, calculate
    // factorial(i) and display result
    for (unsigned int i =0; i <= 21; ++i){
        printf("%u! = %llu\n", i, factorial(i));
    }

    return 0;
}

// recursive definition of functional factorial
unsigned long long int factorial(unsigned int number){
    // base case
    if (number <= 1){
        return 1;
    }
    else { // recursive step
        return (number * factorial(number - 1));
    }
}