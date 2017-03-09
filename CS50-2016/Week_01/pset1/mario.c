#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int h;
    printf("How tall should be the pyramid? (max height of 23)\n");
    do
    {
        h = GetInt();
        if (h < 0 || h > 23)
        {
            printf("Please, type a number between 0 and 23.\n");
        }
    }while (h < 0 || h > 23);
    
    int yh = h, zh = 2;
    
    for (int x = 0;x < h;x++)
    {
        for (int y = (yh-1); y > 0;y--)
        {
            //printf("y = %i", y);
            printf(" ");
        }
        yh--;
        
        for (int z = 0; z < zh;z++)
        {
            //printf("z = %i", z);
            printf("#");
        }
        zh++;
        printf("\n");
    }
}
