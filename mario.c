#include <stdio.h>
#include <cs50.h>
//This programs creates the magnificent mountains of mario
int main(void)
{
    int cntr = 0;
    int n, height;
    //in this part program asks the height of pyramid user wants to create
    do
    {
        /* do loop is executed at least one time even if the while condition is not met */
        int height = get_int("Height:\n");
        if (height >= 1 && height <= 8)
        {
            int n = height;
            for (int i = 0 ; i < height ; i++)
            {
                for (int j = 1; j < n ; j++)
                {
                    printf(" ");
                }
                cntr++;
                for (int k = 1; k <= cntr; k++)
                {
                    printf("#");
                }
                n--;
                printf("\n");
            }
            break;
        };/* program prompts simultaneously until a valid input of height is given */
    } 
    while (!(height >= 1 && height <= 8)); 
}