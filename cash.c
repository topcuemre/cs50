#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    /* asks user the dollar value */
    float dollars;
    do
    {
        dollars = get_float("Change owed:\n");
    }
    while( dollars < 0);
    int cents = round(dollars * 100);
    int counter = 0;
    while ( cents >  0. )
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