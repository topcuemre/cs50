#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
//this is caesar cipher program
int main(int argc, string argv[])
{
    if (argc != 2)
//checks if there are more than one main func parameter
    {
        printf("error occured\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]) ; i++)
//checks that is there a non decimal number 
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
    for (int i = 0; i < a; i++)
    {
        if (k[i] >= 65 && k[i] <= 90)
        {
            k[i] = ((int)k[i] - 65 + val) % 26 + 65; 
// getting A to the index 0
        }
        
        else if (k[i] >= 97 && k[i] <= 122)
        {               
            k[i] = ((int)k[i] - 97 + val) % 26 + 97;
// getting a to the index 0
        }
        else
        {
            continue;
        }
    }
    printf("ciphertext: %s\n", k);
}