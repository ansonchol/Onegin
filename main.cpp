#include <stdio.h>
#include <stdlib.h>

#include "func_file.h"
#include "sort.h"
#include "my_string.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <mode> <src_file> <dst_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* file_name_src = argv[2];
    const char* file_name_dst = argv[3];

    size_t size = get_file_size(file_name_src);
    int max_lines = (int)(size / 2) + 1;

    char** arr_string = (char**)calloc((size_t)max_lines, sizeof(char*));
    if (arr_string == NULL)
    {
        printf("Error: calloc failed\n");
        return 0;
    }

    int line = read_file_into_buffer(file_name_src, arr_string, size, max_lines);
    if (line < 0)
    {
        printf("Can't read file\n");
        free(arr_string);
        return 0;
    }

    sort_bubble(arr_string, line, sizeof(char*), CharPtr_Compare_Down_reverse);
    write_lines_to_file(file_name_dst, arr_string, line, "w");

    qsort(arr_string, (size_t)line, sizeof(char*), CharPtr_Compare_Up_reverse);
    write_lines_to_file(file_name_dst, arr_string, line, "a");

    sort_bubble(arr_string, line, sizeof(char*), Int_Compare_Up);
    write_lines_to_file(file_name_dst, arr_string, line, "a");

    free(arr_string);
    return 0;
}


