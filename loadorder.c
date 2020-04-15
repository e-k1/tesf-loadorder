#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <malloc.h>
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

    if(mod < place)  //=siirtyy alas päin paikalta mod paikalle place --> i kasvaa
        {
        for(i=mod;i<place;i++)
            {
            array[i] = array[i+1];
            }
        array[place] = temp;
        }
    else if(mod > place) //siirtyy ylös päin --> i pienenee
        {
        for(i=mod;i>place;i--)
            {
            array[i] = array[i-1];
            }
        array[place] = temp;
        }

    }
