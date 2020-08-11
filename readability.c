#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
//this is written in order to determine the grade level of a texy
int main(void)
{
    string text = get_string("Text:\n");
    int lc = 0;
    int wc = 1;
    int sc = 0;
    int X;
    //this for 
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        //helps us to count words 
        if ((text[i] <= 'z' && text[i] >= 'a') || (text[i] <= 'Z' && text[i] >= 'A'))
        {
            lc++;
        }
        //identifies spaces in text as well as word number
        if (text[i] == ' ')
        {
            wc++;
        }
        //gives us the number of sentences in text
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sc++;
        }
        else
        {
            continue;
        }
        
    }
    
    X = round(0.0588 * lc * 100 / wc - 0.296 * sc * 100 / wc - 15.8);
    // this counts letters,words and sentences in the text
    //printf("letters = %i , words = %i , sentences = %i \n",lc,wc,sc);
    //grade scale
    if (X > 16)
    {
        printf("Grade 16+\n");
    }
    if (X > 1 && X <= 16)
    {
        printf("Grade %i\n", X);
    }
    if (X < 1)
    {
        printf("Before Grade 1\n");
    }
}