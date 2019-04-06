#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int dir_exists(char*);
void make_dir_if_missing(char*);
void list_note_files(char*);
int check_arg(char*, char* , char*);
void edit_file(char*, char*);
void del_file(char*, char*);
void print_no_ext(char*);

int main(int argc, char* argv[])
{
    char* home_dir = getenv("HOME");

    char notes_dir[128];
    sprintf(notes_dir, "%s/.cnotes", home_dir);

    make_dir_if_missing(notes_dir);
    
    if (argc == 1 || (check_arg(argv[1], "-l", "--list") && argc == 2)) {
        list_note_files(notes_dir);
    } else if (check_arg(argv[1], "-d", "--delete") && argc == 3) {
        del_file(notes_dir, argv[2]);
    } else if (argc == 2) {
        edit_file(notes_dir, argv[1]);
    }

    return 0;
}

int dir_exists(char* dir)
{
    struct stat st = {0};
    if (stat(dir, &st) == -1) {
        return 0;
    } else {
        return 1;
    }
}

void make_dir_if_missing(char* dir)
{
    if (!dir_exists(dir)) {
        printf("Directory %s does not exist, making it now...\n", dir);
        mkdir(dir, 0777);
    }
}

void list_note_files(char* dir)
{
    DIR *d;
    struct dirent *note_file;

    d = opendir(dir);

    if (d) {
        printf("\nAVAILABLE NOTES:");
        printf("\n----------------\n");
        while ((note_file = readdir(d)) != NULL) {
            char* name = note_file->d_name;

            if (strstr(name, ".md")) {
                print_no_ext(name);
            }
        }
        printf("\n");
    }
}

int check_arg(char* opt, char* short_opt, char* long_opt)
{
    return (strcmp(opt, short_opt) == 0) || (strcmp(opt, long_opt) == 0);
}

void edit_file(char* notes_dir, char* note_file)
{
    char* editor;
    if ( !(editor = getenv("EDITOR")) ) {
        editor = "vim";
    }
    
    char file_loc[256];
    char cmd[128];

    sprintf(file_loc, "%s/%s.md", notes_dir, note_file);
    sprintf(cmd, "%s %s", editor, file_loc);
    system(cmd);
}

void del_file(char* notes_dir, char* note_file)
{
    char to_del[256];
    sprintf(to_del, "%s/%s.md", notes_dir, note_file);
    if (remove(to_del) != 0) {
        printf("File not found! Unable to remove %s...\n", to_del);
    }
}

void print_no_ext(char* name)
{
    int i = 0;
    while (1) {
        char letter = name[i];
        if (letter != '.') {
            printf("%c", letter);
        } else {
            printf("\n");
            return;
        }
        i++;
    }
}
