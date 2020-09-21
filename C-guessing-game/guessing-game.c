#include <stdio.h>

int main()
{
    printf("*****************************\n");
    printf("* Welcome to Guessing Game! *\n");
    printf("*****************************\n");

    int secret_number = 42;

    int user_guess;

    printf("What's your guess? ");
    scanf("%d", &user_guess);
    printf("Your guess is %d.\n", user_guess);
}