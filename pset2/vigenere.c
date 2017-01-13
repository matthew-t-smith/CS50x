#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
    //This part just makes sure there are the appropriate
    //  number of command-line arguments. 
   
    if (argc != 2 || argv[1] == NULL)
    {
        printf("Try again!\n");
        return 1;
    }
    
    for (int z = 0, m = strlen(argv[1]); z < m; z++)
    {
        if (!isalpha(argv[1][z])) 
        {
            printf("Try again!\n");
            return 1;
        };
    }

    //Start of cipher
    
    string phrase = GetString();
    string key = argv[1];
    
    for (int i = 0, j = 0, n = strlen(phrase); i < n; i++)
    {
        int c = phrase[i];
        
        //Figure out if upper or lower case alpha, else return character
        
        if (64 < c && c < 91) {
            char a = toupper(key[j]);
            int k = a % 65;
            int r = c + k;
            
            //If condition for looping past "Z"
            if (r > 90) {
                printf("%c", phrase[i] + k - 26);
            } else {
            printf("%c", phrase[i] + k);
            }
            
            //Incrementing through the key; looping as needed
            if (j < strlen(key) - 1) {
                j++;
            } else {
                j = 0;
            }
        } else if (96 < c && c < 123) {
            char a = toupper(key[j]);
            int k = a % 65;
            int r = c + k;
            
            //If condition for looping past "z"
            if (r > 122 || r < 65) {
                printf("%c", phrase[i] + k - 26);
            } else {
            printf("%c", phrase[i] + k);
            }
            
            //Incrementing through the key; looping as needed
            if (j < strlen(key) - 1) {
                j++;
            } else {
                j = 0;
            }
        } else {
            printf("%c", phrase[i]);
        }
    }
    printf("\n");
    return 0;
}