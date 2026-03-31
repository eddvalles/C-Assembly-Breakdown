/*
Special Section: Building Your Own Computer (7.27 through 7.29)

7.27:
Simpletron contains an "accumulator" - a "special register" in which information is put before the Simpletron
that uses that information in calculations or examines it in various ways. All information in the Simpletron
is handled in terms of words.

    Word = Four-digit decimal number such as +3364, -1293, +0007, -0001...

Simpletron is equipped with a 100-word memory, and these words are referenced by their location numbers 00, 01, ...

Before running an SML program, we must load or place the program into memory. The first instruction (or statement)
of every SML program is always placed in location 00.

The sign of an SML instruction is always plus.
The sign of a data word may be either plus or minus.

Each location in the Simpletron's memory may contain either an instruction, a data values used by a program
or an unused area of memory.

The first two digits of each SML instruction are the operation code, which specifies the operation to be performed.
The last two digits of an SML instruction are the operand, which is the address of the memory location containing
the word to which the operation applies. 

The following SML program reads two numbers from the keyboard, and computes and prints their sum.
00 +1007 (Read A)
01 +1008 (Read B)
02 +2007 (Load A)
03 +3008 (Add B)
04 +2109 (Store C)
05 +1109 (Write C)
06 +4300 (Halt)
07 +0000 (Variable A)
08 +0000 (Variable B)
09 +0000 (Result C)

Pseudocode:
--- LOAD PHASE ---
prompt user to enter instructions one by one
for each input:
    store it in memory[instructionCounter]
    increment instructionCounter
until user signals end of program
*/

#include <stdio.h>

void showMemory(int memArray[]);

#define READ 10       // Read a word from the terminal into a specific location in memory
#define WRITE 11      // Write a word from a specific location in memory to the terminal
#define LOAD 20       // Load a word from a specific location in memory into the accumulator
#define STORE 21      // Store a word from the accumulator into a specific location in memory
#define ADD 30        // Add a word from a specific location in memory to the word in the accumulator
#define SUBTRACT 31   // Sub a word from a specific location in memory from the word in the accumulator
#define DIVIDE 32     // Divide a word from a specific location in memory into the word in the accumulator
#define MULTIPLY 33   // Multiply a word from a specific location in memory by the word in the accumulator
#define BRANCH 40     // Branch to a specific location in memory
#define BRANCHNEG 41  // Branch to a specific location in memory if the accumulator is negative
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero
#define HALT 43       // Halt - i.e., the program has completed its task

#define MEM_SIZE 100

int main(void)
{
    // Define the 100-word memory
    int MEMORY[MEM_SIZE] = {0};

    puts("Initial Memory Array: ");
    showMemory(MEMORY);

    // Prompt user to enter instructions one by one
    printf("Please enter instructions:\n");
    for (int i = 0; i < MEM_SIZE; i++){
        int instruction = 0;

        scanf("%4d", &instruction);

        if (instruction == 4300){
            printf("Halting program...\n\n");
            break;
        }

        MEMORY[i] = instruction;
    }

    puts("Final Memory Array: ");
    showMemory(MEMORY);

    // TODO: Build a switch-case that will take the first two digits of the provided number
    // TODO: and perform that instruction (% or /)?
    //switch (instruction){
    //    case 10: // Read a word from the terminal into a specific location in memory
            // TODO: Determine action to take here
    //}

    return 0;
}

void showMemory(int memArray[])
{
    for (int i = 0; i < MEM_SIZE; i++){
        printf("%d, ", memArray[i]);
    }
    puts("");
}