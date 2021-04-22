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

int main()
{
    int hit = 0;
    int hanged = 0;

    chooseSecretword();
    greetings();

    do
    {
        drawHangman();
        makeAGuess();
    } while (!hit && !hanged);
}