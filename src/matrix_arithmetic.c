

int input_int(int *n);
int input_matrix_size(int *x, int *y);
void free_matrix(int **matrix, int m, int type);

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
        int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second,
        int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);

int main()
{
    int command = 0;
    int error = 0;
    int m = 0;
    int n = 0;
    int m2 = 0;
    int n2 = 0;
    int **data;
    if (input_int(&command) && input_matrix_size(&n, &m) && m > 0 && n > 0 && command < 1 && command > 3)
    {
        data = create_two_array_matrix(n, m);
        if (!input_dinamic_matrix(n, m, data))
            error = 1;
    }
    else
        error = 1;
    if (error != 1 && input_matrix_size(&n2, &m2) && m2 > 0 && n2 > 0)
    {
        int **data2 = create_two_array_matrix(n2, m2);
        if (!input_dinamic_matrix(n2, m2, data2))
            error = 1;
        // summ
        if (command == 1 && error != 1)
        {
            int **result = create_two_array_matrix(n, m);
            if (sum(data, n, m, data2, n2, m2, result, n, m))
            {
                output_dinamic_matrix(n, m, result);
            }
            free_matrix(result, m, 2);
        }
        else if (command == 2 && error != 1)
        {
            int n_r = n < n2 ? n2 : n;
            int m_r = m < m2 ? m2 : m;
            int **result = create_two_array_matrix(n_r, m_r);
            if (mul(data, n, m, data2, n2, m2, result, n_r, m_r))
            {
                output_dinamic_matrix(n, m, result);
            }
            free_matrix(result, m, 2);
        }
        else if (command == 3 && error != 1)
        {
        }
        free_matrix(data2, m2, 2);
    }
    else
        error = 1;
    free_matrix(data, m, 2);
    if (error == 1)
    {
        printf("n/a");
    }
    printf("\n");
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second,
        int n_second, int m_second, int **matrix_result, int *n_result, int *m_result) {
            int result = 1;
    if (1)
    {
        for (int i = 0; i < m_result; i++)
        {
            for (int j = 0; j < n_result; j++)
            {
                *(*(matrix_result + i) + j) = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }
    else result = 0;
    return result;
        }

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
        int n_second, int m_second, int **matrix_result, int *n_result, int *m_result)
{
    int result = 1;
    if (n_first == n_second && m_first == m_second)
    {
        for (int i = 0; i < m_result; i++)
        {
            for (int j = 0; j < n_result; j++)
            {
                *(*(matrix_result + i) + j) = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }
    else result = 0;
    return result;
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

int input_matrix_size(int *n, int *m)
{
    int result = 0;
    char ch;
    if (scanf("%d %d", n, m) == 2 && ((ch = getchar()) == ' ' || ch == '\n'))
    {
        result = 1;
    }
    return result;
}