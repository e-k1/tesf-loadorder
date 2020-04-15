#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tesf.h"

int interface(char * mods[1024],char * data[1024])
    {
    int i,x,y,u_input,hlight,page;


    initscr();
    keypad(stdscr,TRUE);
    curs_set(0);
    cbreak();
    noecho();


    getmaxyx(stdscr,y,x);

    WINDOW * win_left = newwin(y,2*x/5,0,0);
    WINDOW * win_center = newwin(y,2*x/5,0,2*x/5);
    WINDOW * win_right = newwin(y,x/5,0,4*x/5);
    WINDOW * win_active;

    refresh();

    print_win(mods,win_left,0);
    print_win(data,win_center,0);
    print_instructions(win_right);


    win_active = win_left;
    hlight = 0;
    page = 0;

    while(1)
        {
        drawpoint(win_active,hlight);
    
        u_input = getch();

        if(u_input==KEY_DOWN || u_input=='j')
            {
            if(hlight < y-3) 
                {
                hlight++;
                }
            else
                {
                hlight=0;
                page++;
                print_win(mods,win_left,page);
                print_win(data,win_center,page);
                }

            drawpoint(win_active,hlight);
            }
        else if(u_input==KEY_UP || u_input=='k')
            {
            if(hlight > 0) 
                {
                hlight--;
                }
            else
                {
                hlight=y-3;
                page--;
                print_win(mods,win_left,page);
                print_win(data,win_center,page);
                }

            drawpoint(win_active,hlight);
            }
        else if(u_input==KEY_RIGHT || u_input==KEY_LEFT || u_input=='h' || u_input=='l')
            {
            if(win_active==win_left)
                {
                drawpoint(win_active,-10);
                win_active = win_center;
                }
            else if(win_active==win_center) 
                {
                drawpoint(win_active,-10);
                win_active = win_left;
                }
            wrefresh(win_left);
            wrefresh(win_center);
            }       
        else if(u_input=='\n')
            {
            if(win_active==win_left)
                {
                activate(mods,data,hlight+page*(y-2));
                }
            else if(win_active==win_center)
                {
                activate(data,mods,hlight+page*(y-2));
                }
            print_win(mods,win_left,page);
            print_win(data,win_center,page);
            }
        else if(u_input == ' ')
            {
            //
            }
        else if(u_input=='q')
            {
            break;
            }

        }

    endwin();
    return 0;

    }


void print_win(char * array[1024],WINDOW * win,int page)
    {
    int i,file;
    
    wclear(win);
    box(win,0,0);

    i=1;
    file=page*(getmaxy(win)-2);

    for(i=1;i<getmaxy(win)-1;i++)
        {
        if(array[file]==NULL) 
            {
            break;
            }
        else
            {
            mvwprintw(win,i,6,"%d. %s",file+1,array[file]);
            file++; 
            }
        }

    wrefresh(win);
    
    }

void print_instructions(WINDOW * win)
    {
    mvwprintw(win,2,2,"Use arrow keys or");
    mvwprintw(win,3,2,"vim keys to navigate");

    mvwprintw(win,5,2,"Activate and deactivate");
    mvwprintw(win,6,2,"mods with ENTER key");

    mvwprintw(win,8,2,"Change loadorder");
    mvwprintw(win,9,2,"with SPACEBAR");

    mvwprintw(win,11,2,"s : apply changes");
    mvwprintw(win,12,6,"and quit");

    mvwprintw(win,14,2,"q : quit");
    wrefresh(win);
    }


void drawpoint(WINDOW * win,int point)
    {
    int i,w_hight;

    w_hight = getmaxy(win);

    for(i=0;i<w_hight-2;i++) {mvwprintw(win,i+1,2,"   ");}

    mvwprintw(win,point+1,2,">>>");

    wrefresh(win);
    }

