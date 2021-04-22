#include <stdio.h>
#include <string.h>

void greetings()
{
    printf("**************************\n");
    printf("***    Hangman Game    ***\n");
    printf("**************************\n\n");
}

void makeAGuess(char guesses[26], int *tries)
{
    char guess;
    scanf(" %c", &guess);

    guesses[(*tries)] = guess;
    (*tries)++;
}

int alreadyTriedThisGuess(char letter, char guesses[26], int tries)
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

void drawHangman(char secretword[20], char guesses[26], int tries)
{
    for (int i = 0; i < strlen(secretword); i++)
    {
        int finded = alreadyTriedThisGuess(secretword[i], guesses, tries);

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

void chooseSecretword(char secretword[20])
{
    sprintf(secretword, "MELANCIA");
}

int main()
{
    char secretword[20];
    char guesses[26];
    int hit = 0;
    int hanged = 0;
    int tries = 0;

    chooseSecretword(secretword);
    greetings();

    do
    {
        drawHangman(secretword, guesses, tries);
        makeAGuess(guesses, &tries);
    } while (!hit && !hanged);
}