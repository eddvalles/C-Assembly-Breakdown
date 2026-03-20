/*
* Guess_the_Number.c
* A game where the player gueses a randomly generated number between 1 and 1000.
* The program provides hints (too high/too low) until the correct number is guessed.
* 
* Author: Eduardo Valles
* Date: 2026-03-20
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_number(void);

int number;
int guess;
char playAgain;

int main(void){
    srand(time(NULL));

    number = generate_number();
    guess = -1;
    playAgain = 'y';

    while (playAgain == 'y'){
        printf("%s\n", "I have a number between 1 and 1000.");
        printf("%s\n", "Can you guess my number?");
        printf("%s\n", "Please type your first guess.");

        scanf("%d", &guess);

        while (guess != number){
            if (guess > number){
                printf("%s\n", "Too high. Try again.");
            }
            else if (guess < number){
                printf("%s\n", "Too low. Try again.");
            }

            scanf("%d", &guess);
        }

        printf("\n%s\n", "Excellent! You guessed the right number.");
        printf("%s\n", "Would you like to play again? (y or n)");

        scanf(" %c", &playAgain);
    }

    return 0;
}

int generate_number(void){
    return rand() % 1000 + 1;
}