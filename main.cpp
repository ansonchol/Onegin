#include <stdio.h>
#include <stdlib.h>

#include "func_file.h"
#include "sort.h"
#include "my_string.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("you wrote smth else, not 4\n");
        return 0;
    }
    const char* file_name_src          =  argv[2];
    const char* file_name_dst          =  argv[3];

    size_t size = file_size(file_name_src);
    char** arr_string = (char**)calloc(1, size);
    if (arr_string == NULL)
    {
        printf("SMTH gone wrong(calloc)\n");
        return 0;
    }

    int line = ParseBuffFromFile(file_name_src, arr_string, size);

    sort_bubble(arr_string, line,sizeof(char*),  CharPtr_Compare_Down_straight);
    write_edit_file(file_name_dst, arr_string, line);

    qsort(arr_string, line, sizeof(char*),  CharPtr_Compare_Up_reverse);
    write_edit_file(file_name_dst, arr_string, line);

    sort_bubble(arr_string, line, sizeof(char*), Int_Compare_Up);
    write_edit_file(file_name_dst, arr_string, line);

    free(arr_string);
    arr_string = NULL;

    return 0;
}



