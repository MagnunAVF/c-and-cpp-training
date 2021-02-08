#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("*****************************\n");
    printf("* Welcome to Guessing Game! *\n");
    printf("*****************************\n");

    // seeds rand with epoch time
    int epoch_time = time(0);
    srand(epoch_time);

    // random number between 0 - 99
    int secret_number = rand() % 100;

    int tries = 1;
    double score = 1000;

    int is_correct_guess = 0;

    int numberOfTries;
    int level;
    printf("Select the difficulty level\n");
    printf("(1) Easy   (2) Normal   (3) Hard\n\n");
    printf("Choose: ");
    scanf("%d", &level);

    switch (level)
    {
    case 1:
        numberOfTries = 20;
        break;

    case 2:
        numberOfTries = 15;
        break;

    default:
        numberOfTries = 6;
        break;
    }

    for (int i = 0; i < numberOfTries; i++)
    {
        printf("\nTry %d.\n", tries);

        int user_guess;
        printf("What's your guess (Digit a number)? ");
        scanf("%d", &user_guess);
        printf("Your guess is %d.\n", user_guess);

        if (user_guess < 0)
        {
            printf("Your number cannot be negative!\n");
        }

        is_correct_guess = (user_guess == secret_number);
        int is_greater_than_secret = (user_guess > secret_number);

        if (is_correct_guess)
        {
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

        tries++;

        double score_lost = abs(user_guess - secret_number) / (double)2;
        score = score - score_lost;
    }

    printf("\nEnd of the game! \n");

    if (is_correct_guess)
    {
        printf("You Win ! Correct guess.\n");
        printf("Number of guesses: %d.\n", tries);
        printf("Game Score: %.3f\n", score);
    }
    else
    {
        printf("You Loose! Try again.\n");
    }
}