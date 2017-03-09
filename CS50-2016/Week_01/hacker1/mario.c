#include <stdio.h>
#include <cs50.h>

int main ()
{
    int h = -1;
    printf("How tall should be the pyramid? (max height of 23)\n");
    while (h < 0 || h > 23)
    {
        h = GetInt();
        if (h < 0 || h > 23) printf("Please, type a number between 0 and 23.\n");
    }
    
    int yh = h, zh = 1;
    
    for (int x = 0;x < h;x++)
    {
        int op = 0;
        for (int y = (yh-1); y > 0;y--) printf(" ");
        yh--;
        
        for (int z = 0; z <= zh;z++)
        {
            printf("#");
            if (z == zh-1 && op == 0) 
            {
                printf("  ");
                z = 0;
                op++;
            }
        }
        zh++;
        printf("\n");
    }
    return 0;
}