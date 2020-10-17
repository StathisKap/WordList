#include <stdio.h>

int main()
{
    char word[20];
    while (scanf("%s",word)==1)
    {
        printf("%s\n",word);
    }
    return 0;
}