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

    if(fopen(config_file,"r")==NULL) {return 0;}

    pathfile = fopen(config_file,"r");

    while(getline(&temp,&linesize,pathfile) != -1)
        {
        if(strstr(temp,game))
            {
            strncpy(game_path,temp,strlen(temp)-1);
            found=1;
            break;
            }
        }
    fclose(pathfile);

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

    return 1;
    }


void addpath()
    {
    char temp_path[512];

    printf("Insert path to your game's data directory (.../steamapps/common/<game>/Data/)\n\n"); 
    scanf("%[^\n]%*c",temp_path);

    if(opendir(temp_path)==NULL)
        {
        printf("\nData files not found!\nMake sure your game is installed and you entered the correct path\n\n");
        }
    else
        {
        FILE * pathfile;
        pathfile = fopen(config_file,"a");

        fprintf(pathfile,"%s\n",temp_path);

        fclose(pathfile);

        printf("\nSuccess!\nRelaunch the program to manage plugins\n\n");
        }
    }

