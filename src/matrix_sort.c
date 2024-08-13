#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int input_int(int *n);
// int input_menu(int *menu);
int input_matrix_size(int *m, int *n);
int input_dinamic_matrix(int x, int y, int **matrix);
void output_dinamic_matrix(int x, int y, int **matrix);
int **create_single_array_matrix(int x, int y);
int **create_slow_matrix(int x, int y);
int **create_two_array_matrix(int n, int m);
void free_matrix(int **matrix, int m, int type);
void swap_rows(int *m_lhs, int *m_rhs, int n, int *lhs, int *rhs);
//void swap_rows(int *lhs, int *rhs, int n);
void sort_matrix(int **matrix, int n, int m);

int main()
{
    int error = 0;
    int command = 0;
    int m = 0;
    int n = 0;
    if (input_int(&command) && input_matrix_size(&m, &n) && m > 0 && n > 0 && command > 0 && command < 4)
    {
        if (command == 1)
        {
            int **data = create_slow_matrix(n, m);
            if (input_dinamic_matrix(n, m, data))
            {
                sort_matrix(data, n, m);
                output_dinamic_matrix(n, m, data);
            }
            else
                error = 1;
            free_matrix(data, m, 0);
        }
        else if (command == 2)
        {
            int **data = create_single_array_matrix(n, m);
            if (input_dinamic_matrix(n, m, data))
            {
                sort_matrix(data, n, m);
                output_dinamic_matrix(n, m, data);
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
                sort_matrix(data, n, m);
                output_dinamic_matrix(n, m, data);
            }
            else
                error = 1;
            free_matrix(data, m, 2);
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

/* void sort_matrix(int **matrix, int n, int m)
{
    __clock_t start, end;
    start = clock();
    double cpu_time_used;

    for (int k = 0; k < m; k++)
    {
        for (int i = 1; i < m; i++)
        {
            int summ_1 = matrix[i][0];
            for (int j = 1; j < n; j++)
            {
                summ_1 += matrix[i][j];
            }
            int summ_2 = matrix[i - 1][0];
            for (int j = 1; j < n; j++)
            {
                summ_2 += matrix[i - 1][j];
            }
            summ_2 > summ_1 ? swap_rows(matrix[i], matrix[i - 1], n) : 0;
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("\nCPU - %lf\n", cpu_time_used);
} */

void sort_matrix(int **matrix, int n, int m)
{
    __clock_t start, end;
    start = clock();
    double cpu_time_used;

    int *arr = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        int summ = matrix[0][0];
        for (int j = 1; j < n; j++)
        {
            summ += matrix[i][j];
        }
        arr[i] = summ;
    }

    for (int k = 0; k < m; k++)
    {
        for (int i = 1; i < m; i++)
        {
            arr[i - 1] > arr[i] ? swap_rows(matrix[i], matrix[i - 1], n, &arr[i - 1], &arr[i]) : 0;
        }
    }
    free(arr);

    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("\nCPU - %lf\n", cpu_time_used);
}

void swap_rows(int *m_lhs, int *m_rhs, int n, int *lhs, int *rhs)
{
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val = m_lhs[i];
        m_lhs[i] = m_rhs[i];
        m_rhs[i] = val;
    }
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

/* void swap_rows(int *lhs, int *rhs, int n)
{
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val = lhs[i];
        lhs[i] = rhs[i];
        rhs[i] = val;
    }
} */

int input_menu(int *menu)
{
    int result = 1;
    char ch;
    if (scanf("%d", menu) != 1 || *menu < 1 || *menu > 3 || (ch = getchar()) != '\n')
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

void free_matrix(int **matrix, int m, int type)
{
    switch (type)
    {
    case 0: // slow
        for (int i = 0; i < m; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
        break;
    case 1: // one array
        free(matrix);
        break;
    case 2: // two array
        free(*matrix);
        free(matrix);
        break;
    default:
        printf("Wrong type of matrix");
        break;
    }
}