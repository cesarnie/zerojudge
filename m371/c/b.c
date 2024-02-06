#include <stdio.h>
#include <stdlib.h>
int check_row(int, int, int*);
int check_col(int, int, int*);
int sum;

void main() {
    int row, clo;
    sum = 0;
    scanf("%d %d", &row, &clo);
    int* d = malloc(row * clo * sizeof(int));
    for (int clo2 = 0; clo2 < clo; clo2++) {
        for (int row2 = 0; row2 < row; row2++) {
            scanf("%d", &d[clo2 * row2 + clo2]);
        }
    }
    sum = 0;
    while (check_row(row, clo, d) || check_col(row, clo, d)) {
    }
    printf("%d\n", sum);
}

int print_grid(int row, int col, int* d) {
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            printf("%d ", d[r * col + c]);
        }
        printf("\n");
    }
    printf("sum=%d\n", sum);
}

int check_row(int row, int clo, int* d) {
    int row2, clo2, find;
    find = 0;
    for (row2 = 0; row2 < row; row2++) {
        for (clo2 = 0; clo2 < clo; clo2++) {
            int* a = &d[clo * row2 + clo2];
            while (d[clo * row2 + clo2] == -1 && clo2 < clo) {
                clo2++;
            }
            if (d[clo * row2 + clo2] == *a && d[clo * row2 + clo2] != -1) {
                find++;
                sum = sum + *a;
                d[clo * row2 + clo2] = *a = -1;
                print_grid(row, clo, d);
                break;
            }
        }
    }
    return find;
}

int check_col(int row, int clo, int* d) {
    int row2, clo2, find;
    find = 0;
    for (clo2 = 0; clo2 < clo; clo2++) {
        for (row2 = 0; row2 < row; row2++) {
            int* a = &d[clo * row2 + clo2];
            while (d[clo * row2 + clo2] == -1 && row2 < row) {
                row2++;
            }
            if (d[clo * row2 + clo2] == *a && d[clo * row2 + clo2] != -1) {
                find++;
                sum = sum + *a;
                d[clo * row2 + clo2] = *a = -1;
                print_grid(row, clo, d);
                break;
            }
        }
    }
    return find;
}