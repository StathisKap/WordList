#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "encrypt.h"

int main(int argc , char * argv[])
{
    char ch;
    char word[20], line[150], fileType[3], fileName[30];
    int encryption = 0, list = 0;

    FILE *in = fopen(argv[1],"r");
    strcpy(fileType,"a");
    strcpy(fileName,argv[2]);

    while ((ch = getopt(argc,argv,"el"))!= EOF)
        switch (ch)
        {
            case 'e':
                encryption = 1;
                strcpy(fileType,"w");
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

    FILE *out = fopen(fileName,fileType);

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