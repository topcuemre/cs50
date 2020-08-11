#include <stdio.h>
#include <cs50.h>
/*this program asks the user his/her name then greets*/
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello,%s\n", name);
}