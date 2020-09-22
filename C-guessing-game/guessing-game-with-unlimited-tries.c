#include <stdio.h>

int main()
{
    printf("*****************************\n");
    printf("* Welcome to Guessing Game! *\n");
    printf("*****************************\n");

    int secret_number = 42;
    int tries = 1;

    while (1)
    {
        printf("\nTry %d.\n", tries);

        int user_guess;
        printf("What's your guess (Digit a number)? ");
        scanf("%d", &user_guess);
        printf("Your guess is %d.\n", user_guess);

        if (user_guess < 0) {
            printf("Your number cannot be negative!\n");
        }

        int is_correct_guess = (user_guess == secret_number);
        int is_greater_than_secret = (user_guess > secret_number);

        if (is_correct_guess)
        {
            printf("Correct guess!\n");
            break;
        }
        else if (is_greater_than_secret)
        {
            printf("Wrong ! Try again.\n");
            printf("Your guess is greater than the secret number\n");
        }
        else
        {
            printf("Wrong ! Try again.\n");
            printf("Your guess is less than the secret number\n");
        }

        tries = tries + 1;
    }

    printf("\nEnd of the game! \n");
    printf("Number of guesses: %d.\n", tries);
}