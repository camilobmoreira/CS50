#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
    Use this to compile 
    
    clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack
    
*/


int main(int argc, char *argv[])
{
    if (argc != 2) //Checks if number of command-line arguments is valid
    {
        printf ("usage: ./crack + hash \n");
        return 1;    
    }
    
    char *hash = argv[1]; //Gets hash passed as argument
    
    char salt[3]; //Gets the salt
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';
    
    
    
    const char *const seedchars = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    char text[5] = "\0"; //Text that is gonna be tried with crypt()
    
    for (int d = 0; d <= 64 ; d++)
    {
        if(d > 0) 
        {
            text[4] = '\0';
            text[3] = seedchars[d];
        }
        
        for (int c = 0; c <= 64 ; c++)
        {
            //printf("c: %d\n", c);
            
            if(c > 0) 
            {
                if (d == 0)
                {
                    text[3] = '\0';
                }
                text[2] = seedchars[c];
            }
            
            for (int b = 0; b <= 64 ; b++)
            {
                //printf("b: %d\n", b);
                    
                if(b > 0)
                {
                    if (c == 0 && d == 0) 
                    {
                        text[2] = '\0';
                    }
                    text[1] = seedchars[b];
                }
                
                for (int a = 0; a <= 64 ; a++)
                {
                    //printf("a: %d\n", a);
                    
                    if(b == 0 && c == 0 && d == 0)
                    {
                        text[1] = '\0';
                    }
                    
                    text[0] = seedchars[a];
                    
                    char *password = crypt(text, salt);
                    
                    if (strcmp(hash, password) == 0) 
                    {
                        printf("%s\n", text);
                        return 0;
                    }
                }   
            }   
        }
    }
    
    return 1;
}