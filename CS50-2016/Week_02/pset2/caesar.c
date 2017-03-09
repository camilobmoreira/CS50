#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2) //Checks if number of command-line arguments is valid
    {
        printf ("usage: ./caesar + key \n");
        return 1;    
    }
    int k = atoi(argv[1]);      //Converts argument to int
    if (k < 0) return 1;        //Checks if it's a non-negative number
    if (k > 26) k = k % 26;     //Converts the key to a number between 0 and 26 if greater than 
    
    //printf("Inform the message you want to encrypt: \n");
    string msg = GetString();
    
    char encMsg[strlen(msg)];
    strcpy(encMsg, msg);
    
    
    for (int x = 0; x < strlen(msg); x++) 
    {
        //if (msg[x] == ' ') encMsg[x] = msg[x];
        if (msg[x] < 65 || (msg[x] > 90 && msg[x] < 97) || msg[x] > 122) encMsg[x] = msg[x];
        else if ((msg[x] + k >= 65 && msg[x] + k <= 90) || (msg[x] + k >= 97 && msg[x] + k <= 122)) encMsg[x] = msg[x] + k;
        else encMsg[x] = msg[x] + k - 26;
    }
    
    printf("%s\n", encMsg);
    
    return 0;
}