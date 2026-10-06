#include <stdio.h>
#include <stdlib.h>

#include "work_file.h"
#include "sort.h"
#include "my_string.h"

struct info_file
{
    const char* file_name;
    size_t size;
    int line;
};

int main()
{
    const char* file_name          =  "onegin.txt";
    const char* file_edit_straight =  "edit_onegin_straight.txt";
    const char* file_edit_reverse  =  "edit_onegin_reverse.txt";
    const char* file_new           =  "do_not_disturb_Pushkin.txt";

    size_t size = file_size(file_name);
    char** arr_string = (char**)calloc(size + 1, sizeof(char*));
    if (arr_string == NULL)
    {
        printf("SMTH gone wrong(calloc)\n");
        return 0;
    }
    int line = open_file_to_buffer(file_name, arr_string, size);

    sort_bubble(arr_string, sizeof(char*), line, CharPtr_Compare_Down_straight);
    write_edit_file(file_edit_straight, arr_string, line);

    sort_bubble(arr_string, sizeof(char*), line, CharPtr_Compare_Up_reverse);
    write_edit_file(file_edit_reverse, arr_string, line);

    sort_bubble(arr_string, sizeof(char*), line, Int_Compare_Up);
    write_edit_file(file_new, arr_string, line);

    free(arr_string);
    arr_string = NULL;

    return 0;
}



