#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int minutes;
    printf("How long does your showers usually take?\n");
    do
    {
        minutes = GetInt();
        if (minutes < 0)
        {
            printf("Please, type a positive number.\n");
        }
    }while (minutes < 0);
    printf("Your showers usually use %i bottles of water\n", minutes*12);
}
