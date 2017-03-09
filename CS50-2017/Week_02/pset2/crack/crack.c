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
        return 1; //Retuns 1 (error)
    }
    
    char *hash = argv[1]; //Gets hash passed as argument
    
    char salt[3]; //Gets the salt
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';
    
    
    //All possible characters used in a DES-based hashed password (taken from gnu library)
    const char *const seedchars = " ./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
    
    char text[5] = "\0"; //Text that is gonna be tried with crypt()
    
    
    /* From innermost foor-loop out.
     * It checks for every possible password
     * from 1 up to 8 characteres.
     */
     
                        
    for (int d = 0; d <= 64 ; d++) //To check for passwords of up to 4 characters
    {
        if(d > 0)
        {
            text[4] = '\0'; //Defining null-terminator at index 4    
            text[3] = seedchars[d]; //Iterates through the seedchars list at index 3
        }
        
        for (int c = 0; c <= 64 ; c++) //To check for passwords of up to 3 characters
        {
            if(c > 0) 
            {
                if (d == 0)
                {
                    text[3] = '\0'; //Defining null-terminator at index 3
                }
                text[2] = seedchars[c]; //Iterates through the seedchars list at index 2
            }
            
            for (int b = 0; b <= 64 ; b++) //To check for passwords of up to 2 characters
            {
                if(b > 0)
                {
                    if (c == 0 && d == 0)
                    {
                        text[2] = '\0'; //Defining null-terminator at index 2
                    }
                    text[1] = seedchars[b]; //Iterates through the seedchars list at index 1
                }
                
                for (int a = 0; a <= 64 ; a++) //To check for passwords of up to 1 character
                {
                    if(b == 0 && c == 0 && d == 0)
                    {
                        text[1] = '\0'; //Defining null-terminator at index 1
                    }
                    
                    text[0] = seedchars[a]; //Iterates through the seedchars list at index 0
                    
                    char *password = crypt(text, salt); //Hash var text and save it to var password
                    
                    if (strcmp(hash, password) == 0)  //Compares the hash passed as argv with created above
                    {
                        printf("%s\n", text); //prints the text that led to said hash
                        return 0; //Returns 0 (okay)
                    }
                }   
            }   
        }
    }
                    
    return 1; //Retuns 1 (error)
}
