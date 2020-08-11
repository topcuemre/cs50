#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

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
        if (k[i] >= 65 && k[i] <= 90)
        {
            k[i] = ((int)k[i] + val % 26);
        }
        
        else if (k[i] >= 97 && k[i] <= 122)
        {               
            k[i] = ((int)k[i] + val % 26);
        }
        else
        {
            continue;
        }
    }
    printf("ciphertext: %s\n",k);
}