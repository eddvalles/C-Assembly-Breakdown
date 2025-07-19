#include <stdio.h>
#include <limits.h>

int main( void ){

    int startNum = 2147483647;
    int addNum = 1;
    int sum = 0;

    printf("Max int: %d\n", INT_MAX);

    sum = startNum + addNum;

    // Here you will be able to observe the values wrapping around to a negative value
    printf("sum is: %d\n\n", sum); // Results in '-2147483648

    startNum = 2147483647;
    addNum = 1;
    sum = 0;

    // Here we include the error secure overflow method
    // INT32-C CERT Secure Programming Guidance
    if (((startNum > 0) && (addNum > (INT_MAX - startNum))) ||
        ((startNum < 0) && (addNum < (INT_MIN - startNum)))){
            printf("%s", "Overflow!! cannot perform operation.\n\n");
    }
    else {
        sum = startNum + addNum;
    }

    printf("sum is: %d", sum);

    return 0;
}