#include <stdio.h>
#include <unistd.h>
#include "encrypt.h"

int main(int argc, char *argv[])
{
    char ch;
    char word[20];
    int encryption =0;
    FILE *in;
    FILE *out;

    while ((ch = getopt(argc,argv,"i:o:e"))!= EOF)
        switch (ch)
        {
            case 'i':
            in = fopen(optarg,"r");
            break;
            case 'o':
            out = fopen(optarg,"a");
            break;
            case 'e':
            encryption = 1;
            break;
            default:
            fprintf(stderr,"Error");
            return 1;
        }
    argc -= optind;
    argv += optind;

    while (EOF && fscanf(in, "%19s", word)==1){
        if(encryption == 1)
        encrypt(word);
        fprintf(out,"%s\n",word);
    }
    fclose(in);
    fclose(out);
    
    return 0; 
}