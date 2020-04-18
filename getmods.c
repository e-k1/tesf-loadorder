#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <malloc.h>
#include <ncurses.h>

#include "tesf.h"



void getmods(char * array[1024])
    {

    FILE * modfile;
    modfile = fopen(plugin_file,"r");

    
    char * temp;
    size_t linesize;

    int i=0,k;

    while(getline(&temp,&linesize,modfile) != -1)
        {
        if(strstr(temp,"#"));
        else if(strlen(temp)<3);
        else if(strstr(temp,"*"))
            {
            array[i] = malloc(1 + strlen(temp));   
            for(k=1;k<strlen(temp)-1;k++)
                {
                strncat(array[i],&temp[k],1);
                }
            i++; 
            }
        else 
            {
            array[i] = malloc(1 + strlen(temp));   
            strncpy(array[i],temp,strlen(temp)-1); 
            i++; 
            }
        }

    fclose(modfile);

    }


void getdata(char * array[1024])
    {
    DIR * datadir = opendir(game_path);
    struct dirent * modfile;

    int i=0;
    while(modfile = readdir(datadir))
        {
        if(strstr(modfile->d_name,".esp") || strstr(modfile->d_name,".esm")) 
            {
            array[i] = malloc(1 + strlen(modfile->d_name));
            strcpy(array[i],modfile->d_name);
            i++;
            }
        }

    closedir(datadir);

    }


void getuninst(char * inactive[1024],char * data[1024],char * mods[1024])
    { 
    int i=0,a,b,match;

    for(a=0;a<getlen(data);a++)
        {
        match=0;

        for(b=0;b<getlen(mods);b++)
            {
            if(strncmp(data[a],mods[b],strlen(data[a]))==0)
                {
                match = 1;
                }
            }

        if(match==0)
            {
            inactive[i] = data[a];
            i++;
            }
        }
    }



int getlen(char * array[1024])
    {
    int l=0;
    while(array[l] != NULL)
        {
        l++;
        }
    return l;
    }

