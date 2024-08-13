#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int input_menu(int *menu);
int input_matrix_size(int *m, int *n);
// int input_static_matrix(int x, int y, int matrix[x][y]);
int input_static_matrix(int x, int y, int **matrix);
int input_dinamic_matrix(int x, int y, int **matrix);
// void output_static_matrix(int x, int y, int matrix[x][y]);
void output_static_matrix(int x, int y, int **matrix);
void output_dinamic_matrix(int x, int y, int **matrix);

int **create_single_array_matrix(int x, int y);
int **create_two_array_matrix(int x, int y);
int **create_slow_matrix(int x, int y);
int input_dinamic_matrix_(int x, int y, int **matrix);

int main()
{
    int result = 1;
    int menu = 0;
    int x = 0, y = 0;

    if (!input_menu(&menu) || !input_matrix_size(&x, &y))
    {
        result = 0;
    }
    if (result != 0 && x <= NMAX && x > 0 && y > 0 && y <= NMAX)
    {
        if (menu == 1)
        {
            int data[NMAX][NMAX];
            int **ptr_data = (int **)data;
            if (input_static_matrix(x, y, ptr_data))
            {
                output_static_matrix(x, y, ptr_data);
            }
            else
                result = 0;
        }
        else if (menu == 2)
        {
            int **data = create_single_array_matrix(x, y);

            if (input_dinamic_matrix(x, y, data))
            {
                output_dinamic_matrix(x, y, data);
            }
            else
                result = 0;
            free(data);
        }
        else if (menu == 3)
        {
            int **data = create_two_array_matrix(x, y);
            if (input_dinamic_matrix(x, y, data))
            {
                output_dinamic_matrix(x, y, data);
            }
            else
                result = 0;
            free(*data);
            free(data);
        }
        else
        {
            int **data = create_slow_matrix(x, y);
            if (input_dinamic_matrix(x, y, data))
            {
                output_dinamic_matrix(x, y, data);
            }
            else
                result = 0;
            for (int i = 0; i < y; i++)
            {
                free(data[i]);
            }
            free(data);
        }
    }
    if (result == 0)
        printf("n/a");

    return 0;
}

int **create_two_array_matrix(int n, int m)
{
    int *data = malloc(sizeof(int) * n * m);
    int **ptr = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        *(ptr + i) = data + n * i;
    }
    return ptr;
}

int **create_slow_matrix(int x, int y)
{
    int **ptr = malloc(sizeof(int *) * y);
    for (int i = 0; i < y; i++)
    {
        *(ptr + i) = malloc(sizeof(int) * x);
    }
    return ptr;
}

int **create_single_array_matrix(int x, int y)
{
    int **data = (int **)malloc(sizeof(int) * x * y + y * sizeof(int *));
    int *ptr = (int *)(data + y);
    for (int i = 0; i < y; i++)
    {
        data[i] = ptr + i * x;
    }
    return data;
}

/* void output_static_matrix(int x, int y, int matrix[x][y]) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d", matrix[i][j]);
            if (j != x - 1) {
                printf(" ");
            }
        }
        if (i != y - 1) {
            printf("\n");
        }
    }
} */

void output_static_matrix(int x, int y, int **matrix)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            int *ptr = (int *)(matrix + i * x + j);
            printf("%d", *ptr);
            if (j != x - 1)
            {
                printf(" ");
            }
        }
        if (i != y - 1)
        {
            printf("\n");
        }
    }
}

int input_menu(int *menu)
{
    int result = 1;
    char ch;
    if (scanf("%d", menu) != 1 || *menu < 1 || *menu > 4 || (ch = getchar()) != '\n')
    {
        result = 0;
    }
    return result;
}

int input_matrix_size(int *m, int *n)
{
    int result = 0;
    char ch;
    if (scanf("%d %d", m, n) == 2 && ((ch = getchar()) == ' ' || ch == '\n'))
    {
        result = 1;
    }
    return result;
}

/* int input_static_matrix(int x, int y, int matrix[x][y]) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                result = 0;
            }
        }
    }
    if (getchar() != '\n') {
        result = 0;
    }
    return result;
}
 */
int input_dinamic_matrix(int x, int y, int **matrix)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (scanf("%d", (*(matrix + i) + j)) != 1)
            {
                result = 0;
            }
        }
    }
    if (getchar() != '\n')
    {
        result = 0;
    }
    return result;
}

int input_static_matrix(int x, int y, int **matrix)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            int *ptr = (int *)(matrix + i * x + j);
            if (scanf("%d", ptr) != 1)
            {
                result = 0;
            }
        }
    }
    if (getchar() != '\n')
    {
        result = 0;
    }
    return result;
}

void output_dinamic_matrix(int x, int y, int **matrix)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d", matrix[i][j]);
            if (j != x - 1)
            {
                printf(" ");
            }
        }
        if (i != y - 1)
        {
            printf("\n");
        }
    }
}