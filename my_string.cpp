#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "my_string.h"

void print_massive_string(char** s, int size_x)
{
    for (int x = 0; x < size_x; x++)
    {
        if (s + x == NULL)
        {
            printf("EXIT in massive\n");
            return;
        }
        char* value = *(s+x);
        while(value != NULL && *value != '\0')
        {
            printf("%c", *value);
            value++;
        }
        printf("\n");
    }
    printf("\n");
}

int my_strlen(const char* s)
{
    assert(s != NULL);

    int count_sym = 0;
    while (*s != '\0')
    {
        s++;
        count_sym++;
    }

    return count_sym; //не считая '\0'
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
    *s1 = '\0';

    return start;
}


bool is_letter(char sym)
{
    return (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z');
}

int to_upper_letter(char s1)
{
    if (s1 >= 'a' && s1 <= 'z')
    {
        s1 = s1 - ('a' - 'A');
        return (int)s1;
    }
    else
    {
        return (int)s1;
    }
}

int my_strcmp(const char* s1, const char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*s1 != '\0' || *s2 != '\0')
    {
        if      (!is_letter(*s1) && *(s1 + 1) != '\0')     {s1++;}
        else if (!is_letter(*s2) && *(s2 + 1) != '\0')     {s2++;}
        else
        {
            int s1_new = to_upper_letter(*s1);
            int s2_new = to_upper_letter(*s2);

            if     ((s1_new - s2_new) <  0)      {return -1;}
            else if((s1_new - s2_new) >  0)      {return  1;}
            s1++;
            s2++;
        }
    }

    return  0;
}

int my_strcmp_reverse(const char* value1, const char* value2)
{
    assert(value1 != NULL);
    assert(value2 != NULL);

    char* s1 = (char*)value1;
    char* s2 = (char*)value2;

    char* end_s1 = s1 + my_strlen(s1);
    char* end_s2 = s2 + my_strlen(s2);

    while (end_s1 > s1  || end_s2 > s2)
    {
        if      (!is_letter(*end_s1) && (end_s1 - 1) != s1)     {--end_s1;}
        else if (!is_letter(*end_s2) && (end_s2 - 1) != s2)     {--end_s2;}
        else
        {
            int s1_new = to_upper_letter(*end_s1);
            int s2_new = to_upper_letter(*end_s2);

            if     ((s1_new - s2_new) <  0)      {return -1;}
            else if((s1_new - s2_new) >  0)      {return  1;}
            end_s1--;
            end_s2--;
        }
    }
    return  0;
}

