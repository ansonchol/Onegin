#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdbool.h>

#include "my_string.h"
#include "sort.h"
#include "func_file.h"

struct stat st;

size_t file_size(const char* file_name)
{
    assert(file_name);

    stat(file_name, &st);
    return st.st_size;
}

int ParseBufToArr(char* buffer, char** array_string)
{
    assert(buffer);
    assert(array_string);

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
                array_string[line] = massive_new + 1;
                (line)++;
            }
        }
        massive_new++;
    }
    return line;
}

int ParseBuffFromFile(const char* file_name, char** array_string, size_t size)
{
    assert(file_name);
    assert(array_string);

    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE);
    }
    printf("SUCCESS -> FILE %s was read\n", file_name);


    char* buffer = (char*)calloc(size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("SMTH gone wrong\n");
        exit(EXIT_FAILURE);
    }
    fread(buffer, size, 1, file);
    buffer[size] = '\0';

    int line = ParseBufToArr(buffer, array_string);

    fclose(file);
    printf("SUCCESS -> FILE %s moved into massive_file\n", file_name);

    return line;
}

void write_edit_file(const char* file_edit, char** array_string, int len_arr)
{
    assert(file_edit);
    assert(array_string);

    FILE* file = fopen(file_edit, "w");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE);
    }

    for (int x = 0; x < len_arr; x++)
    {
        if (**(array_string + x) == '\0'){continue;}
        fputs(*(array_string + x), file);
    }

    fclose(file);
    printf("SUCCESS -> The buffer is in %s\n", file_edit);
}


