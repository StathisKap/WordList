#include <stdio.h>
#include <unistd.h>
#include "encrypt.h"

int main(int argc , char * argv[])
{
    char ch;
    char word[20], line[150];
    int encryption = 0, list = 0;

    FILE *in = fopen(argv[1],"r");
    FILE *out = fopen(argv[2],"a");

    while ((ch = getopt(argc,argv,"el"))!= EOF)
        switch (ch)
        {
            case 'e':
                encryption = 1;
            break;
            case 'l':
                list = 1;
            break;
            default:
                fprintf(stderr,"Error - unknown option");
            return 1;
        }
    argc -= optind;
    argv += optind;

    if (list == 0)
    {
        while (EOF && fscanf(in, "%149[^\n]\n", line)==1) 
        {
            if(encryption == 1)
            encrypt(line);
            fprintf(out,"%s\n",line);
        }
    }
    else
    {
        while (EOF && fscanf(in, "%19s", word)==1)
        {
            if(encryption == 1)
            encrypt(word);
            fprintf(out,"%s\n",word);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}