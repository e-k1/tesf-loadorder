#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "dcc.h"

int interface(char * mods[1024],char * data[1024])
    {
    int i,x,y,u_input,hlight=0;


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

    print_win(mods,win_left);
    print_win(data,win_center);
    print_instructions(win_right);


    win_active = win_left;

    while(1)
        {
        drawpoint(win_active,hlight);
    
        u_input = getch();

        if(u_input==KEY_DOWN || u_input=='j')
            {
            if(hlight != y-1) {hlight++;}
            drawpoint(win_active,hlight);
            }
        else if(u_input==KEY_UP || u_input=='k')
            {
            if(hlight!=0) {hlight--;}
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
        else if(u_input=='q')
            {
            break;
            }

        }

    endwin();
    return 0;

    }


void print_win(char * array[1024],WINDOW * win)
    {
    int i;
    
    wclear(win);
    box(win,0,0);

    for(i=0;i<getlen(array);i++)
        {
        mvwprintw(win,i+1,6,"%d. %s",i+1,array[i]);
        }

    wrefresh(win);
    
    }

void print_instructions(WINDOW * win)
    {
    mvwprintw(win,2,2,"Use arrow keys or");
    mvwprintw(win,3,2,"vim keys to navigate");

    mvwprintw(win,5,2,"activate and deactivate");
    mvwprintw(win,6,2,"mods with ENTER key");

    mvwprintw(win,8,2,"s : apply changes");
    mvwprintw(win,9,6,"and quit");

    mvwprintw(win,11,2,"q : quit");
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

