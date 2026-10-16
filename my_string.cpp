#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "my_string.h"

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

int my_strcmp_forward(const char* s1, const char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    while (*s1 != '\0' && *s2 != '\0')
    {
        if (!is_letter(*s1) && *(s1 + 1) != '\0')
        {
            s1++;
            continue;
        }
        if (!is_letter(*s2) && *(s2 + 1) != '\0')
        {
            s2++;
            continue;
        }

        int c1 = to_upper_letter(*s1);
        int c2 = to_upper_letter(*s2);

        if (c1 != c2)
        {
            return (c1 < c2) ? -1 : 1;
        }
        s1++;
        s2++;
    }

    if (*s1 == '\0' && *s2 == '\0')
    {
        return 0;
    }
    return (*s1 == '\0') ? -1 : 1;
}

int my_strcmp_backward(const char* value1, const char* value2)
{
    assert(value1 != NULL);
    assert(value2 != NULL);

    const char* s1 = value1;
    const char* s2 = value2;

    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    int i = len1 - 1;
    int j = len2 - 1;

    while (i >= 0 && j >= 0)
    {
        if (!is_letter(s1[i]) && i > 0)
        {
            i--;
            continue;
        }
        if (!is_letter(s2[j]) && j > 0)
        {
            j--;
            continue;
        }

        int c1 = to_upper_letter(s1[i]);
        int c2 = to_upper_letter(s2[j]);

        if (c1 != c2)
        {
            return (c1 < c2) ? -1 : 1;
        }
        i--;
        j--;
    }

    if (i < 0 && j < 0)
    {
        return 0;
    }
    return (i < 0) ? -1 : 1;
}

