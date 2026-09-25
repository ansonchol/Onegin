#include <stdio.h>

#include "1D_MASSIVE_H"

// int main()
// {
//     int m[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//     print_matrix_1d(m, 20);
//
//     return 0;
// }

void print_matrix_1d(int s[], int size_x)
{
    for (int x = 0; x < size_x; x++)
    {
        printf("%d ", *(s + x));
    }
    printf("\n");
}
