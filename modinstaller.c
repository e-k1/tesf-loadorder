#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ncurses.h>
#include "tesf.h"


void inst_mod(char * src,char * dest)
    {
    int x,y;
    getmaxyx(stdscr,y,x);

    DIR * mdr;
    struct dirent * fil;
    char temp_file[128];
    char temp_src[512];
    char temp_dir[512];
    char temp_dest[512];

    mdr = opendir(src);

    while(fil = readdir(mdr))
        {
        strcpy(temp_src,src);
        strcpy(temp_dir,src);
        strcpy(temp_dest,dest);
        strcpy(temp_file,fil->d_name);

        strcat(temp_dir,temp_file);
        strcat(temp_dir,"/");

        if(strcmp(temp_file,".")==0 || strcmp(temp_file,"..")==0);
        else if(strstr(temp_file,".zip") || strstr(temp_file,".7z") || strstr(temp_file,".rar"))
            {
            strcat(temp_src,temp_file);
            remove(temp_src);
            }
        else 
            {
            if(opendir(temp_dir)!=NULL)
                {
                if(strcmp(temp_file,"Data")!=0)
                    {
                    strcat(temp_dest,temp_file);
                    strcat(temp_dest,"/");
                    }
                dir_check(temp_dest);
                inst_mod(temp_dir,temp_dest);
                }
            else
                {
                strcat(temp_src,temp_file);
                strcat(temp_dest,temp_file);
                mvprintw(y-2,0,"%s",temp_dest);
                rename(temp_src,temp_dest);
                }
            }
        }

    closedir(mdr);

    remove(src);

    }


void dir_check(char * dir)
    {
    if(opendir(dir)==NULL)
        {
        mkdir(dir,0777);
        }
    }


void cap(char * src)
    {
    DIR * mdr;
    struct dirent * fil;
    char temp_name[128];
    char temp_src[512];
    char temp_dir[512];

    mdr = opendir(src);

    while(fil = readdir(mdr))
        {
        strcpy(temp_src,src);
        strcpy(temp_dir,src);
        strcpy(temp_name,fil->d_name);

        strcat(temp_dir,temp_name);

        if(strcmp(temp_name,".")==0 || strcmp(temp_name,"..")==0);
        else 
            {
            if(opendir(temp_dir)!=NULL)
                {
                if('a' <= temp_name[0] && temp_name[0] <= 'z')
                    {
                    temp_name[0]=temp_name[0]-32;
                    }
                strcat(temp_src,temp_name);
                rename(temp_dir,temp_src);
                strcat(temp_src,"/");
                cap(temp_src);
                }
            }
        }
    closedir(mdr);
    }

