#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>
#include "tesf.h"

int main(int argc,char * argv[])
    {
    strcpy(config_file,home_dir);
    strcat(config_file,"/.local/share/tesf-loadorder/paths.txt");
    strcpy(mods_dir,home_dir);
    strcat(mods_dir,"/.local/share/tesf-loadorder/");

    if(argc != 2)
        {
        print_help();
        return 0;
        }
    else if(strcmp(argv[1],"Skyrim")!=0 && strcmp(argv[1],"SkyrimSE")!=0 && strcmp(argv[1],"Oblivion")!=0 && strcmp(argv[1],"Fallout3")!=0 && strcmp(argv[1],"FalloutNV")!=0 && strcmp(argv[1],"Fallout4")!=0)
        {
        print_help();
        return 0;
        }

    if(findpath(argv[1])==0)
        {
        addpath();
        return 0;
        }

    strcat(mods_dir,argv[1]);
    strcat(mods_dir,"/");

    int svq;

    char * modlist[1024];
    char * datafiles[1024];
    char * uninst[1024];
    char * installable[1024];


    if(getmods(modlist)==0) {return 0;};
    getdata(datafiles);
    getuninst(uninst,datafiles,modlist);
    getinstallable(installable);

    while(1)
        {
        svq = interface(modlist,uninst);

        if(svq==2)
            {
            installer_ui(installable);
            getdata(datafiles);
            getuninst(uninst,datafiles,modlist);
            }
        else if(svq==1)
            {
            save_changes(modlist,argv[1]);
            return 0;
            }
        else
            {
            return 0;
            }
        }
    }


void print_help()
    {
    printf("Usage: tesf <game>\n\n");
    printf("Supported games:\n\n\tSkyrim\n\tSkyrimSE\n\tOblivion\n\tFallout4\n\tFallout3  (goty)\n\tFalloutNV\n\n");
    }

