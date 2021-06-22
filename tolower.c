#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file;
    if(argc==3)
    {
        file = fopen(argv[2], "r+");
    }
    char line[1024];
    while(fgets(line, 1024, file)!=NULL)
    {
        int len = strlen(line);
        for(int i=0;i<len;i++)
        {
            if(line[i]>=65&&line[i]<=90)
            {
                line[i]+=32;
            }
        }
        printf("%s\n",line);
    }
    fclose(file);
}