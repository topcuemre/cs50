#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cntr = 0;
    int height;
    int n;
    
    while (!(height>=1 && height<=8))
    {
        int height = get_int("Height:");
        if (height>=1 && height<=8)
        {
        printf("Stored: %i\n",height);
        int n = height;
         for (int i=0;i<height;i++)
            {
                for (int j=1;j<n;j++)
                    {
                        printf(" ");
                    }
                cntr++;
                for (int k=1;k<=cntr;k++)
                    {
                        printf("#");
                    }
                n--;
                printf("\n");
            }
        }
        
    }
}