#include <stdio.h>
#include <stdlib.h>
int check_row(int, int, int*);
int check_col(int, int, int*);
int sum;
int print_grid(int row, int col, int*);

void main() {
    int row, clo;
    sum = 0;
    scanf("%d %d", &row, &clo);
    int* d = malloc(row * clo * sizeof(int));
    for (int row2 = 0; row2 < row; row2++) {
        for (int clo2 = 0; clo2 < clo; clo2++) {
            scanf("%d", &d[clo * row2 + clo2]);
        }
    }
    sum = 0;
    if (row == 1) {
        while (check_row(row, clo, d)) {
        }
    }
    else {
        int l = 0;
        while (check_row(row, clo, d) || check_col(row, clo, d)) {
            printf("loop %d\n", l);
            l++;
        }
    }
    printf("%d\n", sum);
    free(d);
}

int check_row(int row, int clo, int* d) {
    int row2, clo2, find;
    find = 0;
    for (row2 = 0; row2 < row; row2++) {
        for (clo2 = 0; clo2 < clo; clo2++) {
            // printf("row %d\n",clo*row2+clo2);
            if (d[clo * row2 + clo2] == -1) {
                while (d[clo * row2 + clo2] == -1 && clo2 < clo) {
                    clo2++;
                }
            }
            int* a = &d[clo * row2 + clo2];
            printf("#1 clo=%d, row2=%d, clo2=%d\n", clo, row2, clo2);
            clo2++;
            while (d[clo * row2 + clo2] == -1 && clo2 < clo) {
                clo2++;
            }
            printf("#2 clo=%d, row2=%d, clo2=%d\n", clo, row2, clo2);
            if (d[clo * row2 + clo2] == *a && d[clo * row2 + clo2] != -1) {
                find++;
                sum = sum + *a;
                d[clo * row2 + clo2] = *a = -1;
                print_grid(row, clo, d);
                break;
            }
        }
    }
    printf("check row returns %d\n", find);
    return find;
}

int check_col(int row, int clo, int* d) {
    int row2, clo2, find;
    find = 0;
    for (clo2 = 0; clo2 < clo; clo2++) {
        for (row2 = 0; row2 < row; row2++) {
            // printf("clo %d\n",clo*row2+clo2);
            if (d[clo * row2 + clo2] == -1 && row != 1) {
                while (d[clo * row2 + clo2] == -1 && row2 < row) {
                    row2++;
                }
            }
            int* a = &d[clo * row2 + clo2];
            row2++;
            while (d[clo * row2 + clo2] == -1 && row2 < row) {
                row2++;
            }
            // printf("clo %d, clo=%d, row2=%d, clo2=%d\n",clo*row2+clo2, clo, row2, clo2);
            if (d[clo * row2 + clo2] == *a && d[clo * row2 + clo2] != -1) {
                find++;
                sum = sum + *a;
                d[clo * row2 + clo2] = *a = -1;
                print_grid(row, clo, d);
                break;
            }
        }
    }
    printf("check col returns %d\n", find);
    return find;
}

int print_grid(int row, int col, int* d) {
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            printf("%2d ", d[r * col + c]);
        }
        printf("\n");
    }
    printf("sum=%d\n", sum);
}