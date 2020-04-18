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
    else if(strcmp(game,"SkyrimSE")==0)
        {
        game = "Skyrim Special Edition";
        pluginfile_path = skyrimse_p;
        }
    else if(strcmp(game,"Oblivion")==0)
        {
        pluginfile_path = oblivion_p;
        }
    else if(strcmp(game,"Fallout4")==0)
        {
        game = "Fallout 4";
        pluginfile_path = fallout4_p;
        }
    else if(strcmp(game,"Fallout3")==0)
        {
        game = "Fallout 3 goty";
        pluginfile_path = fallout3_p;
        }
    else if(strcmp(game,"FalloutNV")==0)
        {
        game = "Fallout New Vegas";
        pluginfile_path = falloutnv_p;
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


void addpath(char * game)
    {
    char temp_path[512];
    char * todir;


    if(strcmp(game,"Skyrim")==0)
        {
        todir = "/Skyrim/Data/";
        }
    else if(strcmp(game,"Oblivion")==0)
        {
        todir = "/Oblivion/data/";
        }
    else if(strcmp(game,"Fallout4")==0)
        {
        todir = "/Fallout 4/Data/";
        }
    else if(strcmp(game,"Fallout3")==0)
        {
        todir = "/Fallout 3 goty/Data/";
        }
    else if(strcmp(game,"FalloutNV")==0)
        {
        todir = "/Fallout New Vegas/Data/";
        }
    else if(strcmp(game,"SkyrimSE")==0)
        {
        todir = "/Skyrim Special Edition/Data/";
        }


    printf("Insert path to game library (.../steamapps/common/)\n\n"); 

    scanf("%s",&temp_path);

    strcat(game_path,"/");
    strcat(game_path,strtok(temp_path,"/"));

    while(1)
        {
        if(strstr(game_path,"common"))
            {
            strcat(game_path,todir);
            break;
            }
        else
            {
            strcat(game_path,"/");
            strcat(game_path,strtok(NULL,"/"));
            }
        }


    FILE * pathfile;
    pathfile = fopen(config_file,"a");

    fprintf(pathfile,"%s\n",game_path);

    fclose(pathfile);

    }


