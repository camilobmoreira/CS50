#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2) //Checks if number of command-line arguments is valid
    {
        printf ("usage: ./caesar + key \n");
        return 1;    
    }
    
    char k[strlen(argv[1])];
    strncpy(k, argv[1], strlen(argv[1]));  //Saves argument into a string

    for (int x = 0; x < strlen(k); x++) 
    {
        if (k[x] < 65 || (k[x] > 90 && k[x] < 97) || k[x] > 122) //Checks if there is any non-alphabetical character in key
        {
            printf ("key must contain only alphabetical characters \n");
            return 1;    
        }
        if (k[x] >= 65 && k[x] <= 90) k[x] = k[x] + 32;
    }
    
    //printf("Inform the message you want to decrypt: \n");
    char msg[255];
    fgets(msg, 255, stdin);
    
    char encMsg[strlen(msg)];
    strncpy(encMsg, msg, strlen(msg)); //Saves the message in the encMsg to allocate memory
    
    
    int y = 0;
    for (int x = 0; x < strlen(msg); x++) 
    {
        if(msg[x] == '\n') msg[x] = '\0';
        if (msg[x] < 65 || (msg[x] > 90 && msg[x] < 97) || msg[x] > 122) encMsg[x] = msg[x];
        //else if (msg[x] >= 65 && msg[x] <= 90 && msg[x] - (k[y] - 97 ) > 90)
        else if (msg[x] >= 97 && msg[x] - (k[y] - 97) < 97)
        {
            encMsg[x] = msg[x] - (k[y] - 97) + 26;
            y++;
        }
        //else if ((msg[x] - (k[y] - 97 ) > 90 && msg[x] - (k[y] - 97 ) < 97) || msg[x] - (k[y] - 97 ) > 122)
        else if ((msg[x] - (k[y] - 97 ) < 65)) // && msg[x] - (k[y] - 97 ) <= 90) || msg[x] - (k[y] - 97 ) > 122)
        {
            encMsg[x] = msg[x] - (k[y] - 97) + 26;
            y++;
        }
        else 
        {
            encMsg[x] = msg[x] - (k[y] - 97);
            y++;
        }
        if (y >= strlen(k)) y = 0;
    }
    
    printf("%s\n", encMsg);
    
    return 0;
}
