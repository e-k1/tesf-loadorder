
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <malloc.h>
#include <ncurses.h>
#include "tesf.h"

int main()
    {
    int i;

    char * modlist[1024];
    char * datafiles[1024];
    char * uninst[1024];

    getmods(modlist);
    getdata(datafiles);
    getuninst(uninst,datafiles,modlist);


    interface(modlist,uninst);


    return 0;
    }


