// /**
//  * helpers.c
//  *
//  * Computer Science 50
//  * Problem Set 3
//  *
//  * Helper functions for Problem Set 3.
//  */
       
#include <cs50.h>

#include "helpers.h"

// /**
//  * Returns true if value is in array of n values, else false.
//  */
bool search(int value, int values[], int n)
{
    if (n <= 0) 
    {
        return false;
    }
    for (int k = 0; k < n; k++) 
    {
        if (values[k] == value) 
        {
            return true;
        }
    }
    return false;
}

// /**
//  * Sorts array of n values.
//  */
void sort(int values[], int n)
{
    bool again = false;
    for (int j = 0; j < n - 2; j++)
    {
        if (values[j] > values[j+1])
        {
            int hold = values[j];
            values[j] = values[j+1];
            values[j+1] = hold;
            again = true;
        }
    }
    if (again)
    {
        sort(values, n);
    }
    return;
}