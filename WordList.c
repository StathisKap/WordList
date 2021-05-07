#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "encrypt.h"
#include "Word_Instances.h"
#include "List.h"


int main(int argc , char * argv[])
{
    char ch;
    char word[20], line[150], fileType[3], fileName[30];
    int encryption = 0, list = 0;
//
//Set the default for the out file as append+ and the second argument given
//
    FILE *in = fopen(argv[1],"r");
    strcpy(fileType,"a+");
    strcpy(fileName,argv[2]);

    while ((ch = getopt(argc,argv,"elw"))!= EOF)
        switch (ch)
        {
            case 'e': //Encryption Option
                encryption = 1;
                strcpy(fileType,"w");
            break;
            case 'l': //List Option
                list = 1;
            break;
            case 'w': // write the file instead of appending to it
                strcpy(fileType,"w");
            break;
            default: //If something else is given, give an error
                fprintf(stderr,"Error - unknown option");
            return 1;
        }

    argc -= optind;
    argv += optind;

    FILE *out = fopen(fileName,fileType);


//
// Check which options are chosen and call the appropriate Functions
//
    if (list == 0)
    {
        while (EOF && fscanf(in, "%149s[^\n]\n", line)==1) 
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
            {
                encrypt(List(out,word));
                fprintf(out,"%s\n",List(out,word));
            }
            else
            fprintf(out,"%s\n",List(out,word));
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}