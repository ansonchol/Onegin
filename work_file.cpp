#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

#include "my_string.h"
#include "sort.h"
#include "work_file.h"

struct stat st;

size_t file_size(const char* file_name)
{
    stat(file_name, &st);
    return st.st_size;

}

int open_file_to_buffer(const char* file_name, char** buffer, size_t size, char* out_fp)
{
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE);
    }
    printf("SUCCESS -> FILE %s was read\n", file_name);

    char* fp = (char*)calloc(size + 1, sizeof(char));
    fread(fp, size, 1, file);
    fp[size] = '\0';

    int line = 1;
    //первая строка не читается \n
    char* fp_new = fp;
    buffer[0] = fp;
    while (*fp_new != '\0' && *(fp_new + 1) != '\0')
    {
        if (*fp_new == '\n')
        {
            *fp_new = '\0';
            if (*(fp_new + 1) != '\0')
            {
                buffer[line] = fp_new + 1;
                line++;
            }
        }
        fp_new++;
    }

    out_fp = fp;
    fclose(file);
    printf("SUCCESS -> FILE %s moved into massive_file\n", file_name);

    return line;
}

void write_edit_file(const char* file_edit, char** buffer, int len_buf)
{
    assert(file_edit);

    FILE* file = fopen(file_edit, "w");
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE);
    }

    for (int x = 0; x < len_buf; x++)
    {
        fputs(*(buffer + x), file);
    }

    fclose(file);
    printf("SUCCESS -> The buffer is in %s\n", file_edit);
}
