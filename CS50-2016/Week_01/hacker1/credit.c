#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

bool validCCNumber(long long cc)
{
    char temp[2];
    int sum = 0, n = 0, x = 1, y = 1;
    char ccNumber[20]; 
    sprintf(ccNumber, "%lld", cc);
    
    for (x = strlen(ccNumber)-1;x >= 0; x--)
    {
        n = ccNumber[x] - '0';
        if (y % 2 == 0) 
        {
            if (n * 2 >= 10) 
            {
                sprintf(temp, "%d", n * 2);
                sum += temp[0] - '0';
                sum += temp[1] - '0';
            }
            else sum += n * 2;
            
        }
        else sum += n;
        y++;
    }
    sprintf(temp, "%d", sum);
    //printf("sum %d \n", sum);
    if (sum % 10 == 0) return true;
    return false;
}

void checkCCCompany(long long cc)
{
    char ccNumber[20]; 
    sprintf(ccNumber, "%lld", cc);
    
    if (!validCCNumber(cc)) printf("INVALID\n");
    else 
    {
        if (ccNumber[0] == '4') printf("VISA\n");
        else if (ccNumber[0] == '5') 
        {
            if (ccNumber[1] == '1' || ccNumber[1] == '2' || ccNumber[1] == '3' || ccNumber[1] == '4' || ccNumber[1] == '5') 
                printf("MASTERCARD\n");
            else printf("INVALID\n");
        }
        else if (ccNumber[0] == '3') 
        {
            if (ccNumber[1] == '4' || ccNumber[1] == '7') printf("AMEX\n");
            else printf("INVALID\n");
        }
        else printf("INVALID\n");
    }
}


int main()
{
    long long cc;
    printf("Inform your credit card number (no hyphens): \n");
    cc = GetLongLong();
    checkCCCompany(cc);
    
    return 0;
}


