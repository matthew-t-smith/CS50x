#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

//Create GetPosFloat() function
float GetPosFloat(void)
{
    float n = GetFloat();
    while (n < 0) {
        printf("Looks like you still owe some money. \nPay, then retry: ");
        n = GetFloat();
    }
    if (n == 0) {
        printf("Exact change! Thanks for shopping.\n");
        return 0;
    }
    return n;
}

int main(void) {
    printf("How much change is owed?: $");
    float x = GetPosFloat();
    double y = round(x * 100);
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;
    if (y / 25 > 0) {
        q = floor(y / 25);
        y = (y - 25*q);
    }
    if (y / 10 > 0) {
        d = floor(y / 10);
        y = (y - 10*d);
    }
    if (y / 5 > 0) {
        n = floor(y / 5);
        y = (y - 5*n);
    }
    p = y;
    int c = q + d + n + p;
    printf("%i\n", c);
}