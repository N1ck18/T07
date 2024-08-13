#include <stdlib.h>
#include <stdio.h>

#define NMAX 100

int **create_two_array_matrix(int x, int y);
int **create_slow_matrix(int x, int y);
void output_static_matrix(int x, int y, int matrix[y][x]);
int input_int(int *n);
void output_dinamic_matrix(int x, int y, int **matrix);
int **create_single_array_matrix(int x, int y);
int input_dinamic_matrix(int x, int y, int **matrix);
void print_minmax(int *max, int *min, int n, int m);
void min_max(int **matrix, int n, int m);
int input_matrix_size(int *m, int *n);
int input_static_matrix(int x, int y, int matrix[y][x]);
void min_max_static(int n, int m, int matrix[m][n]);

int main()
{
    int error = 0;
    int command = 0;
    int m = 0;
    int n = 0;
    if (input_int(&command) && input_matrix_size(&m, &n) && m <= NMAX && n <= NMAX && m > 0 && n > 0)
    {
        if (command == 1)
        {
            int data[NMAX][NMAX];
            if (input_static_matrix(n, m, data))
            {
                output_static_matrix(n, m, data);
                min_max_static(n, m, data);
            }
            else
                error = 1;
        }
        else if (command == 2)
        {
            int **data = create_single_array_matrix(n, m);
            if (input_dinamic_matrix(n, m, data))
            {
                output_dinamic_matrix(n, m, data);
                min_max(data, n, m);
            }
            else
                error = 1;
            free(data);
        }
        else if (command == 3)
        {
            int **data = create_two_array_matrix(n, m);
            if (input_dinamic_matrix(n, m, data))
            {
                output_dinamic_matrix(n, m, data);
                min_max(data, n, m);
            }
            else
                error = 1;
            free(*data);
            free(data);
        }
        else if (command == 4)
        {
            int **data = create_slow_matrix(n, m);
            if (input_dinamic_matrix(n, m, data))
            {
                output_dinamic_matrix(n, m, data);
                min_max(data, n, m);
            }
            else
                error = 1;
            for (int i = 0; i < m; i++)
            {
                free(data[i]);
            }
            free(data);
        }
        else
            error = 1;
    }
    else
        error = 1;
    if (error == 1)
    {
        printf("n/a");
    }
    printf("\n");
}

void print_minmax(int *max, int *min, int n, int m)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d", max[i]);
        if (i != m - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", min[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
}

void min_max_static(int n, int m, int matrix[m][n])
{
    int max[NMAX];
    int min[NMAX];

    for (int i = 0; i < n; i++)
    {
        min[i] = matrix[0][i];
    }

    for (int i = 0; i < m; i++)
    {
        max[i] = matrix[i][0];
        for (int j = 0; j < n; j++)
        {
            max[i] = max[i] < matrix[i][j] ? matrix[i][j] : max[i];
            min[j] = min[j] > matrix[i][j] ? matrix[i][j] : min[j];
        }
    }
    print_minmax(max, min, n, m);
}

void min_max(int **matrix, int n, int m)
{
    int max[NMAX];
    int min[NMAX];

    for (int i = 0; i < n; i++)
    {
        min[i] = matrix[0][i];
    }

    for (int i = 0; i < m; i++)
    {
        max[i] = matrix[i][0];
        for (int j = 0; j < n; j++)
        {
            max[i] = max[i] < matrix[i][j] ? matrix[i][j] : max[i];
            min[j] = min[j] > matrix[i][j] ? matrix[i][j] : min[j];
        }
    }
    print_minmax(max, min, n, m);
}

int input_double(double *n)
{
    int result = 0;
    char ch;
    if ((scanf("%lf", n)) && ((ch = getchar()) == ' ' || ch == '\n'))
    {
        result = 1;
    }
    return result;
}

int input_int(int *n)
{
    int result = 0;
    char ch;
    if ((scanf("%d", n)) && ((ch = getchar()) == ' ' || ch == '\n'))
    {
        result = 1;
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

int input_static_matrix(int x, int y, int matrix[y][x])
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
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

int input_dinamic_matrix(int x, int y, int **matrix)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
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

void output_static_matrix(int x, int y, int matrix[y][x])
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