int interface(char * mods[1024],char * data[1024]);

void getdata(char * array[1024]);

void getmods(char * array[1024]);

void getuninst(char * inactive[1024],char * data[1024],char * mods[1024]);

void print_win(char * array[1024],WINDOW * win,int page);

void activate(char * src_array[1024],char * dest_array[1024],int file);

void order(char * array[1024],int mod,int place);

void drawpoint(WINDOW * win,int point);

void print_instructions(WINDOW * win);

int order_management(WINDOW * win,char * array[1024],int hlight,int page);

int getlen(char * array[1024]);

int findpath(char * game);

void addpath();

void print_help();

void save_changes(char * array[1024]);



#define skyrimdata "/run/media/elmo/SSD500/ssdsteamL/steamapps/common/Skyrim/Data/"
#define skyrimlo "/run/media/elmo/SSD500/ssdsteamL/steamapps/compatdata/72850/pfx/drive_c/users/steamuser/Local Settings/Application Data/Skyrim/plugins.txt"


char game_path[512];
char plugin_file[512];


#define skyrim_p "/compatdata/72850/pfx/drive_c/users/steamuser/Local Settings/Application Data/Skyrim/plugins.txt"
#define oblivion_p "/common/Oblivion/data/DLCList.txt"
