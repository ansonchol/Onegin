#include <stdio.h>
#include <stdlib.h>

#include "work_file.h"
#include "sort.h"
#include "my_string.h"

int main()
{
    const char* file_name          =  "onegin.txt";
    const char* file_edit_straight =  "edit_onegin_straight.txt";
    const char* file_edit_reverse  =  "edit_onegin_reverse.txt";
    const char* file_new           =  "do_not_disturb_Pushkin.txt";

    size_t size = file_size(file_name);
    char* massive_file = 0;
    char** buffer = (char**)calloc(size + 1, sizeof(char*));
//TODO
    int line = open_file_to_buffer(file_name, buffer, size, massive_file);

    sort_bubble(buffer, sizeof(char*), line, CharPtr_Compare_Down_straight);
    write_edit_file(file_edit_straight, buffer, line);

    sort_bubble(buffer, sizeof(char*), line, CharPtr_Compare_Up_reverse);
    write_edit_file(file_edit_reverse, buffer, line);

    sort_bubble(buffer, sizeof(char*), line, Int_Compare_Up);
    write_edit_file(file_new, buffer, line);

    free(massive_file);
    free(buffer);
    massive_file = NULL;
    buffer = NULL;

    return 0;
}



