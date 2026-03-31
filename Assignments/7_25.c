/*
Arrays of Pointers to Functions:

Rewrite the program of Fig_6_22 to use a menu-driven interface. The program should offer the user four options as
follows:
    Enter a choice:
        0  Print the array of grades
        1  Find the minimum grade
        2  Find the maximum grade
        3  Print the average on all tests for each student
        4  End program

One restriction on using arrays of pointers is that all the pointers must have the same type. For this reason,
the functions in Fig_6_22 must be modified so that they each return the same type and take the same parameters.

Modify functions minimum and maximum to print the minimum or maximum value and return nothing.

For option 3, modify function average to output the average for each student (not a specific student). It should
return nothing and take the same parameters as printArray, minimum and maximum.

Store the pointers to the four functions in array processGrades and use the choice made by the user as the index
into the array for calling each function.
*/

#include <stdio.h>

int main(void)
{
    return 0;
}