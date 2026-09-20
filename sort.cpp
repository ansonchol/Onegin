#include <stdio.h>
#include <assert.h>

void print_massive(void* s, size_t size, int len_massive, void (*Func)(const void* value));
void sort_bubble(void* data, size_t size, int len_s, int (*CompareFunc)(const void* a, const void* b));
void switch_value(void* value1, void* value2, size_t size);

//comparator for sort
int Int_Compare_Up(const void* a, const void* b);
int Int_Compare_Down(const void* a, const void* b);
int Char_Compare_Up(const void* a, const void* b);
int Char_Compare_Down(const void* a, const void* b);

//comparator for print_massive
void Print_Int(const void* value);
void Print_Char(const void* value);

int main()
{
    int int_massive[10] = {3, 5, 1, 8, 2, 6, 9, 7, 4, 0};
    char char_massive[8] = {'a', 'g', 't', 'e', 'b', '5', '3'};

    sort_bubble(int_massive,sizeof(int), 10, Int_Compare_Up);
    print_massive(int_massive, sizeof(int), 10, Print_Int);

    sort_bubble(char_massive,sizeof(char), 8, Char_Compare_Down);
    print_massive(char_massive, sizeof(char), 8, Print_Char);

    return 0;
}

void Print_Int(const void* value)
{
    assert(value != NULL);
    printf("%d ", *(const int*)value);
}

void Print_Char(const void* value)
{
    assert(value != NULL);
    printf("%c ", *(const char*)value);
}

void print_massive(void* s, size_t size, int len_massive, void (*Func)(const void* value))
{
    assert(s != NULL);

    unsigned char* s_new = (unsigned char*)s;
    printf("\nPrint 1_d massive:\n<");

    for (int x = 0; x < len_massive; x++)
    {
        Func(s_new + size*x);
    }
    printf(">\n");
}

void sort_bubble(void* data, size_t size, int len_s, int (*CompareFunc)(const void* a, const void* b))
{
    assert(data != NULL);
    assert(CompareFunc != NULL);

    unsigned char* data_new = (unsigned char*)data;

    for (int n = 0; n < len_s - 1; n++)
        for (int i = 0; i < len_s - 1 - n; i++)
            {
                void* a = data_new + (size_t)i * size;
                void* b = data_new + (size_t)(i + 1) * size;
                if (CompareFunc(a, b) > 0)
                    switch_value(a, b, size);
             }
}

void switch_value(void* value1, void* value2, size_t size)
{
    assert(value1 != NULL);
    assert(value2 != NULL);

    unsigned char* a = (unsigned char*)value1;
    unsigned char* b = (unsigned char*)value2;

    for (size_t k = 0; k < size; k++)
    {
        unsigned char tmp = a[k];
        a[k] = b[k];
        b[k] = tmp;
    }
}

int Int_Compare_Up(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);

    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return  1;
    return 0;
}

int Int_Compare_Down(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);

    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x > y) return -1;
    if (x < y) return  1;
    return 0;
}

int Char_Compare_Up(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);

    char x = *(const char*)a;
    char y = *(const char*)b;

    if (x < y) return -1;
    if (x > y) return  1;
    return 0;
}

int Char_Compare_Down(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);

    char x = *(const char*)a;
    char y = *(const char*)b;

    if (x > y) return -1;
    if (x < y) return  1;
    return 0;
}
