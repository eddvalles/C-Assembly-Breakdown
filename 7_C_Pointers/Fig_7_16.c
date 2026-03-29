// Fig. 7.16: fig07_16.c
// Applying sizeof to an array name returns
// the number of bytes in the array.
#include <stdio.h>
#define SIZE 20

size_t getSize(float *ptr); // prototype

int main(void)
{
    float array[SIZE]; // create array

    printf("The number of bytes in the array is %u"
            "\nThe number of bytes returned by getSize is %u\n",
            sizeof(array), getSize(array));
    
    return 0;
}

// return size of ptr
size_t getSize(float *ptr)
{
    /* Note: If you change to sizeof(*ptr), you dereference the value, 
       and you get the size of the float which is 4 bytes. 
       As is, you will get the size of the pointer, which is 8 bytes in a 64-bit architecture.
    */
    return sizeof(ptr); 
}