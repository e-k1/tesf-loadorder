
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <malloc.h>
#include <ncurses.h>
#include "tesf.h"

int main(int argc,char * argv[])
    {
    if(argc!=2)
        {
        print_help();
        return 0;
        }
    else if(strcmp(argv[1],"Skyrim")!=0 && strcmp(argv[1],"Skyrim_SE")!=0 && strcmp(argv[1],"Oblivion")!=0 && strcmp(argv[1],"Fallout_3")!=0 && strcmp(argv[1],"Fallout_NV")!=0)
        {
        print_help();
        return 0;
        }

    if(findpath(argv[1])==0)
        {
        addpath();
        return 0;
        }

    int svq;

    char * modlist[1024];
    char * datafiles[1024];
    char * uninst[1024];


    getmods(modlist);
    getdata(datafiles);
    getuninst(uninst,datafiles,modlist);


    svq = interface(modlist,uninst);

    if(svq==1)
        {
        save_changes(modlist);
        }

    return 0;
    }


void print_help()
    {
    printf("Usage: tesf <game>\n\n");
    printf("Supported games:\n\n\tSkyrim\n\tSkyrim_SE\n\tOblivion\n\tFallout_3\n\tFallout_NV\n\n");
    }


void save_changes(char * array[1024])
    {
    int i;
    char temp[128];

    FILE * modfile;
    modfile = fopen(plugin_file,"w");

    for(i=0;i<getlen(array);i++)
        {
        strcpy(temp,array[i]);
        fprintf(modfile,"%s\n",temp);
        }

    fclose(modfile);
    }
