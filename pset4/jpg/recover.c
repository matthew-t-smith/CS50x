/**
 * recover.c <INCOMPLETE>
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 1)
    {
        printf("Usage: ./recover\n");
        return 1;
    }
    
    // open memory card file
    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("Corrupt file is missing.\n");
        return 2;
    }
    
    FILE* buffer = fopen("buffer.txt", "w");
    
    char* jpgBuffer = malloc(513);
    
    while(fread(jpgBuffer, 512, 1, file) ==1)
    {
        fwrite(jpgBuffer, 512, 1, buffer);
    };
    
    //printf("%c, %c, %c, %c\n", jpgBuffer[0], jpgBuffer[1], jpgBuffer[2], jpgBuffer[3]);
    
    
    
    // for (int i = 0, n = sizeof(card.raw)/512; i < n; i++)
    // {
    //     if (fread(jpgBuffer, 512, 1, file) == 1)
    //     {
    //         if (jpgBuffer == "1110")
    //         {
    //             printf("This is a jpeg.\n");
    //         }  
    //         return 0;
    //     }
    // }
    fclose(file);
    fclose(buffer);
    free(jpgBuffer);
}
