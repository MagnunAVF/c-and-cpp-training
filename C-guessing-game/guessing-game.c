#include <stdio.h>

#define NUMBER_OF_TRIES 3

int main()
{
    printf("*****************************\n");
    printf("* Welcome to Guessing Game! *\n");
    printf("*****************************\n");

    int secret_number = 42;

    for (int i = 1; i <= NUMBER_OF_TRIES; i++)
    {
        printf("\nTry %d of %d.\n", i, NUMBER_OF_TRIES);

        int user_guess;
        printf("What's your guess? ");
        scanf("%d", &user_guess);
        printf("Your guess is %d.\n", user_guess);

        int is_correct_guess = (user_guess == secret_number);
        if (is_correct_guess)
        {
            printf("Correct guessing!\n");
            break;
        }
        else
        {
            printf("Wrong ! Try again.\n");

            int is_greater_than_secret = (user_guess > secret_number);
            if (is_greater_than_secret)
            {
                printf("Your guess is greater than the secret number\n");
            }
            else
            {
                printf("Your guess is less than the secret number\n");
            }
        }
    }

    printf("\nEnd of the game! \n");
}