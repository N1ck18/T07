#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int input_array(int a[], int *n);
void output(int a[], int n);
void sort(int *a, int n);

int main() {
    int n = 0;
    int *data = NULL;
    char ch;
    if (scanf("%d", &n) && ((ch = getchar()) == ' ' || ch == '\n') && (n > 0 && n <= NMAX)) {
        data = (int *)malloc(n * sizeof(int));
        if (input(data, &n)) {
            sort(data, n);
            output(data, n);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}

void sort(int *a, int n) {
    for (int j = 0; j < n; j++) {
        int move = 0;
        for (int i = 1; i < n; i++) {
            if (*(a + i - 1) > *(a + i)) {
                int temp = *(a + i);
                *(a + i) = *(a + i - 1);
                *(a + i - 1) = temp;
                move = 1;
            }
        }
        if (move == 0) {
            break;
        }
    }
    return;
}

int input_array(int a[], int *n) {
    int result = 1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            result = 0;
            break;
        }
    }
    if (result != 0 && getchar() != '\n') {
        result = 0;
    }

    return result;
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}