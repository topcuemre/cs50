#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* asks user the dollar value */
    int counter = 0;
    float dollars;
    do
    {
        float dollars = get_float("Change owed :\n");
        // converts dollars to cents
    } 
    while (!(dollars > 0.));
    
    float cents = dollars * 100 ;
    // main idea of greedy algorithms that in cashier problem you have to get rid of the largest cents before the smaller ones
    while (cents -25 >= 0.)
    {
        printf("da");
        cents = cents - 25;
        counter++;
    }
    printf("%i\n", counter);
    
}