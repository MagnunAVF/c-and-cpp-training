#include <stdio.h>
#include <string.h>

char secretword[20];
char guesses[26];
int tries = 0;

void greetings()
{
    printf("**************************\n");
    printf("***    Hangman Game    ***\n");
    printf("**************************\n\n");
}

void makeAGuess()
{
    char guess;
    printf("Which letter? ");
    scanf(" %c", &guess);

    guesses[tries] = guess;
    tries++;
}

int alreadyTriedThisGuess(char letter)
{
    int finded = 0;

    for (int j = 0; j < tries; j++)
    {
        if (guesses[j] == letter)
        {
            finded = 1;
            break;
        }
    }

    return finded;
}

void drawHangman()
{
    printf("Number o tries: %d \n", tries);
    for (int i = 0; i < strlen(secretword); i++)
    {
        int finded = alreadyTriedThisGuess(secretword[i]);

        if (finded)
        {
            printf("%c ", secretword[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void chooseSecretword()
{
    sprintf(secretword, "MELANCIA");
}

int hanged() {
    int errors = 0;

    for (int i = 0; i < tries; i++)
    {
        int exists = 0;

        for (int j = 0; j < strlen(secretword); j++)
        {
            if(guesses[i] == secretword[j]) {
                exists = 1;
                break;
            }
        }

        if (!exists) errors++;
    }

    return errors >= 5;
}

int main()
{
    int hit = 0;

    chooseSecretword();
    greetings();

    do
    {
        drawHangman();
        makeAGuess();
    } while (!hit && !hanged());
}