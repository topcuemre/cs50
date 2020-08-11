#include <stdio.h>
#include <cs50.h>
#include <math.h>
//this is an instance of greedy algorithm, it is about optimization of coin exchange order
int main(void)
{
    /* asks user the dollar value */
    float dollars;
    do
    {
        dollars = get_float("Change owed:\n");
    }
    while (dollars < 0);
    //to solve imprecision issues we have used round function from math library
    int cents = round(dollars * 100);// 1 dollar = 100 cent
    int counter = 0;
    // we tend to give away the larger coins before the smaller ones
    while (cents >  0.)
    {
        if (cents - 25.0 >= 0.0)
        {
            cents = cents - 25.0;
            counter++;
            
        }
        
        else if (cents - 10.0 >= 0.0)
        {
            cents = cents - 10.0;
            counter++;
        }
        else if (cents - 5.0 >= 0.0)
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