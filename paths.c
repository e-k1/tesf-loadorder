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


void addpath(char * game)
    {
    char temp_path[512];
    char * todir;

    printf("Insert path to game library (.../steamapps/common/)\n\n"); 
    scanf("%s",temp_path);

    if(strstr(temp_path,"common")==NULL)
        {
        strcat(temp_path,"/incorect_path/common");  //this error will be dealt with later
        }

    strcat(game_path,"/");
    strcat(game_path,strtok(temp_path,"/"));

    while(strstr(game_path,"common")==NULL)
        {
        strcat(game_path,"/");
        strcat(game_path,strtok(NULL,"/"));
        }


    if(strcmp(game,"Skyrim")==0)
        {
        strcat(game_path,"/Skyrim/Data/");
        }
    else if(strcmp(game,"Oblivion")==0)
        {
        strcat(game_path,"/Oblivion/Data/");
        }
    else if(strcmp(game,"Fallout4")==0)
        {
        strcat(game_path,"/Fallout 4/Data/");
        }
    else if(strcmp(game,"Fallout3")==0)
        {
        strcat(game_path,"/Fallout 3 goty/Data/");
        }
    else if(strcmp(game,"FalloutNV")==0)
        {
        strcat(game_path,"/Fallout New Vegas/Data/");
        }
    else if(strcmp(game,"SkyrimSE")==0)
        {
        strcat(game_path,"/Skyrim Special Edition/Data/");
        }


    if(opendir(game_path)==NULL)
        {
        printf("\nData folder not found!\nMake sure your game is installed and you entered the correct path\n\n");
        }
    else
        {
        FILE * pathfile;
        pathfile = fopen(config_file,"a");

        fprintf(pathfile,"%s\n",game_path);

        fclose(pathfile);

        printf("\nSuccess!\nRelaunch the program to manage plugins\n\n");
        }

    }


