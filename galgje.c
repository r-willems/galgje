#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define MAX 64

char* vraag_input(void);
void plaatje(int);
int count_unique_char(char*);

char speler = 'A';
bool geraden = false;
int levens = 6;
char *woord = NULL;
char tries[MAX] = {0};
char guess = 0;

int main(void)
{
    //later proberen met extern bestand
    system("clear");

    woord = vraag_input();

    //Door een int met aantal unieke letters in te stellen hoeft in bijv goedemiddag 
    //de g of de d maar een keer geraden te worden omdat bij een goede raadbeurt uniek-- geeft.
    int uniek = count_unique_char(woord);

    for (int i = 0; levens != 0 && geraden == false; i++)
    {
        printf("Je hebt nog %i levens\n", levens);
        if (i > 0)
        {
            printf("Dit heb je al geprobeerd: %s\n", tries);
        }
        else
        {
            printf("\n");
        }
        plaatje(levens);
        printf("       # GALGJE #       \n");

        //Speler B voert een letter in
        printf("Speler %c, raad een letter: ... \n", speler+1);
        scanf(" %c", &guess);
        system("clear");


        //Als letter al een keer geraden is
        if (strchr(tries, guess) != NULL)
        {
            levens--;
            printf("%c heb je al geprobeerd!\n", guess);
            continue;
        }

        //Als letter goed is.
        if (strchr(woord, guess) != NULL)
        {
            printf("%c is goed!\n", guess);
            uniek--;
        }
        else
        {
            printf("Helaas!\n");
            levens--;
        }

        //ith element van tries gelijkstellen aan waarde van guess in deze iteration
        tries[i] = guess;

        //Als het alle unieke karakters geraden zijn, door iedere iteration uniek-- te doen
        //kunnen we ervanuitgaan dat het woord geraden is
        if (uniek == 0)
        {
            geraden = true;
        }
    }

    if (levens == 0)
    {
        system("clear");

        printf("\n    #  G A L G J E  #   \n");
        plaatje(levens);
        printf("Jammer, je bent af.\n\n");
    }
    if (geraden == true)
    {
        system("clear");

        printf("\n   # ! G A L G J E ! #  \n");
        plaatje(levens);
        printf("Gefeliciteerd, het woord was '%s'\n\n", woord);
    }

    free(woord);


return 0;
}

char* vraag_input(void)
{
    woord = malloc(MAX);
    printf("\n       # GALGJE #       \n");
    printf("Speler %c geef een woord op: ...\n", speler);
    scanf(" %s", woord);

    system("clear");

    return woord;
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
        if (str[i] == str[j])//is woord[ith element] gelijk aan woord[letter op plek j, dus onder i]
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

void plaatje(int l)
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
