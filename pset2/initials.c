#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
    char name[128] = "";
    strcat(name, GetString());
    char x[5] = "";
    name[0] = toupper(name[0]);
    strncat(x, &name[0], 1);
    for (int i = 1, l = strlen(name); i < l; i++)
        {
            char b[2];
            b[0] = name[i];
            if (strcmp(b, " ") == 0)
                {
                  name[i+1] = toupper(name[i+1]);
                  strncat(x, &name[i+1], 1);
                }
        }
    printf("%s\n", x);
    return 0;
}