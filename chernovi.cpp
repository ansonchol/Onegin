#define NSTART
#define TEST_ONEGIN
#define NTEST_READ

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
#include "my_String.h"

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
    char a[] = "ABC", v[] = "abc", c[] = "ARB", r[] = "RAT", t[] = "RAB";

    char** index = (char**)calloc(5, sizeof(char*));

    index[0] = a;
    index[1] = v;
    index[2] = c;
    index[3] = r;
    index[4] = t;

    sort_bubble (index, sizeof(char*), 5, CharPtr_Compare_Up);
    print_massive_string(index, 5);

    free(index);
    index = NULL;

    return 0;
}


#endif

#ifdef TEST_READ
#include <stdio.h>

int main()
{

return 0;
}
#endif


