#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

//Create GetPosInt() function
int GetPosInt(void)
{
    int n = GetInt();
    while (n < 0) {
        printf("That won't work...\nRetry: ");
        n = GetInt();
    }
    if (n == 0) {
        return 0;
    }
    return n;
}

int main(void) {
    printf("How high should Mario's pyramid be?\nHeight: ");
    int h = GetPosInt();
    while (h > 23) {
        printf("Try something smaller!\nHeight: ");
        h = GetPosInt();
    } 
    char str[128] = "";
    strcat(str, "##");
    char strad[] = "#";
    int l = h + 1;
    for (int i = 0; i < h; i++) {
        printf("%*s\n", l, str);
        strcat(str, strad);
    }
    return 0;
}
