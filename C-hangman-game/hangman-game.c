#include <stdio.h>
#include <string.h>

int main() {
    char secretword[20];
    sprintf(secretword, "MELANCIA");

    int hit = 0;
    int hanged = 0;

    char guesses[26];
    int tries = 0;

    do {
        for(int i = 0; i < strlen(secretword); i++) {
            int finded = 0;
            for(int j = 0; j < tries; j++) {
                if(guesses[j] == secretword[i]) {
                    finded = 1;
                    break;
                }
            }

            if(finded) {
                printf("%c ", secretword[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char guess;
        scanf(" %c", &guess);

        guesses[tries] = guess;
        tries++;

    } while(!hit && !hanged);
}