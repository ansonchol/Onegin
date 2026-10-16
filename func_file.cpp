#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdbool.h>

#include "my_string.h"
#include "sort.h"
#include "func_file.h"

size_t get_file_size(const char* file_name)
{
    assert(file_name);

    struct stat st;
    if (stat(file_name, &st) != 0)
    {
        printf("Error: cannot stat file %s\n", file_name);
        return 0;
    }
    return (size_t)st.st_size;
}

int split_buffer_into_arr_str(char* buffer, char** array_string, int max_lines)
{
    assert(buffer);
    assert(array_string);
    assert(max_lines > 0);

    int line = 1;
    char* massive_new = buffer;
    array_string[0] = buffer;

    while (*(massive_new + 1) != '\0')
    {
        if (*massive_new == '\n')
        {
            *massive_new = '\0';
            if (*(massive_new + 1) != '\0')
            {
                if (line >= max_lines)
                {
                    printf("Warning: too many lines, stopped at %d\n", max_lines);
                    break;
                }
                array_string[line] = massive_new + 1;
                line++;
            }
        }
        massive_new++;
    }
    return line;
}

int read_file_into_buffer(const char* src_file, char** array_string, size_t size, int max_lines)
{
    assert(src_file);
    assert(array_string);

    FILE* file = fopen(src_file, "rb");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        return -1;
    }
    printf("SUCCESS -> FILE %s was opened\n", src_file);

    char* buffer = (char*)calloc(size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("Error: calloc failed\n");
        fclose(file);
        return -1;
    }

    size_t read_count = fread(buffer, 1, size, file);
    buffer[read_count] = '\0';
    fclose(file);

    if (read_count == 0)
    {
        printf("Error: file is empty or read failed\n");
        free(buffer);
        return -1;
    }

    int line = split_buffer_into_arr_str(buffer, array_string, max_lines);
    printf("SUCCESS -> FILE %s parsed into %d lines\n", src_file, line);
    return line;
}

void write_lines_to_file(const char* dst_file, char** array_string, int len_arr,  const char* mode)
{
    assert(dst_file);
    assert(array_string);

    FILE* file = fopen(dst_file, mode);
    if (file == NULL)
    {
        printf("Error: cannot open file for writing: %s\n", dst_file);
        return;
    }

    for (int x = 0; x < len_arr; x++)
    {
        if (array_string[x] == NULL || array_string[x][0] == '\0')
        {
            continue;
        }
        fputs(array_string[x], file);
        fputc('\n', file);
    }

    fclose(file);
    printf("SUCCESS -> The buffer is in %s\n", dst_file);
}
