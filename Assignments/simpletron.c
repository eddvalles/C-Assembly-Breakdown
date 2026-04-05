/*
Special Section: Building Your Own Computer (7.27 and 7.28)

7.27:
Simpletron contains an "accumulator" - a "special register" in which information is put before the Simpletron
that uses that information in calculations or examines it in various ways. All information in the Simpletron
is handled in terms of words.

    Word = Four-digit decimal number such as +3364, -1293, +0007, -0001...

Simpletron is equipped with a 100-word memory, and these words are referenced by their location numbers 00, 01, ...

Before running an SML program, we must load or place the program into memory. The first instruction (or statement)
of every SML program is always placed in location 00.

Each location in the Simpletron's memory may contain either an instruction, a data value used by a program
or an unused area of memory.

The first two digits of each SML instruction are the operation code, which specifies the operation to be performed.
The last two digits of an SML instruction are the operand, which is the address of the memory location containing
the word to which the operation applies. 

Ex. 1) The following SML program reads two numbers from the keyboard, and computes and prints their sum.
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

Ex. 2) The following SML program reads two numbers from the keyboard, and determines and prints the larger value.
00 +1009 (Read A)
01 +1010 (Read B)
02 +2009 (Load A)
03 +3110 (Subtract B)
04 +4107 (Branch negative to 07)
05 +1109 (Write A)
06 +4300 (Halt)
07 +1110 (Write B)
08 +4300 (Halt)
09 +0000 (Variable A)
10 +0000 (Variable B)

a) Use a sentinel-controlled loop to read positive integers and compute and print their sum
00 +1011 READ input
01 +2011 LOAD input into accumulator
02 +3112 Subtract accumulator from sentinel
03 +4208 BRANCHZERO 08, if result is 0, input was -1, jump to end
04 +2013 LOAD sum from location 13
05 +3011 ADD input
06 +2113 STORE sum at location 13
07 +4000 BRANCH 00, loop back to beginning
08 +2013 LOAD sum from location 13
09 +1113 WRITE sum 
10 +4300 HALT
11 0     Input variable
12 -1    Sentinel = -1 variable
13 0     Sum variable
*/

#include <stdio.h>

void load(int memArray[]); // Reads the SML instructions from the user at the keyboard
void dump(int memArray[], int accumulator, int instructionCounter,
        int instructionRegister, int operationCode, int operand);

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

    int accumulator = 0;
    int instructionCounter = 0;  // Location in memory that contains the instruction being performed
    int instructionRegister = 0; // Next instruction to be performed
    int operationCode = 0;       // Operation currently being performed
    int operand = 0;             // Memory location in which the current instruction operates

    puts("*** Welcome to Simpletron! ***");
    puts("*** Please enter your program one instruction ***");
    puts("*** (or data word) at a time. I will type the ***");
    puts("*** location number and a question mark (?).  ***");
    puts("*** You then type the word for that location. ***");
    puts("*** Type the sentinel -99999 to stop entering ***");
    puts("*** your program. ***");

    // Prompt user to enter instructions one by one
    printf("Please enter instructions:\n");
    load(MEMORY);

    dump(MEMORY, accumulator, instructionCounter,
                instructionRegister, operationCode, operand);

    int running = 1;
    while (running){

        instructionRegister = MEMORY[instructionCounter]; 
        operationCode = instructionRegister / 100; 
        operand = instructionRegister % 100; 

        switch(operationCode){
            case READ: // Read a word from the terminal into a specific location in memory
                printf("Please provide an integer > ");
                fflush(stdout);

                int input = 0;
                do {
                    scanf("%d", &input);
                    if (input < -9999 || input > 9999){
                            printf("Please enter a value between -9999 and 9999: ");
                            fflush(stdout);
                    }
                } while (input < -9999 || input > 9999);

                MEMORY[operand] = input;

                instructionCounter++;
                break;
            case WRITE: // Write a word from a specific location in memory to the terminal
                printf("\nAnswer: %d\n", MEMORY[operand]);

                instructionCounter++;
                break;
            case LOAD: // Load a word from a specific location in memory into the accumulator
                accumulator = MEMORY[operand];

                instructionCounter++;
                break;
            case STORE: // Store a word from the accumulator into a specific location in memory
                MEMORY[operand] = accumulator;

                instructionCounter++;
                break;
            case ADD: // Add a word from a specific location in memory to the word in the accumulator
                accumulator += MEMORY[operand];

                instructionCounter++;
                break;
            case SUBTRACT: // Sub a word from a specific location in memory from the word in the accumulator
                accumulator -= MEMORY[operand];

                instructionCounter++;
                break;
            case BRANCH: // Branch to a specific location in memory
                instructionCounter = operand;
                break;
            case BRANCHNEG: // Branch to a specific location in memory if the accumulator is negative
                if (accumulator < 0){
                    instructionCounter = operand;
                }
                else {
                    instructionCounter++;
                }

                break;
            case BRANCHZERO: // Branch to a specific location in memory if the accumulator is zero
                if (accumulator == 0){
                    instructionCounter = operand;
                }
                else {
                    instructionCounter++;
                }
                break;
            case HALT: // Halt - i.e., the program has completed its task
                printf("*** Simpletron execution terminated ***\n");

                running = 0;
                break;
        }   
    }

    dump(MEMORY, accumulator, instructionCounter,
                instructionRegister, operationCode, operand);

    return 0;
}

/**
 * Displays the contents of memory and all of the registers stored in main's variables
 */
void dump(int memArray[], int accumulator, int instructionCounter,
        int instructionRegister, int operationCode, int operand)
{
    printf("\nREGISTERS:\n");
    printf("%-25s%+05d\n", "accumulator",         accumulator);
    printf("%-25s%02d\n",  "instructionCounter",  instructionCounter);
    printf("%-25s%+05d\n", "instructionRegister", instructionRegister);
    printf("%-25s%02d\n",  "operationCode",       operationCode);
    printf("%-25s%02d\n",  "operand",             operand);

    printf("\nMEMORY:\n");

    // column headers
    printf("%4s", "");
    for (int col = 0; col < 10; col++) {
        printf("%7d", col);
    }
    printf("\n");

    // rows
    for (int row = 0; row < 10; row++) {
        printf("%3d", row * 10);  // row label (0, 10, 20, ...)
        for (int col = 0; col < 10; col++) {
            printf(" %+05d", memArray[row * 10 + col]);
        }
        printf("\n");
    }
}

/**
 * Reads the SML instructions from the user at the keyboard
 * Stops when the sentinel value -99999 is entered
 */
void load(int memArray[])
{
    for (int i = 0; i < MEM_SIZE; i++){
        int input = 0;

        printf("%02d ? ", i);
        fflush(stdout);
        
        scanf("%d", &input);

        if (input == -99999){
            printf("*** Program loading completed ***\n");
            printf("*** Program execution begins ***\n\n");
            break;
        }
        
        memArray[i] = input;
    }
}