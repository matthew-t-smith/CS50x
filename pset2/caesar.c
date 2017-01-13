#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    //This part just makes sure there are the appropriate
    //  number of command-line arguments. 
   
    if (argc != 2 || argv[1] == NULL || atoi(argv[1]) <= 0)
    {
        printf("Try again!\n");
        return 1;
    }

    //Start of cipher
    
    string caesar = GetString();
    int k = atoi(argv[1])%26;
    
    for (int i = 0, n = strlen(caesar); i < n; i++)
    {
        int c = caesar[i];
        int r = c + k;
        
        //Figure out if upper or lower case alpha, else return character
        
        if (64 < c && c < 91) {
            if (r > 90) {
                printf("%c", caesar[i] + k - 26);
            } else {
            printf("%c", caesar[i] + k);
            }
        } else if (96 < c && c < 123) {
            if (r > 122) {
                printf("%c", caesar[i] + k - 26);
            } else {
            printf("%c", caesar[i] + k);
            }
        } else {
            printf("%c", caesar[i]);
        }
    }
    printf("\n");
    return 0;
}