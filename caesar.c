#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("error occured\n");
        return 1;
    }
    else
    {
        printf("Success\n");
    }
    for (int i = 0; i < strlen(argv[1]) ; i++)
    {
        if (!(argv[1][i] <= '9' && argv[1][i] >= '0'))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
        else
        {
            break;
        }
    }
    int cntr = (int)argv[1];
        string k = get_string("plaintext:");
        for (int i = 0; i < strlen(k); i++ )
        {
            if (k[i] >= 65 && k[i] <= 90)
            {
                k[i] = (k[i] + cntr) % 26;
            }
            
            else if (k[i] >= 97 && k[i] <= 122)
            {
                k[i] = (k[i] + cntr) % 26;
            }
            else
            {
                continue;
            }
            
        }
        
        printf("ciphertext: %s\n",k);
    
}