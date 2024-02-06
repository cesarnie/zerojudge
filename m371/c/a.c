// https://zerojudge.tw/ShowProblem?problemid=m371

#include <stdio.h>
#include <stdlib.h>

int SUM = 0;
int COLS = 0;
int ROWS = 0;
int* DATA = NULL;

int print_grid() {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            printf("%2d ", DATA[r * COLS + c]);
        }
        printf("\n");
    }
    printf("sum=%d\n", SUM);
}

int find_vertical() {
    int find = 0;
    for (int col = 0; col < COLS; col++) {
        for (int row = 0; row < ROWS; row++) {
            int top = DATA[row * COLS + col];
            for (int row2 = row + 1; row2 < ROWS; row2++) {
                if (DATA[row2 * COLS + col] >= 0) {
                    if (DATA[row2 * COLS + col] == top) {
                        SUM += top;
                        DATA[row * COLS + col] = -1;
                        DATA[row2 * COLS + col] = -1;
                        find += 1;
                        print_grid();
                    }
                    break;
                }
            }
        }
    }
    return find;
}

int find_horizontal() {
    int find = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int left = DATA[row * COLS + col];
            // 取得第col個元素，並往下找相同的值（如果中間有阻礙，則停止）
            for (int col2 = col + 1; col2 < COLS; col2++) {
                if (DATA[row * COLS + col2] >= 0) {
                    if (DATA[row * COLS + col2] == left) {
                        SUM += left;
                        DATA[row * COLS + col2] = -1;
                        DATA[row * COLS + col] = -1;
                        find += 1;
                        print_grid();
                    }
                    break;
                }
            }
        }
    }
    return find;
}

int main(int argc, char** argv) {
    scanf("%d %d", &ROWS, &COLS);
    DATA = malloc(ROWS * COLS * sizeof(int));
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            scanf("%d", &DATA[row * COLS + col]);
        }
    }
    print_grid();
    while (find_horizontal() || find_vertical()) {
    }

    printf("%d\n", SUM);
    return 0;
}
