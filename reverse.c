#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file;
    if(argc==3)
    {
        file = fopen(argv[2], "r");
    }
    char *line = malloc(sizeof(char)*1024);
    char **word=malloc(sizeof(char*)*1024);
    for(int i=0;i<1024;i++)
    {
        *(word+i) = malloc(sizeof(char)*1024);
    }
    int j=0;
    int len=0;
    while(fgets(line, 1024, file)!=NULL)
    {
        line[strcspn(line,"\n")]='\0';
        strcpy(word[j],line);
        j++;
    }
    fclose(file);
    file = fopen(argv[2],"w+");
    for(int y=j-1;y>=0;y--)
    {
        len = strlen(word[y]);
        for(int k=len-1;k>=0;k--)
        {
            fprintf(file, "%c", word[y][k]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
    free(line);
    free(word);
}