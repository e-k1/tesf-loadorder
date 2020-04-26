#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>
#include "tesf.h"




void activate(char * src_array[1024],char * dest_array[1024],int file)
    {
    int i;

    dest_array[getlen(dest_array)] = src_array[file];

    for(i=file;i<getlen(src_array);i++)
        {
        src_array[i] = src_array[i+1];

        }

    }


void order(char * array[1024],int mod,int place)
    {
    int i;
    char * temp;

    temp = array[mod];

    if(mod < place)  
        {
        for(i=mod;i<place;i++)
            {
            array[i] = array[i+1];
            }
        array[place] = temp;
        }
    else if(mod > place) 
        {
        for(i=mod;i>place;i--)
            {
            array[i] = array[i-1];
            }
        array[place] = temp;
        }

    }


void save_changes(char * array[1024],char * game)
    {
    int i;
    char temp[128];

    FILE * modfile;
    modfile = fopen(plugin_file,"w");

    if(strcmp(game,"SkyrimSE")==0 || strcmp(game,"Fallout4")==0)    
        {
        for(i=0;i<getlen(array);i++)
            {
            strcpy(temp,array[i]);
            fprintf(modfile,"*%s\n",temp);
            }       
        }
    else
        {
        for(i=0;i<getlen(array);i++)
            {
            strcpy(temp,array[i]);
            fprintf(modfile,"%s\n",temp);
            }
        }

    fclose(modfile);
    }

