// https://zerojudge.tw/ShowProblem?problemid=m371

#include <stdio.h>
#include <stdlib.h>

int find_vertical(int cols, int rows, int* data, int* sum) {
    int find = 0;
    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            int top = data[row * cols + col];
            for (int row2 = row + 1; row2 < rows; row2++) {
                if (data[row2 * cols + col] >= 0) {
                    if (data[row2 * cols + col] == top) {
                        *sum += top;
                        data[row * cols + col] = -1;
                        data[row2 * cols + col] = -1;
                        find += 1;
                    }
                    break;
                }
            }
        }
    }
    return find;
}

int find_horizontal(int cols, int rows, int* data, int* sum) {
    int find = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int left = data[row * cols + col];
            // 取得第col個元素，並往下找相同的值（如果中間有阻礙，則停止）
            for (int col2 = col + 1; col2 < cols; col2++) {
                if (data[row * cols + col2] >= 0) {
                    if (data[row * cols + col2] == left) {
                        *sum += left;
                        data[row * cols + col2] = -1;
                        data[row * cols + col] = -1;
                        find += 1;
                    }
                    break;
                }
            }
        }
    }
    return find;
}

int main(int argc, char** argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    int* data = malloc(n * m * sizeof(int));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            scanf("%d", &data[row * m + col]);
        }
    }

    int small_sum;
    int sum = 0;
    while (find_horizontal(m, n, data, &sum) || find_vertical(m, n, data, &sum)) {
    }

    printf("%d\n", sum);
    return 0;
}
