#ifndef MASSIVE_H
#define MASSIVE_H

void print_matrix_1d(int s[], int size_x)
{
    for (int x = 0; x < size_x; x++)
    {
        printf("%d ", *(s + x));
    }
}

#endif
