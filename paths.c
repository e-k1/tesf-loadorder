
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <malloc.h>
#include <ncurses.h>
#include "tesf.h"




int findpath(char * game)
    {
    FILE * pathfile;

    int found=0;

    char * pluginfile_path;
    char * temp;
    char temp_path[512];
    size_t linesize;

    pathfile = fopen("/home/elmo/.config/tesf-loadorder/paths.txt","r");

    if(strcmp(game,"Skyrim")==0)
        {
        pluginfile_path = skyrim_p;
        }
    else if(strcmp(game,"Oblivion")==0)
        {
        pluginfile_path = oblivion_p;
        }


    while(getline(&temp,&linesize,pathfile) != -1)
        {
        if(strstr(temp,game))
            {
            strncpy(game_path,temp,strlen(temp)-1);
            found=1;
            break;
            }
        }

    if(found==0) {return 0;}

    strcpy(temp_path,game_path);

    strcat(plugin_file,"/");
    strcat(plugin_file,strtok(temp_path,"/"));

    while(1)
        {
        if(strstr(plugin_file,"steamapps"))
            {
            strcat(plugin_file,pluginfile_path);
            break;
            }
        else
            {
            strcat(plugin_file,"/");
            strcat(plugin_file,strtok(NULL,"/"));
            }
        }

    fclose(pathfile);
    return 1;
    }


void addpath()
    {
    printf("Insert path to data folder (.../steamapps/common/<game>/Data/)\n\n"); 

    scanf("%s",&game_path);

    FILE * pathfile;
    pathfile = fopen("/home/elmo/.config/tesf-loadorder/paths.txt","a");

    fprintf(pathfile,"%s\n",game_path);

    fclose(pathfile);

    }
