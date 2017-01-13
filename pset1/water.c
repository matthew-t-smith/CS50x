#include <stdio.h>
#include <cs50.h>

//Create GetPosInt() function
int GetPosInt(void)
{
    int n = GetInt();
    while (n <= 0) {
        printf("That won't work...\nRetry: ");
        n = GetInt();
    }
    return n;
}

int main(void) 
{
    //Ask user about water usage and output answer in bottles
    printf("How long is your average shower, in minutes?\nMinutes: ");
    int m = GetPosInt();
    printf("Bottles: %i\n", (m*192)/16);
}