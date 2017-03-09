#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float chg_owed_f;
    int coins = 0, chg_owed_i;
    printf("How much change is owed?\n");
    do
    {
        chg_owed_f = GetFloat();
        
        if (chg_owed_f < 0)
        {
            printf("Please inform a valid number (greater than 0).\n");
        }
    }while (chg_owed_f < 0);
    
    chg_owed_i = (int) round(chg_owed_f*100);
    
    while (chg_owed_i > 0)
    {
        if (chg_owed_i >= 25)
        {
            chg_owed_i = chg_owed_i - 25;
            coins++;
        }
        else if (chg_owed_i >= 10)
        {
            chg_owed_i = chg_owed_i - 10;
            coins++;
        }
        else if (chg_owed_i >= 5)
        {
            chg_owed_i = chg_owed_i - 5;
            coins++;
        }
        else if (chg_owed_i >=1)
        {
            chg_owed_i = chg_owed_i - 1;
            coins++;
        }
    }
    printf("%i\n",coins);
}
