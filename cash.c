#include <stdio.h>
#include <cs50.h>

int main (void)
{
    /* asks user the dollar value */
    int counter = 0;
    float dollars;
    
    float cents = get_float("Change owed:\n") * 100.0 ;
    
    // main idea of greedy algorithms that in cashier problem you have to get rid of the largest cents before the smaller ones
    while ( cents > 0. )
    {
        if (cents - 25.0 >= 0.0)
        {
            cents = cents - 25.0;
            counter++;
            
        }
        
        else if ( cents - 10.0 >= 0.0 )
        {
            cents = cents - 10.0;
            counter++;
            
        }
        
        else if ( cents - 5.0 >= 0.0 )
        {
            cents = cents - 5.0;
            counter++;
        }
        
        else if (cents - 1.0 >= 0.0)
        {
            cents = cents - 1.0;
            counter++;
        }
        
        
    }
    printf("%i\n", counter);
    
} 