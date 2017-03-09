#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main()
{
    //printf("Insert your full name: \n");
    char name[255];
    fgets(name, 255, stdin);
    for (int x = 0; name[x] != '\0'; x++)
    {
        if (x == 0 && name[0] != ' ') printf("%c", toupper(name[0]));
        if (x > 0 && name[x-1] == ' ' && isalpha(name[x])) printf("%c", toupper(name[x]));
    }
    printf("\n");
    
    return 0;
}