#define NSTART
#define NTEST_ONEGIN
#define TEST_READ

#ifdef START

#include <stdio.h>
#include <stdlib.h>

#include "1d_massive.h"

int main()
{
    int len_massive = 0;
    scanf("%d", &len_massive);
    int* ptd = (int*)calloc(len_massive * sizeof(int));
    if (ptd == NULL)
    {
        printf("Cannot impossible to give memory\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        for (int* p = ptd; p < ptd + len_massive; p++)
        {
            printf("%p  %d  ", p, *p);
            scanf("%d", p);
        }
    }

    print_matrix_1d(ptd, len_massive);

    free(ptd);
    *ptd = 8;

    printf("%p  %d", ptd, *ptd);
    return 0;
}

#endif

#ifdef TEST_ONEGIN
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "my_string.h"

void print_massive_string(char** s, int size_x);
/*
Что делаем и как?
создаем массив из указателей на указателей
сделали отдельные компараторы для указателей на указателей(подробнее про них в sort.cpp)
каждый элемент имеет тип char*
обращение к литералам выглядит так: **(index + i)
    1) в 1 раз разыменовываем -> получаем значение адреса литерала
    2) во 2 раз разыменовываем -> получаем сам литерал

*/
int main()
{
    char a[] = " BAC", v[] = " abc", c[] = "Ras", r[] = "  RAs-40545T", t[] = "RAB";

    char** index = (char**)calloc(5, sizeof(char*));

    index[0] = a;
    index[1] = v;
    index[2] = c;
    index[3] = r;
    index[4] = t;

    sort_bubble(index, sizeof(char*), 5, CharPtr_Compare_Up);
    print_massive_string(index, 5);

    free(index);
    index = NULL;

    return 0;
}


#endif

#ifdef TEST_READ

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "my_string.h"
#include "sort.h"

struct stat st;

int main()
{
    const char* file_name = "onegin.txt";
    const char* file_name_edit = "edit_onegin.txt";
    FILE* file = fopen(file_name, "r"); //исходник
    FILE* file_edit = fopen(file_name_edit, "w"); //куда записываю
    if (file == NULL)
    {
        printf("Error: file doesn't exist\n");
        exit(EXIT_FAILURE);
    }

    stat(file_name, &st);

    char** buffer = (char**)calloc(st.st_size + 1, sizeof(char*));
    char* fp = (char*)calloc(st.st_size + 1, sizeof(char));

    fread(fp, st.st_size, 1, file);
    fp[st.st_size] = '\0';

    int count = 1;
    char* fp_new = fp;
    //первая строка не читается \n
    buffer[0] = fp;
    while (*fp_new != '\0' && *(fp_new + 1) != '\0')
    {
        if (*fp_new == '\n')
        {
            *fp_new = '\0';
            if (*(fp_new + 1) != '\0')
            {
                buffer[count] = fp_new + 1;
                count++;
            }
        }
        fp_new++;
    }

    sort_bubble(buffer, sizeof(char*), count, CharPtr_Compare_Down_straight);

    print_massive_string(buffer, count);

    for (int x = 0; x < count; x++)
    {
        fputs(*(buffer + x), file_edit);
    }

    free(buffer);
    buffer = NULL;

    fclose(file);
    fclose(file_edit);
    return 0;
}

#endif
