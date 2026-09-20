#include <stdio.h>
#include <assert.h>

#include "string.h"

int my_strlen(const char* s)
{
    assert(s != NULL);

    int count_sym = 0;
    while (*s != '\0')
    {
        s++;
        count_sym++;
    }

    return count_sym;
}

void my_puts(const char* s)
{
    assert(s != NULL);

    printf("<");
    while (*s != '\0')
    {
        printf("%c", *s);
        s++;
    }

    printf(">\n");
}

char* my_strcpy(char* s1, const char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    char* start = s1;
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';

    return start;
}

char* my_strcat(char* s1, const char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    char* start = s1;
    while (*s1 != '\0')
    {
        s1++;
    }

    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s2 = '\0';

    return start;
}

int my_strcmp(const char* s1, const char* s2)
{
    assert(s1 != NULL);

    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    if((*s1 - *s2) <  0)      {return -1;}
    else if((*s1 - *s2) >  0) {return  1;}
    else                      {return  0;}
}

