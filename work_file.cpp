#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdbool.h>

#include "my_string.h"
#include "sort.h"
#include "work_file.h"

struct stat st;

size_t file_size(const char* file_name)
{
    stat(file_name, &st);
    return st.st_size;
}

int move_massive_to_buffer(char* massive_string, char** buffer)
{
    assert(massive_string);
    assert(buffer);

    int line = 1;

    char* massive_new = massive_string;
    buffer[0] = massive_string;
    while (*massive_new != '\0' && *(massive_new + 1) != '\0')
    {
        if (*massive_new == '\n')
        {
            *massive_new = '\0';
            if (*(massive_new + 1) != '\0')
            {
                buffer[line] = massive_new + 1;
                (line)++;
            }
        }
        massive_new++;
    }
    return line;
}
//TODO ENUM ОШИБКИ
int open_file_to_buffer(const char* file_name, char** buffer, size_t size, char* out_fp)
{
    assert(file_name);
    assert(buffer);

    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE); //RETURN ОШИБКА
    }
    printf("SUCCESS -> FILE %s was read\n", file_name);

    //создание массива для файла
    char* massive_string = (char*)calloc(size + 1, sizeof(char));
    fread(massive_string, size, 1, file);//проверка
    massive_string[size] = '\0';

    int line = move_massive_to_buffer(massive_string, buffer);
    out_fp = massive_string;

    fclose(file);
    printf("SUCCESS -> FILE %s moved into massive_file\n", file_name);

    return line;
}

void write_edit_file(const char* file_edit, char** buffer, int len_buf)
{
    assert(file_edit);
    assert(buffer);

    FILE* file = fopen(file_edit, "w");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE);
    }
//TODO массив из структур(длина и указатель на строку)
    for (int x = 0; x < len_buf; x++)
    {
        // if (**(buffer) == '\n') {continue;}
        fputs(*(buffer + x), file);
    }

    fclose(file);
    printf("SUCCESS -> The buffer is in %s\n", file_edit);
}


