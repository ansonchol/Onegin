#include <stdio.h>
#include <stdlib.h>

#include "work_file.h"
#include "sort.h"
#include "my_string.h"

int main()
{
    const char* file_name = "onegin.txt";
    const char* file_edit = "edit_onegin.txt";

    size_t size = file_size(file_name);
    char* massive_file = NULL;
    char** buffer = (char**)calloc(size + 1, sizeof(char*));

    int line = open_file_to_buffer(file_name, buffer, size, massive_file);

    sort_bubble(buffer, sizeof(char*), line, CharPtr_Compare_Up_straight);

    write_edit_file(file_edit, buffer, line);

    free (massive_file);
    free(buffer);
    massive_file = NULL;
    buffer = NULL;

    return 0;
}



