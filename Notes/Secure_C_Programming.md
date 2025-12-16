## Arithmetic Overflow ##

https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow

sum = integer1 + integer2; // assign total to sum

Even this simple statement has a potential problem -- adding the integers could result in a value that's too large
to store in an int variable. This is known as arithmetic overflow and can cause undefined behavior, possibly leaving
a system open to attack.

The platform-specific maximum and minimum values that can be stored in an int variable are represented
by the constant INT_MAX and INT_MIN, which are defined in the header <limits.h>

#include <limits.h>
  
void f(signed int si_a, signed int si_b) {
  signed int sum;
  if (((si_b > 0) && (si_a > (INT_MAX - si_b))) ||
      ((si_b < 0) && (si_a < (INT_MIN - si_b)))) {
    /* Handle error */
  } else {
    sum = si_a + si_b;
  }
  /* ... */
}



