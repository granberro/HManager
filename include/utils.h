#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>
#include <math.h>
#include "pad.h"

#include <lv2/process.h>
#include <psl1ght/lv2/filesystem.h>
#include <psl1ght/lv2.h>
#include <sys/stat.h>
#include <sys/sysfs.h>

// for msgdialogs
#include <sysutil/events.h>
#include <io/msg.h>

#include <tiny3d.h>
#include <libfont.h>

#include "syscall8.h"

#define FONT_DEFAULT 0
#define FONT_BUTTON  2

#define DT_DIR 1

typedef struct {
    u32 flags;
    char path_name[MAXPATHLEN];
	char title[64];
	char title_id[64];

} t_directories;

typedef struct {
    int index;
    u32 flags;
    char title[64];
    char title_id[64];
} entry_favourites;

typedef struct {
    u32 version;
    entry_favourites list[12];
} tfavourites;

#define MAX_DIRECTORIES 512

extern int ndirectories;
extern t_directories directories[MAX_DIRECTORIES];

extern u32 fdevices;
extern u32 fdevices_old;
extern u32 forcedevices;

extern char hdd_folder[64];
extern char bluray_game[64];
extern float cache_need_free;

void draw_cache_external();

void cls();
void cls2();

char * LoadFile(char *path, int *file_size);
int SaveFile(char *path, char *mem, int file_size);

void DrawDialogOK(char * str);
int DrawDialogYesNo(char * str);

int parse_param_sfo(char * file, char *title_name);
int parse_ps3_disc(char *path, char * id);
int parse_param_sfo_id(char * file, char *title_id);
void utf8_to_ansi(char *utf8, char *ansi, int len);

void sort_entries(t_directories *list, int *max);
void delete_entries(t_directories *list, int *max, u32 flag);
void fill_entries_from_device(char *path, t_directories *list, int *max, u32 flag, int sel);

void copy_from_selection(int game_sel);
void copy_from_bluray();
void delete_game(int game_sel);
void test_game(int game_sel);

void copy_to_cache(int game_sel, char * hmanager_path);

void DeleteDirectory(const char* path);

void FixDirectory(const char* path);

extern tfavourites favourites;
extern int havefavourites;

void LoadFavourites(char * path);
void SaveFavourites(char * path);
void UpdateFavourites(t_directories *list, int nlist);
int TestFavouritesExits(char *id);
void AddFavourites(int indx, t_directories *list, int position_list);
int DeleteFavouritesIfExits(char *id);

int param_sfo_util(char * path, int patch_app);

void reset_sys8_path_table();
void add_sys8_path_table(char * compare, char * replace);
void build_sys8_path_table();

int blacklist(char *id);

#endif

