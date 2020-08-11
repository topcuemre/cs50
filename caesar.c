#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("error occured\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]) ; i++)
        {
            if (!(argv[1][i] <= '9' && argv[1][i] >= '0'))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        printf("Success\n");
    }
    string k = get_string("plaintext:");
    int a = strlen(k);
    int val = atoi(argv[1]);
    for (int i = 0; i < a; i++ )
    {
        if (isupper(k[i]))
        {
            k[i] = (k[i] - 65 + val) % 26 + 65;
        }
        
        else if (islower(k[i]))
        {               
            k[i] = (k[i] -65 + val) % 26 + 65;
        }
        else
        {
            continue;
        }
    }
    printf("ciphertext: %s\n",k);
}