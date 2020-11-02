#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"

char * List(FILE *output, char * word)
{
    char * word2 = (char*)malloc(20);
    size_t i;
    for (i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            word2[i] = tolower(word[i]);
        }
        else
        word++;
    }
        word2[i] = '\0'; 
    
    // fprintf(output,"%s\n",word2);
    return word2;
}