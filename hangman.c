#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define MAX 64

char* ask_input(void);
void print_art(int);
int count_unique_char(char*);

char player = 'A';
bool guessed = false;
int lives = 6;
char *word = NULL;
char tries[MAX] = {0};
char guess = 0;

int main(void)
{
    //later proberen met extern bestand
    system("clear");

    word = ask_input();

    //Door een int met aantal unieke letters in te stellen hoeft in bijv goedemiddag 
    //de g of de d maar een keer guessed te worden omdat bij een goede raadbeurt unique-- geeft.
    int unique = count_unique_char(word);

    for (int i = 0; lives != 0 && guessed == false; i++)
    {
        printf("You have %i lives left\n", lives);
        if (i > 0)
        {
            printf("You have already tried: %s\n", tries);
        }
        else
        {
            printf("\n");
        }
        print_art(lives);
        printf("       # HANGMAN #       \n");

        //player B voert een letter in
        printf("Player %c, guess a character: ... \n", player+1);
        scanf(" %c", &guess);
        system("clear");


        //Als letter al een keer guessed is
        if (strchr(tries, guess) != NULL)
        {
            lives--;
            printf("The letter %c has already been tried!\n", guess);
            continue;
        }

        //Als letter goed is.
        if (strchr(word, guess) != NULL)
        {
            printf("The letter %c is right!\n", guess);
            unique--;
        }
        else
        {
            printf("Too bad!\n");
            lives--;
        }

        //ith element van tries gelijkstellen aan waarde van guess in deze iteration
        tries[i] = guess;

        //Als het alle unieke karakters guessed zijn, door iedere iteration unique-- te doen
        //kunnen we ervanuitgaan dat het word guessed is
        if (unique == 0)
        {
            guessed = true;
        }
    }

    if (lives == 0)
    {
        system("clear");

        printf("\n    #  G A L G J E  #   \n");
        print_art(lives);
        printf("Jammer, je bent af.\n\n");
    }
    if (guessed == true)
    {
        system("clear");

        printf("\n   # ! G A L G J E ! #  \n");
        print_art(lives);
        printf("Gefeliciteerd, het word was '%s'\n\n", word);
    }

    free(word);


return 0;
}

char* ask_input(void)
{
    word = malloc(MAX);
    printf("\n       # HANGMAN #       \n");
    printf("player %c geef een word op: ...\n", player);
    scanf(" %s", word);

    system("clear");

    return word;
}

int count_unique_char(char* str)
{
//Tel het aantal unieke karakters in de string;
int c = 0;//initialiseer teller c op 0
int i;
int j;

for (i = 0; str[i] != '\0'; i++)//iteriate door de string
{
    for (j = 0; j < i; j++)
    {
        if (str[i] == str[j])//is word[ith element] gelijk aan word[letter op plek j, dus onder i]
        {
            break;//stoppen
        }
    }
    if (j == i)
        {
            c++;// je en i zijn gelijk, dus teller plus 1
        }
}
return c;
}

void print_art(int l)
{
    printf(":::::::::::::::::::::\n");
    switch (l)
    {
        case 6:
            printf(":::::::.......:::::::\n");
            printf(":::::::.......:::::::\n");
            printf(":::::::.......:::::::\n");
            break;
        case 5:
            printf(":::::::...o...:::::::\n");
            printf(":::::::.......:::::::\n");
            printf(":::::::.......:::::::\n");
            break;
        case 4:
            printf(":::::::.\\.o...:::::::\n");
            printf(":::::::.......:::::::\n");
            printf(":::::::.......:::::::\n");
            break;
        case 3:
            printf(":::::::.\\.o./.:::::::\n");
            printf(":::::::.......:::::::\n");
            printf(":::::::.......:::::::\n");
            break;
        case 2:
            printf(":::::::.\\.o./.:::::::\n");
            printf(":::::::...|...:::::::\n");
            printf(":::::::.......:::::::\n");
            break;
        case 1:
            printf(":::::::.\\.o./.:::::::\n");
            printf(":::::::...|...:::::::\n");
            printf(":::::::./.....:::::::\n");
            break;
        case 0:
            printf("!:::::X.\\.o./.X:::::!\n");
            printf("!:::::X...|...X:::::!\n");
            printf("!:::::X../.\\..X:::::!\n");
            break;
    }
    printf(":::::::.......:::::::\n");
}